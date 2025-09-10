#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int n,ans[500005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j0=0,o0=0,j1=0,o1=0,j2=0,o2=0;
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(j%2==0&&s[j]=='0')
			{
				o0++;
			}
			if(j%2==1&&s[j]=='0')
			{
				j0++;
			}
			if(j%2==0&&s[j]=='1')
			{
				o1++;
			}
			if(j%2==1&&s[j]=='1')
			{
				j1++;
			}
			if(j%2==0&&s[j]=='2')
			{
				o2++;
			}
			if(j%2==1&&s[j]=='2')
			{
				j2++;
			}
		}
		if(o0>j0)
		{
			if(o0-j0<=j2)
			{
				j2-=(o0-j0);
			    o0=j0;
			}
			else
			{
				o0-=j2;
				j2=0;
			}
		}
		else
		{
			if(j0-o0<=o2)
			{
				o2-=(j0-o0);
			    o0=j0;
			}
			else
			{
				j0-=o2;
				o2=0;
			}
		}
		if(o1>j1)
		{
			if(o1-j1<=j2)
			{
				j2-=(o1-j1);
			    o1=j1;
			}
			else
			{
				o1-=j2;
				j2=0;
			}
		}
		else
		{
			if(j1-o1<=o2)
			{
				o2-=(j1-o1);
			    o1=j1;
			}
			else
			{
				j1-=o2;
				o2=0;
			}
		}
		if((j2+o2)==0)
		{
			ans[i]=abs(o0-j0)+abs(o1-j1);
		}
		else
		{
			if((j2+o2)%2==1)ans[i]=1;
			else ans[i]=0;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
}
