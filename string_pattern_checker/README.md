
# Pattern Finder in String

This program finds all occurrences of a given pattern (word) in a text string, converts each whole‑word match to uppercase, and counts how many such matches were found. It demonstrates string searching, word boundary detection, and in‑place string modification using pointers.

----

## Features

1.  **Whole‑Word Matching**: Only matches the pattern if it forms a complete word (surrounded by non‑alphabetic characters or string boundaries).
    
2.  **In‑Place Uppercase Conversion**: Each matched word is converted to uppercase directly in the original string.
    
3.  **Counting Occurrences**: Returns the total number of whole‑word matches.
    
4.  **Safe Input Handling**: Uses `fgets` and `strcspn` to handle newline characters properly.
    
5.  **Overlap‑Aware Search**: Correctly advances the search pointer to find overlapping matches when a potential match is not a whole word.
    

----------

## Key Concepts

-   **`stristr`** – a custom case‑insensitive version of `strstr` that ignores letter case when comparing characters.
    
-   **`isalpha`** – checks if a character is an alphabetic letter (used to determine word boundaries).
    
-   **`toupper`** – converts a character to uppercase.
    
-   **Pointer Arithmetic** – moving a pointer through the string to locate and modify characters.
    
-   **Word Boundary Detection**: A match is considered a whole word if the character before it (if any) is **not** alphabetic **or** we are at the start of the string, **and** the character after the match is **not** alphabetic **or** we are at the end of the string.
    

----------

## 🛠 Code

### Main
```c
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
```
### Pattern Finder Function
```c
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
```

### This function is a custom case-insensitive version of strstr
```c
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
```
----------

##  Execution Trace Table

The following table traces the execution for the input:  
`sentence = "hello world Hello"` and `pattern = "hello"`

| Step | `pos` (after `strstr`) | `wordStart` | `wordEnd` | Action | `count` | Modified Sentence |
|---:|---|---|---|---|---:|---|
| 0 | — | — | — | Initial | 0 | `"hello world Hello"` |
| 1 | points to first `'h'` | 1 (start) | 0 (space) | Convert | 1 | `"HELLO world Hello"` |
| 2 | after advancing by 5 | — | — | Search | 1 | `"HELLO world Hello"` |
| 3 | points to `'H'` in `Hello` | 0 (previous char is space, not alphabetic) | 1 (end) | Convert | 2 | `"HELLO world HELLO"` |
| 4 | after advancing by 5 | — | — | Loop ends | 2 | `"HELLO world HELLO"` |

----------

## 🖼 Memory Diagram (ASCII style)

### Initial state

```text
sentence:  h e l l o   w o r l d   H e l l o \0
 ↑
 pos (after strstr points to first 'h')
```
### After first match converted

```text
sentence:  H E L L O   w o r l d   H e l l o \0
 ↑
 pos moved to after the word
```
### After second match converted

```text
sentence:  H E L L O   w o r l d   H E L L O \0
 ↑
 pos at end, loop exits
 ```

----------

## Program Output

```text
Enter a sentence: hello world Hello
Enter a word to search for: hello
New sentence: HELLO world HELLO
Number of occurrences of the word 'hello': 2
```
---
### Other Sample Output:
- ![sample output 1](https://github.com/zoreladreanjava/C-language-codes/blob/main/string_pattern_checker/sampleOutput1.PNG)
- ![sample output 2](https://github.com/zoreladreanjava/C-language-codes/blob/main/string_pattern_checker/sampleOutput2.PNG)