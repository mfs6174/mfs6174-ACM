/*
ID: mfs6174
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
#define LL long long

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  LL c,d;
  D (LL _c=0,LL _d=0){c=_c;d=_d;}
  bool operator <(const D &x) const
  {
    return c>x.c;
  }
};
  
vector<D> shu[100100];
LL i,j,k,t,n,m,zz,zu,q,tt,mm;
LL cc[100100],rr[510000];

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
  zu=get();
  for (zz=1;zz<=zu;zz++)
  {
    n=get();m=get();q=get();
    memset(cc,0,sizeof(cc));
    memset(rr,0,sizeof(rr));
    for (i=1;i<=n;i++)
      shu[i].clear();
    for (i=1;i<=m;i++)
    {
      t=get();tt=get();k=get();
      shu[t].push_back(D(tt,k));
      cc[t]++;
    }
    mm=0;
    for (i=1;i<=n;i++)
    {
      sort(shu[i].begin(),shu[i].end());
      for (j=0;j<cc[i];j++)
        rr[j+1]+=shu[i][j].d;
      mm=max(mm,cc[i]);
    }
    for (i=2;i<=mm;i++)
      rr[i]+=rr[i-1];
    printf("Case #%I64d:\n",zz);
    for (i=1;i<=q;i++)
    {
      tt=get();
      if (tt>mm) tt=mm;
      printf("%I64d\n",rr[tt]);
    }
  }
  return 0;
}

    
  
