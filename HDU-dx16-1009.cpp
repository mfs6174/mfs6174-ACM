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
const long long maxlongint=2147483647;
const long long mod=100000007;
#define MAXN 110000
long long shu[MAXN],f[MAXN];
long long rr[MAXN],hd[MAXN],qx[MAXN];
long long n,i,j,k,t,m,zz,zu,ss;

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline long long lowbit(long long x)
{
  return x&(x^(x-1));
}

inline void upc(long long x,long long d,long long n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

inline long long downs(long long x) //查找
{
  long long s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

inline long long getn(long long x)
{
  long long rt=0;
  rt=x*(x-1)/2;
  return rt%mod;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%I64d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%I64d",&n);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      scanf("%I64d",&shu[i]);
    long long c=0,ss=0;
    for (i=n;i>=1;i--)
    {
      m=downs(shu[i]);
      m=c-m;
      rr[i]=getn(m);
      hd[i]=m;
      ss=(ss+rr[i])%mod;
      upc(shu[i],1,n);
      c++;
    }
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      qx[i]=downs(shu[i]);
      ss=(ss-(qx[i]*hd[i])%mod)%mod;
      upc(shu[i],1,n);
    }
    printf("Case #%I64d: %I64d\n",zz,((ss%mod+mod)%mod));
  }
  return 0;
}
