//#include<bits/cpp.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;

int randomNUMBER();
void function(int input);

int functionvar=randomNUMBER();

int main()
{
    extern int functionvar;
    function(0);
    int var1=1;
    var1+=1;
    const int var2=var1;
    printf("\n11\n%d\n",functionvar);
    return 0;
}
void function(int input)
{
    extern int functionvar;
    printf("The variable given to the function is %d.\nWhile the external var is %d", input, functionvar);
}
int randomNUMBER()
{
    srand(time(NULL));
    return rand();
}
