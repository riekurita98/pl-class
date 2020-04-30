#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char word[4];
  word[0] = 'c';
  word[1] = 'a';
  word[2] = 't';    
  word[3] = '\0';
  printf("%s\n", word);

  char word2[4];
  strcpy(word2, "dog");
  printf("%s\n", word2);

  word2[0] = 'h';
  printf("%s\n", word2);

  char *wptr = "dog";
  printf("%s\n", wptr);
  // wprt[0] = 'h';

  char *word3 = malloc(4 * sizeof(char));
  strcpy(word3, "pet");
  printf("%s\n", word3);
  free(word3);

}

// strings are just arrays of chars
// strings must be null terminated
// use built in string functions(strcpy, strcar -- how null terminator handles are treated)