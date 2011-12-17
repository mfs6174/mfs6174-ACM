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
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const double Pi=3.14159265358979323846;
const double ling=1e-7;
int i,j,k,t,n,m,zu,zz;
double shu[200],a,b,ma,mb,zuo,you,mid,s,rr,la;
bool fl,zd;

inline double fang(double x)
{
  return x*x;
}

inline double rad(double a,double b,double c)
{
  return acos((fang(a)+fang(b)-fang(c))/(2*a*b));
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d",&n);
    printf("Case %d: ",zz);
    fl=false;zd=false;
    for (i=1;i<=n;i++)
      scanf("%lf",&shu[i]);
    mb=maxlongint;ma=-1;
    for (i=1;i<n;i++)
    {
      a=abs(shu[i+1]-shu[i]);
      b=shu[i+1]+shu[i];
      ma=max(ma,a);
      mb=min(mb,b);
      if (ma>mb)
      {
        fl=true;
        break;
      }
    }
    a=abs(shu[1]-shu[n]);
    b=shu[1]+shu[n];
    ma=max(ma,a);
    mb=min(mb,b);
    if (ma>mb)
      fl=true;
    if (fl)
    {
      cout<<"impossible"<<endl;
      continue;
    }
    zuo=ma;you=mb;la=maxlongint;
    while (abs(you-zuo)>ling)
    {
      mid=(zuo+you)/2;
      s=0;
      for (i=1;i<n;i++)
        s+=rad(shu[i+1],shu[i],mid);
      s+=rad(shu[1],shu[n],mid);
      if (abs(s-2*Pi)<ling)
      {
        rr=mid;zd=true;
        break;
      }
      if (s>2*Pi) you=mid;
      if (s<2*Pi) zuo=mid;
    }
    mid=(zuo+you)/2;
    s=0;
    for (i=1;i<n;i++)
      s+=rad(shu[i+1],shu[i],mid);
    s+=rad(shu[1],shu[n],mid);
    if (abs(s-2*Pi)<ling)
    {
      rr=mid;zd=true;
    }
    if (zd)
      printf("%.3lf\n",rr);
    else
      cout<<"impossible"<<endl;
  }
  return 0;
}

    
      
    
