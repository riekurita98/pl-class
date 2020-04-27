#include "linkedlist.h"
#include <stdlib.h>

int main() {
  LinkedList *list = NULL;
  for (int i=0; i<5; i++) {
    list = insertFrontLL(list, i);
  }

  displayLL(list);
  cleanupLL(list);
  list = NULL;

}