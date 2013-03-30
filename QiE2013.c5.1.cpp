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

llg i,j,k,t,n,m,k1,k2,kk,ss,w;
int zu,zz;
double bi;

inline bool getbig(llg a,llg m,llg kk)
{
  if (m<0)
    m=-m;
  if (a<0)
    a=-a;
  // double aa=a,mm=m;
  if (sqrt(a)*sqrt(m)>bi)
    return true;
  else
  {
    if (a*m>kk)
      return true;
    else
      return false;
  }
}
int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  bi=1e9+1e8;
  for (zz=1;zz<=zu;zz++)
  {
    sf("%I64d%I64d%I64d%I64d",&n,&k1,&k2,&kk);
    ss=0;
    for (i=1;i<=n;i++)
    {
      sf("%I64d",&t);
      ss+=t;
    }
    w=k1+k2;
    if (ss>kk)
    {
      pf("Case #%d: 0\n",zz);
      continue;
    }
    if (w==0)
    {
      pf("Case #%d: inf\n",zz);
      continue;
    }
    if (w==1)
    {
      if (ss>kk)
        pf("Case #%d: 0\n",zz);
      else
        pf("Case #%d: inf\n",zz);
      continue;
    }
    if (w==-1)
    {
      if (ss>kk)
        pf("Case #%d: 0\n",zz);
      else
        pf("Case #%d: inf\n",zz);
      continue;
    }
    k=0;
    while (1)
    {
      // if (ss>kk)
      // {
      //   pf("Case #%d: %I64d\n",zz,k);
      //   continue;
      // }
      if (getbig(ss,w,kk))
      {
        if ( ((w>0)&&(ss>0)) || ( (w<0)&&(ss<0) ) )
          t=k+1;
        else
          t=k+2;
        pf("Case #%d: %I64d\n",zz,t);
        break;
      }
      else
        ss*=w;
      k++;
    }
  }
  return 0;
}


