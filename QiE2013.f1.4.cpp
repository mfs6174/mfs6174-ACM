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

struct B
{
  int a,b,c,d;
};
B bei[21000];
struct S
{
  int d,t,p;
  int a,b,c;
  bool operator <(const S &x) const
  {
    if (d==x.d)
      return t<x.t;
    else
      return d<x.d;
  }
};
S shi[100000];
int i,j,k,t,n,m,c,tt,now,lp;
int zu,zz;
long long rr,dr,dc,ct,ss;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    c=0;
    for (i=1;i<=n;i++)
    {
      sf("%d%d%d%d",&bei[i].a,&bei[i].b,&bei[i].c,&bei[i].d);
      t=max(bei[i].a,bei[i].b);
      c++;
      shi[c].t=1;
      shi[c].d=t;
      shi[c].a=bei[i].a;
      shi[c].b=bei[i].b;
      c++;
      shi[c].t=2;
      t=min(bei[i].c,bei[i].d);
      t=max(shi[c-1].d,t);//这里
      shi[c].d=t;
      shi[c].p=shi[c-1].d;
      shi[c-1].p=shi[c].d;
      shi[c].a=bei[i].a;
      shi[c].b=bei[i].b;  
      if (bei[i].c==bei[i].d)
      {
        shi[c].c=0;
        //之前a,b赋值在这了..但是全用的..
      }
      else
      {
        if (bei[i].c<bei[i].d)
        {
          shi[c].c=bei[i].c-bei[i].a;
        }
        else
        {
          shi[c].c=bei[i].d-bei[i].b;
        }
      }
      c++;
      shi[c].t=3;
      shi[c].d=max(bei[i].c,bei[i].d);
      shi[c].c=shi[c-1].c;
    }
    sf("%d",&m);
    for (i=1;i<=m;i++)
    {
      sf("%d",&now);
      shi[c+i].t=0;
      shi[c+i].d=now;
    }
    c+=m;
    sort(&shi[1],&shi[c+1]);
    j=0;
    ss=0;
    dr=0;
    lp=0;
    dc=0;
    ct=0;
    for (i=1;i<=c;i++)
    {
      if (shi[i].d!=j)
      {
        long long cd=shi[i].d-j;
        ss+=(cd*cd+2*cd*j)*ct;
        ss-=dr*cd;
        ss+=dc*cd;
      }
      if (shi[i].t==0)
          pf("%lld\n",ss);
      j=shi[i].d;
      if (shi[i].t==1)
      {
        if (shi[i].d<shi[i].p)//这里
        {
          ct++;
          dr+=shi[i].a+shi[i].b;
        }
        continue;
      }
      if (shi[i].t==2)
      {
        if (shi[i].d>shi[i].p)//这里 说明可能没有第一个过程,直接第2个..
        {
          ct--;
          dr-=shi[i].a+shi[i].b;
        }
        dc+=shi[i].c;
        continue;
      }
      if (shi[i].t==3)
      {
        dc-=shi[i].c;
      }
    }
  }
  return 0;
}

