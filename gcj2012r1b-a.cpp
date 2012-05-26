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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,ss,c,mins,adiv,p0;
int shu[500],wei[500];
double rr[500];

int main()
{
  freopen("ti.in","r",stdin);
  //freopen("ti.out","w",stdout);
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    ss=0;
    for (i=1;i<=n;i++)
    {
      cin>>shu[i];
      ss+=shu[i];
      wei[i]=i;
    }
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (shu[j]<shu[i])
        {
          t=shu[i];
          shu[i]=shu[j];
          shu[j]=t;
          t=wei[i];
          wei[i]=wei[j];
          wei[j]=t;
        }
    for (i=1;i<=n;i++)
    {
      m=ss;
      c=0;
      adiv=0;
      for (j=1;j<n;j++)
      {
        if (j==i)
          continue;
        if (j+1==i)
          t=2;
        else
          t=1;
        if (j+t>n)
          continue;
        c++;
        if (m>=(shu[j+t]-shu[j])*c)
        {
          m-=(shu[j+t]-shu[j])*c;
        }
        else
        {
          p0=shu[j];
          adiv=c;
          mins=ss-m;
          break;
        }
      }
      if (!adiv)
      {
        if (i==n)
          p0=shu[n-1];
        else
          p0=shu[n];
        adiv=n-1;
        mins=ss-m;
      }
      double ddiv=adiv;
      rr[wei[i]]=(p0+(ss-mins)/ddiv-shu[i])/(ss+ss/ddiv);
      rr[wei[i]]*=100;
      // if (rr[wei[i]]<0)
      // rr[wei[i]]=0;
    }
    pf("Case #%d: ",zz);
    for (i=1;i<n;i++)
      pf("%.6lf ",rr[i]);
    pf("%.6lf\n",rr[n]);
  }
  return 0;
}

