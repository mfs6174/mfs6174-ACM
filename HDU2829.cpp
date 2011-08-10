/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: HDU2829
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

struct DIAN
{
  llg x,y;
};

llg i,j,k,t,n,m;
llg s[1100],ss[1100],shu[1100],f[1100][1100];
DIAN zhan[1100][1100],tt;
llg ding[1100],dang[1100];

inline long long  cha(DIAN a,DIAN b,DIAN c)
{
  long long  x1,x2,y1,y2;
  x1=b.x-a.x;
  y1=b.y-a.y;
  x2=c.x-b.x;
  y2=c.y-b.y;
  return x1*y2-x2*y1;
}

int main()
{
  freopen("ti.in","r",stdin);
  sf("%lld%lld",&n,&m);
  while (n)
  {
    memset(s,0,sizeof(s));
    memset(ss,0,sizeof(ss));
    memset(shu,0,sizeof(shu));
    memset(f,-1,sizeof(f));
    memset(ding,0,sizeof(ding));
    memset(dang,0,sizeof(dang));
    for (i=1;i<=n;i++)
    {
      sf("%lld",shu[i]);
      s[i]=s[i-1]+shu[i];
      ss[i]=s[i-1]*shu[i];
    }
    f[1][1]=0;
    tt.x=s[0];
    tt.y=f[1]-ss[1]+s[0]*s[1];
    ding[1]=1;
    dang[1]=0;
    for (i=2;i<=n;i++)
      for (j=i;j<=m+1;j++)
      {
        long long k=s[i-1];
        if (ding[j-1]-dang[j-1]!=0)
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
          while ((j=cha(zhan[ding-1],zhan[ding],zhan[t]))<=0)
          {
            ding--;
            if (ding-dang==0)
              break;
          }
        ding++;
        zhan[ding]=zhan[t];
        
