#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

LinkedList *insertFrontLL(LinkedList *lst, int item) {
   LinkedList *cell = malloc(sizeof(LinkedList));
   cell->value = item;
   cell->next = lst;
   return cell;
}

void displayLL(LinkedList *lst) {
   LinkedList *cur = lst;
   while (cur != NULL) {
      printf("Value = %i\n", cur->value);
      cur = cur->next;
   }
}

void cleanupLL(LinkedList *lst) {
   LinkedList *cur = lst;
   while (cur != NULL) {
      LinkedList *follow = cur->next;
      free(cur);
      cur = follow;
   }
}

