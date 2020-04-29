#include <stdio.h>
#include <stdlib.h>

struct Thing {
   int a;
   struct Thing *b;
};
typedef struct Thing Thing;

int main() {
   Thing x;
   Thing *y;
   Thing *z;
   x.a = 3;
   x.b = malloc(sizeof(Thing));
   y = malloc(sizeof(Thing));
   y->b = malloc(sizeof(Thing));
  

   printf("%i\n",x.a);
   printf("%i\n",y);
   printf("%i\n",y->a);
   printf("%i\n",z);

   y->b = &x;
   z = malloc(sizeof(Thing));
   y->a = 9;
   z->b = y;
   z->a = 47;
   (y->b)->a = 7;

   printf("%i\n",x.a);
   printf("%i\n",y->a);
   printf("%i\n",(y->b)->a);
   printf("%i\n",z->a);
}