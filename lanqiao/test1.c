#include <stdio.h>

int main(){
    char name[6][11];
    for(int i=0;i<6;i++){
        scanf("%s",&name[i]);
    }
    for(int i=0;i<6;i++){
        printf("%c",name[i][0]);
    }
    return 0;
}