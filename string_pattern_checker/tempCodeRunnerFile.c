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