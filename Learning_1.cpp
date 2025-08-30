#include <stdio.h>
#include <time.h>
int max(int input_1, int input_2)
{
   return input_1>input_2?input_1:input_2;
}
int main ()
{
   int a=10,b=20;
   for(int i=1;i<=100;i++)
      int v=1;
   printf("%d\nTime consumed is %d\n",max(a,b),clock()-1200);
   return 0;
}