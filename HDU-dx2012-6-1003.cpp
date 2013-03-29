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

int i,j,k,t,n,m,zu,zz,p;
int wei[60][1100],zhi[60][1100];
int f[60][1100];

inline int mabs(int x)
{
  if (x<0)
    return -x;
  else
    return x;
}

struct D1
{
  int f,x;
  bool operator <(const D1 &p) const
  {
    if (p.f!=f)
      return f>p.f;
    return x>p.x;
  }
};

struct D2
{
  int f,x;
  bool operator <(const D2 &p) const
  {
    if (p.f!=f)
      return f>p.f;
    return x<p.x;
  }
};

struct T
{
  int d,h;
  bool operator <(const T &x) const
  {
    return d<x.d;
  }
};

T shu[1100];

D1 t1;
D2 t2;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d%d",&m,&n,&p);
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        sf("%d",&wei[i][j]);
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        sf("%d",&zhi[i][j]);
    priority_queue<D1> qx[55];
    priority_queue<D2> qd[55];
    for (i=1;i<=m;i++)
    {
      while (!qx[i].empty()) qx[i].pop();
      while (!qd[i].empty()) qd[i].pop();
    }
    for (i=1;i<=n;i++)
    {
      f[1][i]=mabs(p-wei[1][i])+zhi[1][i];
      t1.f=f[1][i]-wei[1][i];
      t2.x=t1.x=wei[1][i];
      qx[1].push(t1);
      t2.f=f[1][i]+wei[1][i];
      qd[1].push(t2);
    }
    for (i=2;i<=m;i++)
    {
      for (j=1;j<=n;j++)
      {
        shu[j].h=j;
        shu[j].d=wei[i][j];
      }
      sort(&shu[1],&shu[n+1]);
      for (int o=n;o>=1;o--)
      {
        j=shu[o].h;
        while ( (!qx[i-1].empty()) && qx[i-1].top().x>wei[i][j])
          qx[i-1].pop();
        if (!qx[i-1].empty())
          f[i][j]=qx[i-1].top().f+wei[i][j];
        else
          f[i][j]=maxlongint;
      }
      for (int o=1;o<=n;o++)
      {
        j=shu[o].h;
        while ( (!qd[i-1].empty()) && qd[i-1].top().x<wei[i][j])
          qd[i-1].pop();
        if (!qd[i-1].empty())
          f[i][j]=min(f[i][j],qd[i-1].top().f-wei[i][j])+zhi[i][j];
        else
          f[i][j]+=zhi[i][j];
        t1.f=f[i][j]-wei[i][j];
        t2.x=t1.x=wei[i][j];
        qx[i].push(t1);
        t2.f=f[i][j]+wei[i][j];
        qd[i].push(t2);
      }
      // f[i][j]=maxlongint;
      // for (k=1;k<=n;k++)
      //   f[i][j]=min(f[i][j],f[i-1][k]+mabs(wei[i-1][k]-wei[i][j]));
      // f[i][j]+=zhi[i][j];
    }
    int mm=maxlongint;
    for (i=1;i<=n;i++)
      mm=min(mm,f[m][i]);
    cout<<mm<<endl;
  }
  return 0;
}

 
