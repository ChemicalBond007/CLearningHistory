#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,a[n+1],b[m+1],num=0,lst=0;//all the n,m are not starting from 0.
    for(i=0;i<=m;i++)
        b[i]=0;
    for(i=1;i<=n;i++)//a[0] here is blank
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)//b[0] here is blank
        b[a[i]]+=1;
        //input section end
    for(i=1;i<=m;i++)
    {
        num=i;
        for(j=1;j<m;j++)
        {
            if(j+num>m)
                num-=m;
            if(b[num+j])
                break;
        }
        if(lst<j-1)
            lst=j-1;
    }
    printf("%d\n",m-lst-1);
    return 0;
}