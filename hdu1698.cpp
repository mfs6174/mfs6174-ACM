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
  int l,r,d,xx,yy,h;
};

D shu[300000];
int i,j,kk,t,n,m,tt,mm,c,cc,zz,zu;



void init(int x,int a,int b)
{
  int m=(a+b)>>1;
  shu[x].h=1;
  shu[x].xx=a;shu[x].yy=b;
  if (a==b)
    return;
  c++;
  shu[x].l=c;
  init(shu[x].l,a,m);
  c++;
  shu[x].r=c;
  init(shu[x].r,m+1,b);
}
  
void jia(int t,int x,int y)
{
  int m=(shu[t].xx+shu[t].yy)>>1;
  if ((x<=shu[t].xx)&&(y>=shu[t].yy))
  {
    shu[t].h=kk;
    return;
  }
  if (shu[t].xx==shu[t].yy)
    return;
  if (y<=m)
  {
    jia(shu[t].l,x,y);
    if (shu[t].h&&(y<m))
      jia(shu[t].l,y+1,m);
  }
  else if (x>m)
  {
    jia(shu[t].r,x,y);
    if (shu[t].h&&(m+1>x))
      jia(shu[t].r,m+1,x-1);
  }
  else
  {
    jia(shu[t].l,x,y);
    jia(shu[t].r,x,y);
    if (shu[t].h)
    {
      if (shu[t].xx<=x-1)
        jia(shu[t].l,shu[t].xx,x-1);
      if (shu[t].yy>=y+1)
        jia(shu[t].r,y+1,shu[t].yy);
    }
  }
    shu[t].h=0;
  if ((shu[shu[t].l].h==shu[shu[t].r].h)&&(shu[shu[t].l].h))
    shu[t].h=shu[shu[t].l].h;
}

int he(int t)
{
  if (shu[t].h)
    return shu[t].h*(shu[t].yy-shu[t].xx+1);
  return he(shu[t].l)+he(shu[t].r);
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
    init(0,1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&t,&tt,&kk);
      jia(0,t,tt);
    }
    cout<<"Case "<<zz<<": The total value of the hook is "<<he(0)<<'.'<<endl;
  }
}

    
