#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// struct LinkedList {
//   int value;
//   struct LinkedList *next;
// };

// typedef struct LinkedList LinkedList;

LinkedList *insertFrontLL(LinkedList *lst, int item) {
  LinkedList *cell = malloc(sizeof(LinkedList));
  cell -> value = item;
  cell -> next = lst;
  return cell;
}

void displayLL(LinkedList *lst) {
  LinkedList *cur = lst;
  while (cur != NULL) {
    printf("Value = %i\n", cur -> value);
    cur = cur -> next;
  }
}


void cleanupLL(LinkedList *lst) {
  LinkedList *cur = lst;
  while (cur != NULL) {
    LinkedList *follow = cur -> next;
    free(cur);
    cur = follow;
  }
}



// video4
// int main() {
//   LinkedList *list = NULL;
//   for (int i=0; i<5; i++) {
//     list = insertFrontLL(list, i);
//   }

//   displayLL(list);
//   cleanupLL(list);
//   list = NULL;

// }



// video1
// int main() {
//   LinkedList *list = NULL;

//   list = malloc(sizeof(LinkedList));
//   list -> value = 2;

  // list -> next = malloc(sizeof(LinkedList));
  // list -> next -> value = 3;

  // list -> next -> next = NULL;


  // printf("%i\n",   list -> value);
  // printf("%i\n",   list -> next -> value);
  // free(list);

// }



// clang -g -o xx xx.c
// valgrind ./xx

// valgrind --leak-check=ful ./xx