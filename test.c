#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<n)
        printf("%d",n);
    else{
        m-=n;
        n-=1;
        int odds=(m/n)%2,num=m%n;
        if(odds){
            int;
        }
    }
    return 0;
}