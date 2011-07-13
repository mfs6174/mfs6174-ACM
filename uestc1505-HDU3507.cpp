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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct DIAN
{
  long long x,y;
};
long long i,j,k,t,n,m,ding,dang;
long long s[501000],f[501000];
DIAN zhan[501000];


inline double cha(DIAN a,DIAN b,DIAN c)
{
  double x1,x2,y1,y2;
  x1=b.x-a.x;
  y1=b.y-a.y;
  x2=c.x-b.x;
  y2=c.y-b.y;
  return x1*y2-x2*y1;
}

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

inline long long fang(long long x)
{
  return x*x;
}


int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%lld%lld",&n,&m)!=EOF)
  {
    for (i=1;i<=n;i++)
    {
      s[i]=get();
      s[i]+=s[i-1];
    }
    ding=1;
    dang=1;
    f[1]=fang(s[1])+m;
    zhan[1].x=s[1];
    zhan[1].y=f[1]+fang(s[1]);
    for (i=2;i<=n;i++)
    {
      long long k=2*s[i];
      if (ding-dang!=0)
      {
        double kk=(double)(zhan[dang+1].y-zhan[dang].y)/(zhan[dang+1].x-zhan[dang].x);
        while (k>kk)
        {
          dang++;
          if (ding-dang==0)
            break;
          kk=(double)(zhan[dang+1].y-zhan[dang].y)/(zhan[dang+1].x-zhan[dang].x);
        }
      }
      f[i]=zhan[dang].y-k*zhan[dang].x+fang(s[i])+m;
      t=ding+1;
      zhan[t].x=s[i];
      zhan[t].y=f[i]+fang(s[i]);
      if (ding-dang>0)
        while (cha(zhan[ding-1],zhan[ding],zhan[t])<=0)
        {
          ding--;
          if (ding-dang==0)
            break;
        }
      ding++;
      zhan[ding]=zhan[t];
    }
    cout<<f[n]<<endl;
  }
  return 0;
}

          
        
