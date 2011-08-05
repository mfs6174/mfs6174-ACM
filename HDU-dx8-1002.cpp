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
#define MAXN 110000
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct T
{
  int x,y,m[2],mz[2],my[2];
};

T ss[MAXN*5];

void stinit(int p,int x,int y)
{
  ss[p].x=x;ss[p].y=y;
  ss[p].m=0;ss[p].d=ss[p].mz=ss[p].my;
  ss[p].b=ss[p].by=ss[p].bz=0;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

void ins(int p,int x,int y,int d)
{
  int mid=(shu[p].x+shu[p].y)>>1;
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    shu[p].m[d]=shu[p].y-shu[p].x+1;
    shu[p].mz[d]=shu[p].my=shu[p].m;
    return;
  }
  if (x<=m)
    ins(p<<1,x,y);
  if (y>=m+1)
    ins((p<<1)+1,x,y);
  if (x<=shu[p].x)
    shu[p].mz[d]=max(shu[p].mz[d],y-shu[p].x+1);
  if (y>=shu[p].y)
    shu[p].my[d]=max(shu[p].my[d],shu[p].y-x+1);
  //update zuo you
  shu[p].m[d]=max(shu[p].m[d],shu[p<<1].my[d]+shu[(p<<1)+1].mz[d]);
  shu[p].m[d]=max(shu[p].m[d],max(shu[p].mz[d],shu[p].my[d]));
  shu[p].m[d]=max(shu[p].m[d],max(shu[p<<1].m[d],shu[(p<<1)+1].m[d]);
}
void md(int p,int x,int y)
{
  int mid=(shu[p].x+shu[p].y)>>1;
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    return;
  }
  if (x<=m)
    md(p<<1,x,y);
  if (y>=m+1)
    md((p<<1)+1,x,y);
  shu[p].m=max(shu[p].m,shu[p<<1].my+shu[(p<<1)+1].mz);
  shu[p].m=max(shu[p].m,max(shu[p].mz,shu[p].my));
}

int qr(int p,int x,int y)
{
  int mid=(shu[p].x+shu[p].y)>>1,mt=0;
  if (x<=shu[p].x&&y>=shu[p].y)
    return shu[p].m;
  if (x<=m)
    mt=max(mt,qr(p<<1,x,y));
  if (y>=m+1)
    mt=max(mt,qr((p<<1)+1,x,y));
  return mt;
}

int i,j,k,t,n,m,a,b,mm;
int shu[MAXN];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    shu[0]=0;
    spinit(1,1,n);
    j=1;
    shu[1]=get();
    for (i=2;i<=n;i++)
    {
      shu[i]=get();
      if (shu[i]!=shu[i-1])
      {
        ins(1,j,i-1,shu[i-1]);
        j=i;
      }
    }
    ins(1,j,n,shu[n]);
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
