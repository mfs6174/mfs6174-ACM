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

const int dt=210000;
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,ngt,mx,p,mm,zhi;
bool f[2][500000];
double dm,gt;
int dd[300];
int zu,zz;

inline int mabs(int x)
{
  if (x<0)
    return -x;
  else
    return x;
}

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%lf%d",&gt,&n);
    if (gt<0)
      gt=gt-0.00005;//This is important! pos+eps/10*5 neg-
    else
      gt=gt+0.00005;
    ngt=(gt)*10000;
    mx=0;
    for (i=1;i<=n;i++)
    {
      sf("%lf",&dm);
      if (dm<0)
      dm=dm-0.00005;
    else
      dm=dm+0.00005;
      dd[i]=(dm)*10000;
      if (dd[i]<0)
        mx+=dd[i];
    }
    sort(&dd[1],&dd[n+1]);
    memset(f,0,sizeof(f));
    f[0][dt]=true;
    mm=maxlongint;
    for (i=1,p=1;i<=n;i++,p=1-p)
      for (j=mx;j<20000;j++)
      {
        if (j-dd[i]>=mx&&j-dd[i]<20000)
          f[p][j+dt]=f[1-p][j+dt]||f[1-p][j-dd[i]+dt];
        else
          f[p][j+dt]=f[1-p][j+dt];
        if (f[p][j+dt])
        {
          if (mabs(j-ngt)<mm)
          {
            mm=mabs(j-ngt);
            zhi=j;
          }
          else
            if (mabs(j-ngt)==mm)
            {
              if (j<zhi)
                zhi=j;
            }
        }
      }
    pf("%.4lf\n",zhi/10000.0);
  }
  return 0;
}
    
