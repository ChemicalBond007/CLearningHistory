#include <stdio.h>
#include <string.h>

int main(){
	int a,b,ans=0,tmp,det;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		for(tmp=i,det=0;tmp>0;tmp/=10)
			det=det*10+tmp%10;
		if(det==i)
			ans++;
	}
	printf("%d",ans);
	return 0;
}