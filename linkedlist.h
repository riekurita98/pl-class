struct LinkedList {
  int value;
  struct LinkedList *next;
};

typedef struct LinkedList LinkedList;

LinkedList *insertFrontLL(LinkedList *lst, int item);
void displayLL(LinkedList *lst);
void cleanupLL(LinkedList *lst);