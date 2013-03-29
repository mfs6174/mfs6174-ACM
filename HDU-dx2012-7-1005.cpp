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
const int maxlongint=2147483647;

int i,j,k,t,n,m,zu,zz,p,b,th;
int f[110][11000];
int s[110][11000];
int rmq[2][11000][32];

inline void rmqinit(int x)
{
  for (int i=1;i<=x;i++)
    for (int j=1;j<=18;j++)
      rmq[0][i][j]=rmq[1][i][j]=-maxlongint;
}

inline void rmqchuli(int x,int h)//预处理，x为数字个数
{
  int i,j,t=(int)(log((double)x)/log(2.0));
	for (j=1;j<=t;j++)
      for (i=x-(1<<j)+1;i>=1;i--)
        rmq[h][i][j]=max(rmq[h][i][j-1],rmq[h][i+(1<<(j-1))][j-1]);
}

inline int cha(int x,int y,int h)//查询过程，x到y闭区间
{
	int k;
	k=(int)(log((double)(y-x+1))/log(2.0));
	return max(rmq[h][x][k],rmq[h][y-(1<<k)+1][k]);
}


int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d%d%d",&n,&m,&b,&th)!=EOF)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        sf("%d",&s[i][j]);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        s[i][j]+=s[i][j-1];
    for (i=1;i<=m;i++)
      s[n+1][i]=0;
    rmqinit(m);
    for (i=1;i<=m;i++)
    {
      f[1][i]=-maxlongint;
      rmq[0][i][0]=-maxlongint;
      rmq[1][i][0]=-maxlongint;
    }
    f[1][b]=0;
    rmq[0][b][0]=-s[1][b-1];
    rmq[1][b][0]=s[1][b];
    rmqchuli(m,0);
    rmqchuli(m,1);
    for (i=2;i<=n+1;i++)
    {
      for (j=1;j<=m;j++)
      {
        t=cha(max(1,j-th),j,0);
        if (t!=-maxlongint)
          f[i][j]=t+s[i-1][j];
        else
          f[i][j]=-maxlongint;
        t=cha(j,min(j+th,m),1);
        if (t!=-maxlongint)
          f[i][j]=max(f[i][j],t-s[i-1][j-1]);
      }
      rmqinit(m);
      for (j=1;j<=m;j++)
        if (f[i][j]!=-maxlongint)
        {
          rmq[0][j][0]=f[i][j]-s[i][j-1];
          rmq[1][j][0]=f[i][j]+s[i][j];
        }
        else
          rmq[0][j][0]=rmq[1][j][0]=-maxlongint;
      rmqchuli(m,0);
      rmqchuli(m,1);
    }
    int mm=-maxlongint;
    for (i=1;i<=m;i++)
      mm=max(mm,f[n+1][i]);
    cout<<mm<<endl;
  }
  return 0;
}

 
