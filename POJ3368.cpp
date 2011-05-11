#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

//ifstream inf("data.in");
ofstream ouf("out.out");


const int maxn=100010;
int t,i,n,m,l,r,f[maxn][32],zuo[maxn],you[maxn],shu[maxn];

int max(int x,int y)
{
	return (x>y)?(x):y;
}

int min(int x,int y)
{
	return (x<y)?(x):y;
}
void rmqchuli(int x)
{
	int i,j,t,tt;
	t=(int)(log((double)(x))/log(2.0));
	for (j=1;j<=t;j++)
		for (i=x-(1<<j)+1;i>=1;i--)
		{
			tt=1<<(j-1);
			f[i][j]=max(f[i][j-1],f[i+(tt)][j-1]);
			if (shu[i+(tt)-1]==shu[i+(tt)])
				f[i][j]=max(f[i][j],min(zuo[i+(tt)-1],tt)+min(you[i+(tt)],tt));
		}
}

int cha(int x,int y)
{
	int k,t,tt;
	k=(int)(log((double)(y-x+1))/log(2.0));
	tt=1<<k;
	t=max(f[x][k],f[y-(tt)+1][k]);
	if (shu[x+(tt)-1]==shu[x+(tt)])
		t=max(t,min(zuo[x+(tt)-1],1<<k)+min(you[x+(tt)],y-x+1-(tt)));
	if (shu[y-(tt)+1]==shu[y-(tt)])
		t=max(t,min(you[y-(tt)+1],1<<k)+min(zuo[y-(tt)],y-x+1-(tt)));
		return t;
}

int main()
{
	cin>>n;
	while (n)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&m);
		t=-2147483647;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&shu[i]);
			f[i][0]=1;
			if (shu[i]!=t)
			{
				zuo[i]=1;
				t=shu[i];
			}
			else
				zuo[i]=zuo[i-1]+1;
		}
		t=-2147483647;
		for (i=n;i>=1;i--)
			if (shu[i]!=t)
			{
				you[i]=1;
				t=shu[i];
			}
			else
				you[i]=you[i+1]+1;
		rmqchuli(n);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			//cout<<cha(l,r)<<endl;
			printf("%d\n",cha(l,r));
		}
		scanf("%d",&n);
	}
}
		
		
				
			
			
			
