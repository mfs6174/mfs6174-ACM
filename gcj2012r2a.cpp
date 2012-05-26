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
  int w,l;
  bool operator <(const D &x) const
  {
    return w<x.w;
  }
};

int i,j,k,t,n,m,zu,zz,mm;
int ff[11000];
D dian[11000];

int main()
{
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    for (i=1;i<=n;i++)
      sf("%d%d",&(dian[i].w),&(dian[i].l));
    sf("%d",&m);
    sort(&dian[1],&dian[n+1]);
    mm=0;
    memset(ff,0,sizeof(ff));
    ff[1]=dian[1].w;
    for (i=1;i<n;i++)
    {
      t=dian[i].w+ff[i];
      mm=max(mm,t);
      for (j=i+1;j<=n;j++)
      {
        if (dian[j].w>t)
          break;
        ff[j]=max(ff[j],min(dian[j].w-dian[i].w,dian[j].l));
      }
    }
    mm=max(mm,dian[n].w+ff[n]);
    if (mm>=m)
      printf("Case #%d: YES\n",zz);
    else
      printf("Case #%d: NO\n",zz);
  }
  return 0;
}


