#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
// You might need other includes for printing or whatnot


/* Take an already existing Vector as a parameter. Do not create a Vector
 inside this function. Set its internal memory size to match the value given in
 the parameter, allocate an appropriately-sized C array to hold the actual data,
 and initialize the size variable to 0. */

void init(Vector *vector, int memorySize)
{
  vector -> memorySize = memorySize;
  vector -> size = 0;
  // vector -> array = malloc(sizeof(memorySize));
  // for (int i = 0; i)
  vector -> array = malloc(sizeof(void *) * (memorySize));
  for (int i = 0; i < memorySize; i++){
    (vector -> array)[i] = '\0';
  }
}


/* Removes the array associated with the Vector. */

void cleanup(Vector *vector){
  free(vector -> array);
}

/* Print out the Vector for debugging purposes. */

void print(Vector *vector){
  
  printf("This is the vector size: %i \n", vector -> size);
  printf("This is the vector memorySize: %i \n", vector -> memorySize);
  for(int j = 0; j < (vector -> size); j++) {
        printf("%i \n", (vector -> array)[j]);
  }
  printf("____ \n"); 
  printf("____ \n"); 
  printf("____ \n"); 
  printf("____ \n"); 
  printf("End of Vector array \n");

}

/* Insert value at location inside the Vector. If the list has items in
 positions 0 through n-1, you are only permitted to insert new values at
 locations 0 through n. (This is identical to Java's ArrayList behavior.) If
 there is already data at the location you are inserting into, insert slides the
 rest of the data down one position to make room for the new value. Returns 1 if
 success, and 0 if the location is invalid (less than 0, or greater than the
 size). Inserting at the very end of the current data (at position equal to
 size) is fine. All inserts should increase size by 1.

 If the internal array is too small to fit a new value, a new array of twice the
 size is created with malloc. The values are copied, the Vector is appropriately
 updated, and the old array is freed.) */
int insert(Vector *vector, int location, int value){
  if(location < 0 || location > (vector -> memorySize)){
    return 0;
  }
  else{
    // if(((vector -> size) + 1) > (vector -> memorySize)){
		// 	Vector *doubled = (Vector *)malloc(sizeof(Vector));
    // 	init(doubled, ((vector -> memorySize) * 2));
		// 	doubled -> size = vector -> size;
    //   doubled -> memorySize = 2 * (vector -> memorySize);
		// 	doubled -> array = vector -> array;
		// 	*vector = *doubled;
		// }

    if(((vector -> size) + 1) > (vector -> memorySize)){
			// update the vector with doubled memorySize
			int* arraydub = malloc(sizeof(void *) * (2 * (vector -> memorySize)));
      
      for(int i = 0; i < (vector -> size); i++){
        arraydub[i] = (vector -> array)[i];
      }
      
			free(vector -> array);
      vector -> array = arraydub;
			vector -> memorySize = (vector -> memorySize) * 2;
		}

    if((vector -> array)[location] != '\0'){
      for(int j = (vector -> size); j >= location; j--) {
				//printf("when J is %i array[j+1] is: %i \n", j, (vector -> array)[j + 1]);
        (vector -> array)[j + 1] = (vector -> array)[j];
      }
      (vector -> array)[location] = value;
      (vector -> size) += 1;
      return 1;
    } else {
      (vector -> array)[location] = value;
      (vector -> size) += 1;
      return 1;
    }
  }
  return 0;
}


/* Obtains value at location inside the Vector. Returns 1 if success, and 0 if
 the location is invalid (less than 0, or greater than or equal to the
 size). The value itself is returned through the parameter value. */
int get(Vector *vector, int location, int *value) {
  if(location < 0 || location >= (vector -> size)){
    return 0;
  } else {
    *value = (vector -> array)[location];
    return 1;
  }
}



/* Deletes value at location inside the Vector.  Returns 1 if success, and 0 if
 the location is invalid (less than 0, or greater than or equal to the
 size). When an item is deleted, everything else past it in the array should be
 slid down. The internal array itself does not need to be compressed, i.e., you
 don't need to halve it in size if it becomes half full, or anything like
 that. */

int delete(Vector *vector, int location){
  if(location < 0 || location >= (vector -> size)){
    return 0;
  } else{
    if((vector -> array)[location] != '\0'){
      for(int j = location; j < (vector -> size); j++) {
        (vector -> array)[j] = (vector -> array)[j + 1];
      }
      (vector -> size) -= 1;
      return 1;
    } else if ((vector -> array)[location] == '\0'){
      return 0;
    } else if ((vector -> array)[location + 1] == '\0'){
      (vector -> array)[location] = '\0';
      (vector -> size) -= 1;
      return 1;
    }
  }
  return 0;
}



