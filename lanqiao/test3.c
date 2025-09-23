#include<stdio.h>

int main(){
    int i,a[3],lst,max,sum;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    lst=a[0];max=a[0];sum=a[0]+a[1]+a[2];
    for(i=0;i<3;i++)
        if(a[i]>max)
            max=a[i];
    if(max>=(0.5*sum))
        printf("%d",max);
    else
        printf("%d",sum-max);
    return 0;
}