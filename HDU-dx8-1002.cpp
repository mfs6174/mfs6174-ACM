/*
ID: mfs6174
PROG: HDU3911
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
#define MAXN 110000
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct T
{
  int x,y,m[2],mz[2],my[2],d,l,f;
};

T shu[MAXN*5];

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

void stinit(int p,int x,int y)
{
  shu[p].x=x;shu[p].y=y;shu[p].l=y-x+1;shu[p].f=-1;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}

inline void sw(int &x,int &y)
{
  int t;
  t=x;x=y;y=t;
}

inline void sw(T &a)
{
  sw(a.m[0],a.m[1]);
  sw(a.mz[0],a.mz[1]);
  sw(a.my[0],a.my[1]);
}  
  
void pd(int x)
{
  if (shu[x].d)
    sw(shu[x]);
  shu[x<<1].d=shu[x<<1].d^shu[x].d;
  shu[(x<<1)+1].d=shu[(x<<1)+1].d^shu[x].d;
  shu[x].d=0;
}

void ins(int p,int x,int y,int d)
{
  int mid=(shu[p].x+shu[p].y)>>1;
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    shu[p].m[d]=shu[p].l;
    shu[p].mz[d]=shu[p].my[d]=shu[p].m[d];
    return;
  }
  if (x<=mid)
    ins(p<<1,x,y,d);
  if (y>=mid+1)
    ins((p<<1)+1,x,y,d);
  if (shu[p<<1].l==shu[p<<1].m[d])
    shu[p].mz[d]=shu[(p<<1)+1].mz[d]+shu[p<<1].l;
  else
    shu[p].mz[d]=shu[p<<1].mz[d];
  if (shu[(p<<1)+1].l==shu[(p<<1)+1].m[d])
    shu[p].my[d]=shu[(p<<1)+1].l+shu[p<<1].my[d];
  else
    shu[p].my[d]=shu[(p<<1)+1].my[d];
  shu[p].m[d]=shu[p<<1].my[d]+shu[(p<<1)+1].mz[d];
  shu[p].m[d]=max(shu[p].m[d],max(shu[p].mz[d],shu[p].my[d]));
  shu[p].m[d]=max(shu[p].m[d],max(shu[p<<1].m[d],shu[(p<<1)+1].m[d]));
}
void md(int p,int x,int y)
{
  pd(x);
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    shu[p].d=shu[p].d^1;
    return;
  }
  int mid=(shu[p].x+shu[p].y)>>1;
  if (x<=mid)
    md(p<<1,x,y);
  if (y>=mid+1)
    md((p<<1)+1,x,y);
  pd(p<<1);pd((p<<1)+1);
  for (int d=0;d<=1;d++)
  {
    if (shu[p<<1].l==shu[p<<1].m[d])
      shu[p].mz[d]=shu[(p<<1)+1].mz[d]+shu[p<<1].l;
    else
      shu[p].mz[d]=shu[p<<1].mz[d];
    if (shu[(p<<1)+1].l==shu[(p<<1)+1].m[d])
      shu[p].my[d]=shu[(p<<1)+1].l+shu[p<<1].my[d];
    else
      shu[p].my[d]=shu[(p<<1)+1].my[d];
    shu[p].m[d]=shu[p<<1].my[d]+shu[(p<<1)+1].mz[d];
    shu[p].m[d]=max(shu[p].m[d],max(shu[p].mz[d],shu[p].my[d]));
    shu[p].m[d]=max(shu[p].m[d],max(shu[p<<1].m[d],shu[(p<<1)+1].m[d]));
  }
}

int qr(int p,int x,int y)
{
  pd(p);
  if (x<=shu[p].x&&y>=shu[p].y)
    return shu[p].m[1];
  int mid=(shu[p].x+shu[p].y)>>1,mt=0,st=0;
  if (x<=mid)
  {
    mt=max(mt,qr(p<<1,x,y));
    //(p<<1);
    st=min(shu[p<<1].my[1],mid-x+1);
  }
  if (y>=mid+1)
  {
    mt=max(mt,qr((p<<1)+1,x,y));
    //((p<<1)+1);
    st+=min(shu[(p<<1)+1].mz[1],y-mid);
  }
  pd(p<<1);pd((p<<1)+1);
  for (int d=0;d<=1;d++)
  {
    if (shu[p<<1].l==shu[p<<1].m[d])
      shu[p].mz[d]=shu[(p<<1)+1].mz[d]+shu[p<<1].l;
    else
      shu[p].mz[d]=shu[p<<1].mz[d];
    if (shu[(p<<1)+1].l==shu[(p<<1)+1].m[d])
      shu[p].my[d]=shu[(p<<1)+1].l+shu[p<<1].my[d];
    else
      shu[p].my[d]=shu[(p<<1)+1].my[d];
    shu[p].m[d]=shu[p<<1].my[d]+shu[(p<<1)+1].mz[d];
    shu[p].m[d]=max(shu[p].m[d],max(shu[p].mz[d],shu[p].my[d]));
    shu[p].m[d]=max(shu[p].m[d],max(shu[p<<1].m[d],shu[(p<<1)+1].m[d]));
  }
  if (x<=mid&&y>=mid+1)
    mt=max(mt,st);
  return mt;
}

int i,j,k,t,n,m,a,b,mm;
int s[MAXN];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    s[0]=0;
    memset(shu,0,sizeof(shu));
    stinit(1,1,n);
    j=1;
    s[1]=get();
    for (i=2;i<=n;i++)
    {
      s[i]=get();
      if (s[i]!=s[i-1])
      {
        ins(1,j,i-1,s[i-1]);
        j=i;
      }
    }
    ins(1,j,n,s[n]);
    m=get();
    for (i=1;i<=m;i++)
    {
      t=get();a=get();b=get();
      if (t)
        md(1,a,b);
      else
      {
        mm=qr(1,a,b);
        cout<<mm<<endl;
      }
    }
  }
  return 0;
}
