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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long maxlongint=2147483647;

#define MAXN 510000
long long f[MAXN];
long long n;

//f[x]总是表示x-lowbit+1 到 x的和
inline long long lowbit(long long x)
{
  return x&(x^(x-1));
}

void upc(long long x,long long d)
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

long long downs(long long x)
{
  long long s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

struct D
{
  long long d,p;
  bool operator <(const D &x) const
  {
    return d>x.d;
  }
};
D shu[MAXN];
long long i,j,k,t,mm;
long long wei[MAXN];

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%lld",&n)!=EOF&&n)
  {
    for (i=1;i<=n;i++)
    {
      shu[i].d=get();
      shu[i].p=i;
    }
    sort(&shu[1],&shu[n+1]);
    for (i=1;i<=n;i++)
      wei[shu[i].p]=i;
    memset(f,0,sizeof(f));
    mm=0;
    for (i=1;i<=n;i++)
    {
      mm+=downs(wei[i]);
      upc(wei[i],1);
    }
    cout<<mm<<endl;
  }
  return 0;
}
