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
  int l,r,xx,yy,h;
};

D shu[500000];
int i,j,kk,t,n,m,tt,mm,c,cc,zz,zu;

void jia(int t,int x,int y)
{
  int m=(shu[t].xx+shu[t].yy)>>1;
  if ((x<=shu[t].xx)&&(y>=shu[t].yy))
  {
    shu[t].h=kk;
    return;
  }
  if ((shu[t].xx==shu[t].yy)&&shu[t].xx==0)
  {
    return;
  }
  if (shu[t].h==0)
  {
    if (y<=m)
      jia(shu[t].l,x,y);
    else if (x>m)
      jia(shu[t].r,x,y);
    else
    {
      jia(shu[t].l,x,y);
      jia(shu[t].r,x,y);
    }
    if ((shu[shu[t].l].h==shu[shu[t].r].h)&&(shu[shu[t].l].h))
      shu[t].h=shu[shu[t].l].h;
    return;
  }
  if (shu[t].h==kk)
    return;
  if (!shu[t].l)
  {
    c++;
    shu[t].l=c;
    shu[c].xx=shu[t].xx;
    shu[c].yy=m;
  }
  if (!shu[t].r)
  {
    c++;
    shu[c].xx=m+1;
    shu[c].yy=shu[t].yy;
    shu[t].r=c;
  }
  shu[shu[t].l].h=shu[t].h;
  shu[shu[t].r].h=shu[t].h;
  shu[t].h=0;
  if (y<=m)
    jia(shu[t].l,x,y);
  else if (x>m)
    jia(shu[t].r,x,y);
  else
    {
      jia(shu[t].l,x,y);
      jia(shu[t].r,x,y);
    }
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
    shu[0].xx=1;
    shu[0].yy=n;
    shu[0].h=1;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&t,&tt,&kk);
      jia(0,t,tt);
    }
    cout<<"Case "<<zz<<": The total value of the hook is "<<he(0)<<'.'<<endl;
  }
}

    
