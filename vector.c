#include "vector.h"
#include <stdio.h>
// #include <string.h>
#include <stdlib.h>
// You might need other includes for printing or whatnot


void init(Vector *vector, int memorySize)
{
  vector -> memorySize = memorySize;
  vector -> size = 0;
  vector -> array = malloc(sizeof(void *) * memorySize);
}


// Now do this again for all of the other functions in vector.h
void cleanup(Vector *vector)
{
  if (vector) {
    free(vector -> array);
    vector -> array = NULL;
    vector -> size = 0;
  }
}

void print(Vector *vector)
{ 
  int size = vector -> size;
	for (int i = 0; i < size; i++) {
		printf("%i, ", (vector -> array)[i]);
	}
}

/* If the internal array is too small to fit a new value, a new array of twice the size is created with malloc. The values are copied, the Vector is appropriately updated, and the old array is freed.) */
int insert(Vector *vector, int location, int value)
{
  int status;
  int memorySize = vector -> memorySize;
  if ((location < 0) || (location > memorySize)){
    status = 0;
  }
  else {
    if ((vector -> array)[location]) {
      int curr = (vector -> array)[location];
      (vector -> array)[location] = value;
      for (int i = location; i < (vector->size); i++) {
        int next = (vector -> array)[i + 1];
        (vector -> array)[i + 1] = curr;
        curr = next;
      }
    } else {
      (vector -> array)[location] = value;
    }
  
  //   if (location <= size) {
  //     Vector *twice = malloc(sizeof(size * 2));
  //     twice -> data = data;
  //     free(vector -> data);
  //     insert(twice, location, value);
  //   } else {
  //     for (int i = 0; i < size + 1; )
  //     return 1;
  //   }
    (vector -> size) ++;
    status = 1;
   }
  return status;
}

int get(Vector *vector, int location, int *value){
  int status;
  if ((location < 0) || (location >= vector->size)){
    status = 0;
  } else {
    *value = (vector->array)[location];
    return 1;
  }
  return status;
}

int delete(Vector *vector, int location){
  int status;
  if ((location < 0) || (location >= vector->size)){
    status = 0;
  } else {
    if ((vector -> array)[location]) {
      for (int i = location; i < ((vector->size) - 1); i++) {
        (vector -> array)[i] = (vector -> array)[i + 1];
      }
    }
    (vector -> size) --;
    status = 1;
  }
  return status;
}
