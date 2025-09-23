#include<stdio.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int main(){
    int x=1,y=2;
    printf("%d %d\n",x,y);
    swap(&x,&y);
    printf("%d %d\n",x,y);
    return 0;
}