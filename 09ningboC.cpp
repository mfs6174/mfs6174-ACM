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

struct D
{
  int t,n,h;
  bool operator <(const D &x) const 
  {
    return t<x.t;
  }
};

int i,j,k,t,n,m,kk,tt,mm;
int zhi[50][50];
bool zhan[50][50];
D ren[100];
int rr[100][2];

bool  ck(int x,int y,int l)
{
  bool f=true;
  int j=y+l-1;
  if (j>m)
    return false;
  for (int i=y;i<=j;i++)
  {
    if (zhan[x][i])
    {
      f=false;
      break;
    }
  }
  return f;
}

void mk(int x,int y,int l)
{
  for (int i=y;i<=y+l-1;i++)
    zhan[x][i]=true;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d%d",&n,&m,&kk)!=EOF)
  {
    if (n==0&&m==0&&kk==0)
      break;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        sf("%d",&zhi[i][j]);
    memset(zhan,0,sizeof(zhan));
    for (i=1;i<=kk;i++)
    {
      sf("%d:%d",&t,&tt);
      ren[i].h=i;
      ren[i].t=t*60+tt;
      sf("%d",&t);
      ren[i].n=t;
    }
    sort(&ren[1],&ren[kk+1]);
    for (i=1;i<=kk;i++)
    {
      mm=-maxlongint;
      for (j=1;j<=n;j++)
        for (k=1;k<=m;k++)
        {
          if (ck(j,k,ren[i].n))
          {
            if (zhi[j][k]>mm)
            {
              mm=zhi[j][k];
              rr[0][0]=j;
              rr[0][1]=k;
            }
          }
        }
      if (mm>-maxlongint)
      {
        rr[ren[i].h][0]=rr[0][0];
        rr[ren[i].h][1]=rr[0][1];
        mk(rr[0][0],rr[0][1],ren[i].n);
      }
      else
      {
        mm=-maxlongint;
        for (j=1;j<=n;j++)
          for (k=1;k<=m;k++)
          {
            if (ck(j,k,1))
            {
              if (zhi[j][k]>mm)
              {
                mm=zhi[j][k];
                rr[0][0]=j;
                rr[0][1]=k;
              }
            }
          }
        if (mm>-maxlongint)
        {
          rr[ren[i].h][0]=rr[0][0];
          rr[ren[i].h][1]=rr[0][1];
          mk(rr[0][0],rr[0][1],1);
        }
        else
          rr[ren[i].h][0]=rr[0][0]=rr[ren[i].h][1]=-1;
      }
    }
    for (i=1;i<=kk;i++)
    {
      if (rr[i][0]>-1)
        cout<<rr[i][0]<<' '<<rr[i][1]<<endl;
      else
        cout<<-1<<endl;
    }
  }
  return 0;
}
    
  
  
