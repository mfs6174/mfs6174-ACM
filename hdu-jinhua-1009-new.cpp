/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: ti
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;
int MO;
const int MOT=31011;
const int MO1=3;
const int MO2=10337;
const int MAXN=110;
const int MAXM=1010;
int a[MAXN][MAXN],sz;
inline int Mod(int x)
{
	x%=MO;
	if(x<0)x+=MO;
	return x;
}
inline int Mul(int x,int y)
{
	return x*y%MO;
}
int exgcd(int a,int b,int& x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int ret=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
inline int Div(int a,int b)
{
	int g,x,y;
	g=exgcd(b,MO,x,y);
	return Mul(a/g,x);
}
int getDeter()
{
	if(sz==0)return 1;
	for(int i=1;i<=sz;i++)
		for(int j=1;j<=sz;j++)
			a[i][j]=Mod(a[i][j]);
	bool nag=false;
	for(int i=1;i<sz;i++)
	{
		if(a[i][i]==0)
		{
			int ps=-1;
			for(int j=i;j<=sz;j++)
			{
				if(a[j][i])
				{
					ps=j;
					break;
				}
			}
			if(ps==-1)return 0;
			nag=!nag;
			for(int j=i;j<=sz;j++)swap(a[i][j],a[ps][j]);
		}
		for(int j=i+1;j<=sz;j++)
		{
			if(a[j][i])
			{
				int t=Div(a[j][i],a[i][i]);
				for(int k=i;k<=sz;k++)
				{
					a[j][k]=Mod(a[j][k]-Mul(a[i][k],t));
				}
			}
		}
	}
	int ret=1;
	for(int i=1;i<=sz;i++)ret=Mul(ret,a[i][i]);
	if(nag)ret=MO-ret;
	return ret;
}
int n,m;
struct edge
{
	int x,y,w;
};
edge e[MAXM];
inline bool cmp(const edge& e1,const edge& e2)
{
	return e1.w<e2.w;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	sort(e+1,e+m+1,cmp);
}
int set[MAXN];
int Root(int x)
{
	if(set[x]==0)return x;
	return set[x]=Root(set[x]);
}
void Union(int x,int y)
{
	int r1=Root(x),r2=Root(y);
	if(r1==r2)return;
	set[r1]=r2;
}
bool Same(int x,int y)
{
	return Root(x)==Root(y);
}
int tp;
int nd[MAXN];
int g[MAXN][MAXN];
int work()
{
	int lst=1;
	int ans=1;
	for(int i=1;i<=n;i++)set[i]=0;
	for(int i=1;i<=m+1;i++)
	{
		if(i==m+1||i!=1&&e[i].w!=e[i-1].w)
		{
			tp=0;
			for(int j=1;j<=n;j++)
			{
				if(Root(j)==j)
				{
					tp++;
					nd[j]=tp;
				}
			}
			for(int j=1;j<=tp;j++)
				for(int k=1;k<=tp;k++)a[j][k]=g[j][k]=0;
			for(int j=lst;j<i;j++)
			{
				int t1=nd[Root(e[j].x)],t2=nd[Root(e[j].y)];
				g[t1][t2]++;
				g[t2][t1]++;
			}
			for(int j=lst;j<i;j++)Union(e[j].x,e[j].y);
			for(int j=1;j<=n;j++)
			{
				if(Root(j)==j&&!Same(j,1))
				{
					g[nd[Root(1)]][nd[j]]++;
					g[nd[j]][nd[Root(1)]]++;
				}
			}
			int res=1;
			for(int j=1;j<=tp;j++)
				for(int k=1;k<=tp;k++)
				{
					if(j==k)continue;
					if(g[j][k])
					{
						a[j][k]=a[k][j]=-g[j][k];
						g[j][k]=g[k][j]=0;
					}
				}
			for(int j=1;j<=tp;j++)
			{
				a[j][j]=0;
				for(int k=1;k<=tp;k++)
				{
					if(j==k)continue;
					a[j][j]-=a[j][k];
				}
			}
			sz=tp-1;
			res=Mul(res,getDeter());
			ans=Mul(ans,res);
			lst=i;
		}
	}
	return ans;
}
int main()
{
	init();
	MO=MO1;
	int m1=work();
	MO=MO2;
	int m2=work();
	MO=MOT;
	int ans=Div((m1*MO2+m2*MO1)%MOT,(MO1+MO2)%MOT);
	printf("%d\n",ans);
}

