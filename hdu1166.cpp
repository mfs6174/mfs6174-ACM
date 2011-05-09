/*
ID: mfs6174
PROG: HDU1166 sagements tree
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

struct D
{
  int l,r,d,xx,yy;
};

D shu[200000];
int i,j,k,t,n,m,tt,mm,c,zz,zu;
string st;


void jia(int x,int w,int d)
{
  int m=(shu[x].xx+shu[x].yy)/2;
  shu[x].d+=d;
  if (shu[x].xx==shu[x].yy)
    return;
  if (w<=m)
  {
    if (!shu[x].l)
    {
      c++;
      shu[c].xx=shu[x].xx;
      shu[c].yy=m;
      shu[x].l=c;
    }
    jia(shu[x].l,w,d);
  }
  else
  {
    if (!shu[x].r)
    {
      c++;
      shu[c].xx=m+1;
      shu[c].yy=shu[x].yy;
      shu[x].r=c;
    }
    jia(shu[x].r,w,d);
  }
}


void  cha(int tt,int x,int y)
{
  if ((x<=shu[tt].xx)&&(y>=shu[tt].yy))
  {
    mm+=shu[tt].d;
    return;
  }
  if (y<=(shu[tt].xx+shu[tt].yy)/2)
  {
    cha(shu[tt].l,x,y);
    return;
  }
  if (x>(shu[tt].xx+shu[tt].yy)/2)
  {
    cha(shu[tt].r,x,y);
    return;
  }
  cha(shu[tt].l,x,y);
  cha(shu[tt].r,x,y);
}

  
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    memset(shu,0,sizeof(shu));
    c=0;
    shu[0].xx=1;
    shu[0].yy=n;
    cout<<"Case "<<zz<<':'<<endl;
    for (i=1;i<=n;i++)
    {
      cin>>t;
      jia(0,i,t);
    }
    cin>>st;
    while (st!="End")
    {
      cin>>t>>tt;
      if (st=="Add")
        jia(0,t,tt);
      else if (st=="Sub")
        jia(0,t,-tt);
      else
      {
        mm=0;
        cha(0,t,tt);
        cout<<mm<<endl;
      }
      cin>>st;
    }
  }
}

