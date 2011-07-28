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
LL shu[MAXN],dao[MAXN],f[MAXN],wei[MAXN];
struct Q
{
  LL d,p;
};

Q q[MAXN];
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

T ss[MAXN*3];

void stinit(int p,int x,int y)
{
  ss[p].x=x;ss[p].y=y;
  ss[p].m=maxlongint;ss[p].d=-1;
  if (x==y)
    return;
  stinit(p>>1,x,(x+y)>>1);
  stinit((p>>1)+1,((x+y)>>1)+1,y);
}

void push(int x,int p,int d)
{
  if (ss[x].x==ss[x].y)
  {
    ss[x].m=min(ss[x].m,d);
    return;
  }
  if (
int main()
{
  freopen("ti.in","r",stdin);
  scanf("%lld",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(wei,0,sizeof(wei));
    scanf("%d",&n);
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
    stinit(1,1,n);
    f[0]=0;
    for (i=1;i<=n;i++)
    {
      while (dw>=dt&&q[dw].d<shu[i])
      {
        Q tt=q[dw];
        dw--;
        if (dw>=dt)
          del(q[dw].p,tt.p-1);
        else
          del(0,tt.p-1);
      }
      tt.p=i;tt.d=shu[i];
      if (dw>=dt)
        add(q[dw].p,i-1);
      else
        add(0,i-1);
      q[++dw]=tt;
      f[i]=gm(dao[i],i-1);
      push(1,i,f[i]);
    }
    cout<<f[n]<<endl;
  }
  return 0;
}

