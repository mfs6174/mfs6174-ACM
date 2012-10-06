/*
ID: mfs.dev2
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
#include<cmath>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int x,n;
  bool operator <(const D &d) const
  {
    return x<d.x;
  }
};

int i,j,k,t,n,m,zz,zu;
double tt,dang,mm,nn,d;
D shu[1000100];

bool fen(double x)
{
  int i,j;
  double t;
  t=shu[1].x-x;
  for (i=1;i<=n;i++)
    for (j=1;j<=shu[i].n;j++)
    {
      if (i==1&&j==1)
        continue;
      if (shu[i].x-t>=d)
      {
        t=max(t+d,shu[i].x-x);
        continue;
      }
      if (shu[i].x+x-t<d)
          return false;
      t=t+d;
    }
  return true;
}
int main()
{
  freopen("ti.out","w",stdout);
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>d;
    for (i=1;i<=n;i++)
    {
      inf>>shu[i].x>>shu[i].n;
      nn+=shu[i].n;
    }
  
    sort(&(shu[1]),&(shu[n+1]));
    mm=(nn-1)*d;
    dang=0;
    bool ff;
    while (1)
    {
      ff=fen(mm);
      if (mm-dang<1e-4)
          break;
      if (ff)
      {
        mm=(mm+dang)/2;
      }
      else
      {
        tt=dang;
        dang=mm;
        mm=(mm*3-tt)/2;
      }
    }
    printf("Case #%d: %.1lf\n",zz,mm);
  }
}

  
    
