#include<stdio.h>

int main(){
    int month;
    scanf("%d",&month);
    if(month>12||month<1)
        printf("??");
    else if(month<4)
        printf("Q1");
    else if(month>9)
        printf("Q4");
    else if(month<7)
        printf("Q2");
    else
        printf("Q3");
    return 0;
}