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
#define sf scanf
using namespace std;
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

#define MAXN 55000
int f[11][11][MAXN];
int shu[55000];

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}


void upc(int x,int d,int n,int id1,int id2) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[id1][id2][x]+=d;
    x+=lowbit(x);
  }
}


int downs(int x,int id1,int id2) //查找
{
  int s=0;
  while (x>0)
  {
    s+=f[id1][id2][x];
    x-=lowbit(x);
  }
  return s;
}

int i,j,k,t,n,m,a,b,c,md,ss;


int  main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d",&n)!=EOF)
  {
    for (i=1;i<=n;i++)
      sf("%d",&shu[i]);
    sf("%d",&m);
    memset(f,0,sizeof(f));
    for (i=1;i<=m;i++)
    {
      sf("%d",&t);
      if (t==1)
      {
        sf("%d%d%d%d",&a,&b,&k,&c);
        md=a%k;
        upc(a,c,n,md,k);
        upc(b+1,-c,n,md,k);
      }
      else
      {
        sf("%d",&a);
        ss=shu[a];
        for (k=1;k<=10;k++)
        {
          md=a%k;
          ss+=downs(a,md,k);
        }
        printf("%d\n",ss);
      }
    }
  }   
  return 0;
}
