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
#define LL long long
#define MAXN 110000
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

struct T
{
  LL x,y,l,d,lz;
};

T shu[MAXN*5];
LL i,j,k,t,n,m,zz,zu,tt;

void stinit(LL p,LL x,LL y)
{
  shu[p].x=x;shu[p].y=y;shu[p].l=y-x+1;shu[p].d=0;shu[p].lz=0;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}

inline void pd(LL x)//pushdown函数 用延迟标记影响节点，把延迟标记传到子节点（比较懒所以只传递并不递归处理）
{
  if (shu[x].lz)
  {
    if (shu[x].d!=-1)
      shu[x].d+=shu[x].lz;
    if (shu[x].x!=shu[x].y)
    {
      shu[x<<1].lz+=lz;
      shu[(x<<1)+1].lz+=shu[x].lz;
    }
  } 
  shu[x].lz=0;
}

void ins(LL p,LL x,LL y)
{
  pd(p);
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    shu[p].lz++;
    return;
  }
  if (shu[p].d>0)
    shu[p].lz=shu[p].d;
  shu[p].d=-1;
  pd(p);
  LL mid=(shu[p].y+shu[p].x)>>1;
  if (x<=mid)
    ins(p<<1,x,y);
  if (y>=mid+1)
    ins((p<<1)+1,x,y);
  pd(p);
}

LL qr(LL p,LL x,LL y)
{
  pd(p);
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    if (shu[p].d!=-1)
      return;
}
  
LL s[25][110000],aa[110000];

int main()
{
  while (scanf("%lld",&n)!=EOF)
  {
    zz++;
    memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
      scanf("%lld",&aa[i]);
    for (i=0;i<=20;i++)
    {
      for (j=1;j<=n;j++)
        s[i][j]=s[i][j-1]+aa[j];
      aa[j]=(int)(sqrt(aa[j]));
    }
    stinit(1,1,n);
    scanf("%lld",&m);
    printf("Case #%lld:\n",zz);
    for (i=1;i<=m;i++)
    {
      scanf("%lld%lld%lld",&t,&j,&k);
      if (!t)
        ins(1,j,k);
      else
      {
        tt=qr(1,j,k);
        cout<<tt<<endl;
      }
    }
    cout<<endl;
  }
  return 0;
}

    
