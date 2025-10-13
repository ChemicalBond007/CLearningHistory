#include <cstdio>
#include <cmath>
#include <cstdlib>
int fact(int in){
	int i,ans=1;
	for(i=1;i<=in;i++)
		ans*=i;
	return ans;
}
int main()
{
	double ans=0,x,add=1;
	int i;
	scanf("%lf",&x);
	for(i=0;fabs(add)>=0.0001;i++){
		add=pow(x,i)/fact(i);
		ans+=add;
	}
	printf("%.4lf",ans);
	return 0;
}