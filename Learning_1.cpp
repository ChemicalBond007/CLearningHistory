#include <stdio.h>
#include <string.h>
#include <float.h>
 
void printconst(char* input)
{
   const char *strings=strcat(input,"\n");
   printf(strings);
}
int main()
{
   char in[50];
   scanf("%s",in);
   printconst((char*)in);
   return 0;
}