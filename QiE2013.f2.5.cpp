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

int i,j,k,t,n,m,pre;
int ff[2][2200000];
struct D
{
  int s,t;
};
queue<D> Q;

int dd[110][110];
int now,st,ii,mod,mm;
D dang,yy;
map<int,bool> pan[120];

inline int getb(int x,int pos)
{
  return ((x>>(pos-1))&1);
}

inline void fang(int &x,int pos)
{
  x=x|(1<<(pos-1));
}

inline void doit(int s,int x,int ps,int h,int rs)
{
  if (ps>m)
  {
    yy.t=x;
    yy.s=((s<<m)&mod)+h;
    if (!pan[x][yy.s])
    {
      ff[ii][yy.s]=rs;
      pan[x][yy.s]=true;
      Q.push(yy);
    }
    else
      ff[ii][yy.s]=max(ff[ii][yy.s],rs);
    mm=max(mm,rs);
    return;
  }
  bool flag=(dd[x][ps]);
  int t=h;
  for (int i=-2;i<=-2;i++)
  {
    if (ps+i>0)
    {
      if (getb(h,ps+i))
      {
        flag=false;
        break;
      }
    }
  }
  if (getb(s,m+ps))
    flag=false;
  // if (getb(s,ps))
  //   flag=false;
  if (ps-1>0)
    if (getb(s,ps-1))
      flag=false;
  if (ps+1<=m)
    if (getb(s,ps+1))
      flag=false;
  if (flag)
  {
    fang(h,ps);
    doit(s,x,ps+1,h,rs+1);
  }
  h=t;
  doit(s,x,ps+1,h,rs);
}
      
      
int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d",&n,&m)!=EOF)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        sf("%d",&dd[i][j]);
    dang.s=0;
    dang.t=0;
    Q=queue<D>();
    Q.push(dang);
    pre=-1;
    ii=1;
    ff[1][0]=0;
    mod=0;
    mm=0;
    for (i=0;i<=n;i++)
      pan[i].clear();
    pan[0][0]=true;
    for (i=1;i<=m;i++)
      mod=(mod<<1)+1;
    mod=mod<<m;
    while (!Q.empty())
    {
      dang=Q.front();
      Q.pop();
      if (pre!=dang.t)
      {
        ii=1-ii;
        //memset(ff[ii],-1,sizeof(ff[ii]));
      }
      if (dang.t>=n)
        break;
      pre=dang.t;
      st=dang.t+1;
      doit(dang.s,st,1,0,ff[1-ii][dang.s]);
    }
    // for (i=0;i<=2100000;i++)
    //   mm=max(mm,max(ff[ii][i],ff[1-ii][i]));
    cout<<mm<<endl;
  }
  return 0;
}
