/*
ID: mfs6174
PROG: hdu1698 segments tree
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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int xx,yy,h;
};

D shu[500000];
int i,j,kk,t,n,m,tt,mm,c,cc,zz,zu;

void init(int t,int x,int y)
{
  shu[t].xx=x;
  shu[t].yy=y;
  shu[t].h=1;
  if (x==y)
    return;
  init(t<<1,x,(x+y)>>1);
  init((t<<1)+1,((x+y)>>1)+1,y);
}

void jia(int t,int x,int y)
{
  int m=(shu[t].xx+shu[t].yy)>>1;
  if ((x<=shu[t].xx)&&(y>=shu[t].yy))
  {
    shu[t].h=kk;
    return;
  }
  
  if (shu[t].h==kk)
    return;
  if (shu[t].h>0)
  {
    shu[t<<1].h=shu[t].h;
    shu[(t<<1)+1].h=shu[t].h;
    shu[t].h=0;
  }
  if (y<=m)
    jia(t<<1,x,y);
  else if (x>=m+1)
    jia((t<<1)+1,x,y);
  else
  {
    jia(t<<1,x,y);
    jia((t<<1)+1,x,y);
  }
  if ((shu[t<<1].h==shu[(t<<1)+1].h)&&(shu[t<<1].h))
   shu[t].h=shu[t<<1].h;
}

int he(int t)
{
  if (shu[t].h)
    return shu[t].h*(shu[t].yy-shu[t].xx+1);
  if (shu[t].xx==shu[t].yy)
    return shu[t].h;
  return he(t<<1)+he((t<<1)+1);
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&n,&m);
    memset(shu,0,sizeof(0));
    c=0;
    init(1,1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&t,&tt,&kk);
      jia(1,t,tt);
    }
    cout<<"Case "<<zz<<": The total value of the hook is "<<he(1)<<'.'<<endl;
  }
}
