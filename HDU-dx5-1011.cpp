/*
ID: mfs6174
PROG: ti
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,p;
double sd,z,ss,mm,m,se,mx,sdx,ssx;
double shu[11000],shux[11000];

inline double ff(double x)
{
  return x*x;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&p,&n)!=EOF)
  {
    if (p==1)
    {
      ss=0;
      for (i=1;i<=n;i++)
      {
        scanf("%lf",&shu[i]);
        ss+=shu[i];
      }
      m=ss/n;
      sd=0;
      for (i=1;i<=n;i++)
        sd+=ff(shu[i]-m);
      sd=sd/n;
      sd=sqrt(sd);
      for (i=1;i<n;i++)
        printf("%.2lf ",(shu[i]-m)/sd);
      printf("%.2lf\n",(shu[n]-m)/sd);
      continue;
    }
    if (p==2)
    {
      ss=0;
      scanf("%lf",&mm);
      for (i=1;i<=n;i++)
      {
        scanf("%lf",&shu[i]);
        ss+=shu[i];
      }
      m=ss/n;
      sd=0;
      for (i=1;i<=n;i++)
        sd+=ff(shu[i]-m);
      sd=sd/(n-1);
      sd=sqrt(sd);
      se=sd/sqrt(n);
      double t=(m-mm)/se;
      printf("%.2lf\n",t);
      continue;
    }
    ssx=ss=0;
    for (i=1;i<=n;i++)
    {
      scanf("%lf",&shux[i]);
      ssx+=shux[i];
    }
    for (i=1;i<=n;i++)
    {
      scanf("%lf",&shu[i]);
      ss+=shu[i];
    }
    m=ss/n;
    sd=0;
    for (i=1;i<=n;i++)
      sd+=ff(shu[i]-m);
    sd=sd/n;
    sd=sqrt(sd);
    mx=ssx/n;
    sdx=0;
    for (i=1;i<=n;i++)
      sdx+=ff(shux[i]-mx);
    sdx=sdx/n;
    sdx=sqrt(sdx);
    double r=0;
    for (i=1;i<=n;i++)
      r+=(shux[i]-mx)*(shu[i]-m);
    r=r/n/sdx/sd;
    if (p==3)
    {
      printf("%.2lf\n",r);
    }
    else
    {
      double b=r*sd/sdx,a=m-b*mx;
      printf("%.2lf %.2lf\n",a,b);
    }
  }
  return 0;
}

      
      
      
