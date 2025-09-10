#include<stdio.h>
#include<math.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int breakingvar=0,zeronum[2]={0,0},onenum[2]={0,0},twonum[2]={0,0},ans=0,status=0;
        char input[200001];
        scanf("%s",&input);
        breakingvar=0;
        for(int j=1;;j++)
        {
            switch((int)input[j-1]){
                case '0':zeronum[j%2]++;break;
                case '1':onenum[j%2]++;break;
                case '2':twonum[j%2]++;break;
                case '\0':breakingvar=1;break;
            }
            if(breakingvar)
                break;
        }
        //ans+=abs(zeronum[0]-zeronum[1])+abs(onenum[0]-onenum[1]);
        ans+=zeronum[0]>zeronum[1]?((zeronum[0]-zeronum[1]>twonum[1])?:):();
        printf("%d\n",ans>=0?ans:(twonum-zeronum[0]-zeronum[1]-onenum[0]-onenum[1]));
    }
    return 0;
}