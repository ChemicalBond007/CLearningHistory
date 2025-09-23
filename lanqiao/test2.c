#include <stdio.h>
int main(){
    char input[100001]={'\0'};
    int i=0;
    scanf("%s", input);
    while(input[i]!='\0'){
        if((int)input[i]>='a'&&(int)input[i]<='z')
            printf("L");
        else
            printf("Q");
        i++;
    }
    return 0;
}