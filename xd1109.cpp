/*
ID: mfs6174
PROG: xd1109
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
  int x,y,l,p,n;
};

D shu[100000];
int i,j,k,t,n,m,zz,zu,cc,a,b,h,ss,s;

bool pan(int x)
{
  if (shu[x].x<shu[x].y)
    return true;
  else
    return false;
}

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cc=1;
    inf>>n>>m;
    memset(shu,0,sizeof(shu));
    shu[1].x=1;
    shu[1].y=n;
    shu[1].l=n;
    h=1;
    for (i=1;i<=m;i++)
    {
      inf>>a>>b;
      j=h;
      ss=0;
      while (ss<a)
      {
        ss+=shu[j].l;
        j=shu[j].n;
      }
      s=ss-shu[j].l+1;
      if (a>s)
      {
        t=shu[j].y;
        if (pan(j))
          shu[j].y=shu[j].x+a-s-1;
        else
          shu[j].y=shu[j].x-(a-s-1);
        shu[j].l=shu[j].y-shu[j].x+1;
        cc++;
        tn=shu[j].n;
        shu[j].n=cc;
        tw=min(b,ss);
        shu[cc].x=;
        shu[cc].y=shu[j].y+(pan(j)?1:-1;
        shu[cc].l=shu[cc].y-shu[cc].x+1;
      
