#include <stdio.h>
 
int main ()
{
   int a = 10;
   int * ptra=&a;
   printf("The location of a is %p.\n", ptra);
   *ptra=++a;
   printf("The location of ++a is %p.\n", ptra);
   return 0;
}