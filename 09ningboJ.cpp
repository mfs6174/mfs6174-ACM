/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


struct D
{
  bool on;
  int ds,dh;
  bool iscpl,isdld;
};

struct P
{
  int tp,tm,id;
  bool operator <(const P &x) const
  {
    return tm<x.tm;
  }
};

P shi[1000];
int i,j,k,t,n,m,zu,zz,zong,fd,sc,tt,ti,sci;
D cpt[100];
int sp[100][100];

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&zong);
    sf("%d%d",&m,&fd);
    memset(cpt,0,sizeof(cpt));
    for (i=1;i<=m;i++)
    {
      sf("%d",&t);
      cpt[t].iscpl=true;
      cpt[t].dh=fd;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        sf("%d",&sp[i][j]);
    sc=0;
    for (i=1;i<=n;i++)
    {
      sf("%d",&k);
      for (j=1;j<=k;j++)
      {
        sf("%d",&t);
        sc++;
        shi[sc].tm=t;
        shi[sc].tp=0;
        shi[sc].id=i;
        sf("%d",&t);
        sc++;
        shi[sc].tm=t;
        shi[sc].tp=1;
        shi[sc].id=i;
      
      }
    }
    sf("%d",&k);
    for (i=1;i<=k;i++)
    {
      sf("%d%d",&t,&tt);
      sc++;
      shi[sc].tm=t;
      shi[sc].id=tt;
      shi[sc].tp=2;
    }
    sort(&shi[1],&shi[sc+1]);
    sci=1;
    for (ti=0;ti<=zong;ti++)
    {
      for (sci;sci<=sc;sci++)
      {
        if (shi[sci].tm>ti)
          break;
        if (shi[sci].tp==0)
        {
          cpt[shi[sci].id].on=true;
          continue;
        }
        if (shi[sci].tp==1)
        {
          cpt[shi[sci].id].on=false;
          continue;
        }
        if (shi[sci].tp==2)
        {
          cpt[shi[sci].id].isdld=true;
        }
      }
      for (i=1;i<=n;i++)
      {
        if (cpt[i].dh>=fd)
        {
          cpt[i].isdld=false;
          cpt[i].iscpl=true;
        }
      }
      for (i=1;i<=n;i++)
      {
        if (cpt[i].on&&cpt[i].isdld)
        {
          int dl=0;
          for (j=1;j<=n;j++)
            if (cpt[j].on&&cpt[j].iscpl)
              dl+=sp[i][j];
          cpt[i].dh+=dl;
        }
      }
    }
    for (i=1;i<=n;i++)
      cout<<cpt[i].dh*100/fd<<'%'<<endl;
  }
  return 0;
}              
