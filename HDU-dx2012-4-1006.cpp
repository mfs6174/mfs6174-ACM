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

int i,j,k,t,n,m;
double f[2][1200000];
double p[20];
int g[1200000];
double pp[1200000];
double d,sd;
double e,de;
int c1(int i)
{
      int count = 0;

      while (i)
      {
            ++ count;
            i = (i - 1) & i;
      }

      return count;
}

int main()
{
  freopen("1006.in","r",stdin);
  while (sf("%d",&n)>=1)
  {
    sd=0;
    for (i=1;i<=n;i++)
    {
      sf("%lf",&p[i]);
      sd+=p[i];
      f[1][1<<(i-1)]=p[i];
    }
    sd=1-sd;
    f[1][0]=sd;
    k=1;
    m=0;
    for (i=1;i<=n;i++)
      m=(m<<1)+1;
    for (i=1;i<=m;i++)
    {
      g[i]=c1(i);
      double t=0;
      for (j=1;j<=n;j++)
        if (i&(1<<(j-1)))
          t+=p[j];
      pp[i]=t+sd;
    }
    e=0;
    if (n<=1)
      e=p[1];
    for (;;)
    {
      k++;
      int kk=k%2;
      f[kk][0]=f[1-kk][0]*sd;
      for (i=1;i<=m;i++)
      {
        f[kk][i]=0;
        if (g[i]>k)
          continue;
        for (j=1;j<=n;j++)
          if (i&(1<<(j-1)))
            f[kk][i]+=f[1-kk][i^(1<<(j-1))]*p[j];
        if (i!=m)
          f[kk][i]+=f[1-kk][i]*pp[i];
      }
      de=k*f[kk][m];
      e+=de;
      if (k>n&&de<1e-6)
        break;
    }
    printf("%.5lf\n",e);
  }
  return 0;
}
      
      
        
    
    
  
