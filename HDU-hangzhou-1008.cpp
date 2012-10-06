/*
ID: mfs6174
PROG: BIT
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
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
#define MAXN 110000
int f[MAXN];
int rr[MAXN];

#define sf scanf
#define pf printf
struct D
{
  int h,d;
  bool operator < (const D &x) const
  {
    return d<x.d;
  }
};
struct P
{
  int d,a,b,h;
  bool operator <(const P &x) const
  {
    return d<x.d;
  }
};

D shu[MAXN];
P cha[MAXN];


//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}


void upc(int x,int d,int n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}


int downs(int x) //查找
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

int i,j,k,t,n,m,a,b,c,md,ss;
int zz,zu;

int  main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      sf("%d",&shu[i].d);
      shu[i].h=i;
    }
    for (i=1;i<=m;i++)
    {
      sf("%d%d%d",&cha[i].a,&cha[i].b,&cha[i].d);
      cha[i].h=i;
      cha[i].a++;
      cha[i].b++;
    }
    sort(&cha[1],&cha[m+1]);
    sort(&shu[1],&shu[n+1]);
    memset(f,0,sizeof(f));
    k=1;
    for (i=1;i<=m;i++)
    {
      for (j=k;j<=n;j++)
      {
        if (shu[j].d<=cha[i].d)
          upc(shu[j].h,1,n);
        else
        {
          k=j;
          break;
        }
      }
      if (j==n+1)k=j;
      t=downs(cha[i].b)-downs(cha[i].a-1);
      rr[cha[i].h]=t;
    }
    pf("Case %d:\n",zz);
    for (i=1;i<=m;i++)
      pf("%d\n",rr[i]);
  }
      
  return 0;
}
