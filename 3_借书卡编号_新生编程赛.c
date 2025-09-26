#include<stdio.h>

int main(){
    int N,num[6];
    scanf("%d",&N);
    num[5]=N%10;
    num[4]=N/10%10;
    num[3]=N/100%10;
    num[2]=N/1000%10;
    num[1]=N/10000%10;
    num[0]=N/100000;
    if(num[0]+num[1]+num[2]==num[3]+num[4]+num[5])
        printf("YES");
    else
        printf("NO");
    return 0;
}