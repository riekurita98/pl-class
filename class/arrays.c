#include <stdio.h>
#include <stdlib.h>

int main() {

  int *vals = malloc(3 * sizeof(int));

  *vals = 20;
  *(vals + 1) = 25;
  // below does the same but it is better
  vals[0] = 20;
  vals[1] = 25;

  printf("%i\n", *vals);

  free(vals);

}