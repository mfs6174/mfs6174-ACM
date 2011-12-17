#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,ss;
int f[60][12][3100];
int g[60][12][3000];
int shu[12][60];
int yong[12]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int mm,ff[100];
int rr[100],cc;

void dfs(int x,int y,int z,int d,int s)
{
	if (z==0)
	{
		if (x>=mm)
		{
			mm=x;
			if (d>ff[x])
				ss=d;
		}
		ff[x]=max(ff[x],d);
	}
	if (g[x][d][z]!=-1&&y<=f[x][d][z])
		return;
	f[x][d][z]=y;
	g[x][d][z]=s;
	/*int i;
		for (i=0;i<=9;i++)
			if (y>=yong[i])
				dfs(x+1,y-yong[i],(z+shu[i][x])%m,i);
	*/
}

void gr(int x,int y,int z,int s)
{
	int i;
	if (x<=0)
		return;
	cc++;
	rr[cc]=y;
	for (i=9;i>=0;i--)
	{
		int t;
		t=z-shu[y][x-1];
		if (t<0)
			t+=m;
		if (f[x-1][i][t]>=s)
		{
			gr(x-1,i,t,s+yong[i]);
			break;
		}
	}
}

int main()
{
	//freopen("ti.in","r",stdin);zz=0;
	while (scanf("%d%d",&n,&m)!=EOF&&n)
	{
		zz++;
		memset(f,-1,sizeof(f));
		for (i=1;i<=9;i++)
		{
			t=i;t=t%m;
			shu[i][0]=t;
			for (j=1;j<=55;j++)
			{
				t=t*10%m;
				shu[i][j]=t;
			}
		}
		mm=0;cc=0;
		memset(ff,0,sizeof(ff));
		memset(g,-1,sizeof(g));
		for (i=0;i<=9;i++)
			if (n>=yong[i])
				dfs(1,n-yong[i],shu[i][0]%m,i,0);
		int o;
		bool fl;
		for (i=1;i<=58;i++)
		{
			fl=true;
			for (j=0;j<=9;j++)
				for (k=0;k<m;k++)
					if (g[i][j][k]!=-1)
						for (o=0;o<=9;o++)
							if (f[i][j][k]>=yong[o])
							{
								fl=false;
								dfs(i+1,f[i][j][k]-yong[o],(k+shu[o][i])%m,o,j);
							}
				if (fl)
					break;
		}
		printf("Case %d: ",zz);
		if (mm==0)
		{
			printf("%d\n",-1);
			continue;
		}
		for (i=9;i>=0;i--)
			if (f[mm][i][0]>=0)
			{
				gr(mm,i,0,yong[i]);
				break;
			}
		for (i=1;i<=cc;i++)
			printf("%d",rr[i]);
		printf("\n");
	}
	return 0;
}
