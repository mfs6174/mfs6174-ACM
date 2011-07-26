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
#define LL long long
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

#define MAXN 110000
LL f[MAXN];
LL n;

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline LL lowbit(LL x)
{
  return x&(x^(x-1));
}

void upc(LL x,LL d,LL n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

LL downs(LL x) //查找
{
  LL s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

struct D
{
  LL p,x,y;
  bool operator <(const D &t) const
  {
    return y<t.y;
  }
};

LL i,j,k,m,t,zz,zu;
LL xia[MAXN],wei[1010000],shu[MAXN],rr[MAXN*2];
D q[MAXN*2];

int main()
{
  freopen("ti.in","r",stdin);
  zu=get();
  for (zz=1;zz<=zu;zz++)
  {
    memset(f,0,sizeof(f));
    memset(wei,0,sizeof(wei));
    memset(xia,0,sizeof(xia));
    n=get();
    for (i=1;i<=n;i++)
    {
      shu[i]=get();
      if (!wei[shu[i]])
      {
        wei[shu[i]]=i;
        //upc(i,shu[i],n);
      }
      else
      {
        xia[i]=wei[shu[i]];
        wei[shu[i]]=i;
      }
    }
    m=get();
    for (i=1;i<=m;i++)
    {
      q[i].x=get();q[i].y=get();
      q[i].p=i;
    }
    sort(&q[1],&q[m+1]);
    j=1;
    for (i=1;i<=n;i++)
    {
      upc(i,shu[i],n);
      if (xia[i])
        upc(xia[i],-shu[i],n);
      while (q[j].y==i)
      {
        rr[q[j].p]=downs(i)-downs(q[j].x-1);
        j++;
      } 
    }
    for (i=1;i<=m;i++)
      cout<<rr[i]<<endl;
  }
  return 0;
}
