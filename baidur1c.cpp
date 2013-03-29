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
  int a,b,c,h;
  bool operator <(const D &x) const
  {
    return c>x.c;
  }
};

int i,j,k,t,n,m,tt,mm,p1,p2;
int shu[1100][2];
D ren[1100];
int nn[3],aa[3],bb[3];

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&n);
  for (i=1;i<=n;i++)
    sf("%d%d",&ren[i].a,&ren[i].b);
  for (i=1;i<=2;i++)
    sf("%d%d%d",&nn[i],&aa[i],&bb[i]);
  for (i=1;i<=n;i++)
  {
    ren[i].h=i;
    t=ren[i].a*aa[1]+ren[i].b*bb[1];
    tt=ren[i].a*aa[2]+ren[i].b*bb[2];
    shu[i][0]=t;shu[i][1]=tt;
    ren[i].c=t-tt;
  }
  sort(&ren[1],&ren[n+1]);
  mm=0;
  for (i=1;i<=n;i++)
  {
    if (nn[1]<1 || ren[i].c<0)
    {
      p1=i-1;
      break;
    }
    mm+=shu[ren[i].h][0];
    nn[1]--;
  }
  for (i=n;i>=1;i--)
  {
    if (nn[2]<1 || ren[i].c>=0)
    {
      p2=i+1;
      break;
    }
    mm+=shu[ren[i].h][1];
    nn[2]--;
  }
  if (p1<p2-1)
  {
    if (nn[1]>0)
      for (i=p1+1;i<p2;i++)
        mm+=shu[ren[i].h][0];
    else
      for (i=p1+1;i<p2;i++)
        mm+=shu[ren[i].h][1];
  }
  cout<<mm<<endl;
  return 0;
}

