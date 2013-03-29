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

//懒惰标记 能覆盖时即时覆盖不再向下 查询时向下累积(细分) 查询到完全覆盖处
//离散化 包括所有出现的点(覆盖和查询) 然后就不用考虑区间中了,因为涉及的都在区间端点上
struct T
{
  int x,y,d;
  bool con;
};

struct D
{
  int a,m;
  int f;
  bool operator <(const D&x) const
  {
    return a<x.a;
  }
};

T shu[520000];
D duan[110000];
int i,j,k,t,n,m,zu,zz,tt,c,l;
int rmap[300000],dmap[110000][2];
int cha[110000],shi[110000];

void stinit(int p,int x,int y)
{
  shu[p].x=x;shu[p].y=y;shu[p].d=0;shu[p].con=true;
  if (x!=y)
  {
    stinit(p<<1,x,(x+y)>>1);
    stinit((p<<1)+1,((x+y)>>1)+1,y);
  }
  else
  {
    return;
  }
}

inline void down(int p)
{
  //shu[p].d+=s;
  if (shu[p].d)
  {
    shu[p<<1].d+=shu[p].d;
    shu[(p<<1)+1].d+=shu[p].d;
    shu[p].d=0;
  }
}

void push(int p,int l,int r)
{
  if (l<=rmap[shu[p].x]&&r>=rmap[shu[p].y])
  {
    // if (shu[p].con)
    // {
    //   shu[p].d+=1;
    //   return;
    // }
    // else
    // {
    //   push(p<<1,l,r);
    //   push((p<<1)+1,l,r);
    //   return;
    // }
    shu[p].d+=1;
    return;
  }
  // if (shu[p].con)
  // {
  //   shu[p].con=false;
  //   down(p<<1,shu[p].d);
  //   down((p<<1)+1,shu[p].d);
  // }
  if (l<=rmap[ (shu[p].x+shu[p].y)>>1])
    push(p<<1,l,r);
  if (r>=rmap[ ((shu[p].x+shu[p].y)>>1)+1 ])
    push((p<<1)+1,l,r);
}

int qr(int p,int w)
{
  // if (w<rmap[shu[p].x]||w>rmap[shu[p].y])
  // return 0;
  // if (shu[p].con)
  //   return shu[p].d;
  if (shu[p].x==shu[p].y)
    return shu[p].d;
  down(p);
  if (w<=( rmap[(shu[p].x+shu[p].y)>>1]))
    return qr(p<<1,w);
  else
    return qr((p<<1)+1,w);
}

int main()
{
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&m);
    c=0;
    for (i=1;i<=n;i++)
    {
      sf("%d%d",&t,&tt);
      c++;
      duan[c].a=t;
      duan[c].m=i;
      duan[c].f=0;
      c++;
      duan[c].a=tt;
      duan[c].m=i;
      duan[c].f=1;
    }
    for (i=1;i<=m;i++)
    {
      sf("%d",&cha[i]);
      c++;
      duan[c].a=cha[i];
      duan[c].m=i;
      duan[c].f=3;
    }
    sort(&duan[1],&duan[c+1]);
    t=0;l=0;
    // rmap[1]=0;
    // l=1;
    for (i=1;i<=c;i++)
    {
      if (duan[i].a==duan[i-1].a)
      {
        if (duan[i].f!=3)
          dmap[duan[i].m][duan[i].f]=l;
        else
          shi[duan[i].m]=l;
        continue;
      }
      l++;
      if (duan[i].f!=3)
        dmap[duan[i].m][duan[i].f]=l;
      else
        shi[duan[i].m]=l;
      rmap[l]=duan[i].a;
    }
    // l++;
    // rmap[l]=maxlongint-1;
    stinit(1,1,l);
    for (i=1;i<=n;i++)
      push(1,rmap[dmap[i][0]],rmap[dmap[i][1]]);
    pf("Case #%d:\n",zz);
    for (i=1;i<=m;i++)
    {
      //sf("%d",&t);
      pf("%d\n",qr(1,cha[i]));
    }
  }
  return 0;
}

