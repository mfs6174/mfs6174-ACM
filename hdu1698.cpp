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
  if ((shu[shu[t].l].h==shu[shu[t].r].h)&&(shu[shu[t].l]))
    shu[t].h=shu[shu[t].l].h;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&n,&m);
    memset(shu,0,sizeof(0));
    shu[0].xx=1;
    shu[0].yy=n;
    shu[0].h=1;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&t,&tt,&kk);
      jia(0,t,tt);
    }
    
    
