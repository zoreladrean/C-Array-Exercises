#include <stdio.h>
#include <string.h>
#include <ctype.h>

int patternFinder ( char *sentence, const char *pattern );
char *stristr ( const char *haystack, const char *needle );

int main () {

  char sentence [ 100 ];
  char pattern [ 100 ];

  printf ( "Enter a sentence: " );
  fgets ( sentence, sizeof ( sentence ), stdin );

  sentence [ strcspn ( sentence, "\n" ) ] = 0; // remove the newline character from the input

  printf ( "Enter a word to search for: " );
  scanf ( "%s", pattern );

  int count = patternFinder ( sentence, pattern );

  printf ( "\nNew sentence: %s", sentence );
  printf ( "\nNumber of occurrences of the word '%s': %d\n", pattern, count );



  return 0;

}

char *stristr ( const char *haystack, const char *needle ) { // this function performs a case-insensitive search for the needle in the haystack

  if ( !*needle )
    return ( char * ) haystack; // return the original string if the needle is empty

  for ( ; *haystack; haystack++ ) { // iterate through the haystack

    const char *h = haystack;
    const char *n = needle;

    while ( *h && *n && tolower ( *h ) == tolower ( *n ) ) { // compare characters case-insensitively
      h++;
      n++;
    }

    if ( !*n )
      return ( char * ) haystack; // return the position of the found pattern
  }

  return NULL; // return NULL if the pattern is not found
}

int patternFinder ( char *sentence, const char *pattern ) {

  int count = 0;
  char *pos = sentence;
  int patternLen = strlen ( pattern );

  if ( patternLen == 0 )
    return 0; // return 0 if the pattern is empty

  while ( ( pos = stristr ( pos, pattern )) != NULL ) { // find the next occurrence of the pattern in the sentence

    int wordStart = ( pos == sentence ) ? 1 : !isalpha ( *( pos - 1 ) ); // check if the found pattern is at the start of a word
    int wordEnd = !isalpha ( * ( pos + patternLen ) ); // check if the found pattern is at the end of a word

    if ( wordStart && wordEnd ) { // check if the found pattern is a whole word

      for ( int i = 0; i < patternLen; i++ ) // convert the found pattern to uppercase
        pos [ i ] = toupper ( pos [ i ] );
      
      count++;
      pos += patternLen; // move past the current occurrence
    }
    else
      pos += 1; // move to the next character if not a whole word
  }

  return count;
}
