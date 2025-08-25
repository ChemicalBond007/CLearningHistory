#include <stdio.h>
#include <float.h>
 
void printconst(char* input)
{
   const char *strings=input;
   printf(strings);
}
int main()
{
   char * in[50];
   scanf("%s",in);
   printconst((char*)in);
   return 0;
}