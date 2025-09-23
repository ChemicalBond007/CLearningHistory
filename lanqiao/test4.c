#include<stdio.h>
int main(){
    int a[10],i,sum=0;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++){
        if(sum+a[i]>100)
            if(100-sum>=sum+a[i]-100){
                printf("%d",sum+a[i]);
                return 0;
            }
            else{
                printf("%d",sum);
                return 0;
            }
        sum+=a[i];
    }
    printf("%d",sum);
    return 0;
}