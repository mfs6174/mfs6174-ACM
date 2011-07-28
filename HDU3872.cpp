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
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
#define MAXN 110000
#define LL long long
LL i,j,k,t,n,m,zz,zu;
LL shu[MAXN],dao[MAXN],f[MAXN],wei[MAXN*11];
struct Q
{
  LL d,p;
};

Q q[MAXN*2];
LL dt,dw;

inline LL  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    LL ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

void qinit()
{
  dt=1;dw=0;
}

struct T
{
  LL x,y,m,d;
};

T ss[MAXN*4];

void stinit(LL p,LL x,LL y)
{
  ss[p].x=x;ss[p].y=y;
  ss[p].m=maxlongint;ss[p].d=-1;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}

void push(LL x,LL p,LL d)
{
  ss[x].m=min(ss[x].m,d);
  if (ss[x].x==ss[x].y)
    return;
  LL m=(ss[x].x+ss[x].y)>>1;
  if (p<=m)
    push(x<<1,p,d);
  else
    push((x<<1)+1,p,d);
}

void add(LL p,LL x,LL y,LL d)
{
  if (x<=ss[p].x&&y>=ss[p].y)
  {
    ss[p].d=d;
    return;
  }
  LL m=(ss[p].x+ss[p].y)>>1;
  if (y>m)
    add((p<<1)+1,x,y,d);
  if (x<=m)
    add(p<<1,x,y,d);
}

void del(LL p,LL x,LL y)
{
  if (x<=ss[p].x&&y>=ss[p].y)
  {
    ss[p].d=-1;
    return;
  }
  LL m=(ss[p].x+ss[p].y)>>1;
  if (y>m)
    del((p<<1)+1,x,y);
  if (x<=m)
    del(p<<1,x,y);
}

LL gm(LL p,LL x,LL y)
{
  if (x<=ss[p].x&&y>=ss[p].y&&ss[p].d!=-1)
    return ss[p].m+ss[p].d;
  LL mm=maxlongint,m=(ss[p].x+ss[p].y)>>1;
  if (y>m)
    mm=min(mm,gm((p<<1)+1,x,y));
  if (x<=m)
    mm=min(mm,gm(p<<1,x,y));
  return mm;
}
Q tt;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%lld",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(wei,0,sizeof(wei));
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
    {
      t=get();
      if (wei[t]==0)
      {
        wei[t]=i;
        dao[i]=0;
      }
      else
      {
        dao[i]=wei[t];
        wei[t]=i;
      }
    }
    for (i=1;i<=n;i++)
      shu[i]=get();
    qinit();
    stinit(1,0,n);
    f[0]=0;
    push(1,0,0);
    for (i=1;i<=n;i++)
    {
      while (dw>=dt&&q[dw].d<shu[i])
      {
        tt=q[dw];
        dw--;
        if (dw>=dt)
          del(1,q[dw].p,tt.p-1);
        else
          del(1,0,tt.p-1);
      }
      tt.p=i;tt.d=shu[i];
      if (dw>=dt)
        add(1,q[dw].p,i-1,shu[i]);
      else
        add(1,0,i-1,shu[i]);
      q[++dw]=tt;
      f[i]=gm(1,dao[i],i-1);
      push(1,i,f[i]);
    }
    cout<<f[n]<<endl;
  }
  return 0;
}

