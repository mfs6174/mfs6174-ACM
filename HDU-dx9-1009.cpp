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

using namespace std;

#define LL long long
const int MAXN=11000;

struct D
{
  LL d,p;
  bool operator <(const D &x) const
  {
    return d<x.d;
  }
};

struct S
{
  LL x,y,e;
  bool operator <(const S &t) const
  {
    return e<t.e;
  }
};
S ji[51000];
LL ff[MAXN],n,m,i,j,t,tt,k,q,l,mm;
LL fm[MAXN];
LL qr[110000];
D du[110000];
LL dui[110000];
LL cc;


void init(LL n)
{
  int i;
  for (i=1;i<=n;i++)
  {
    ff[i]=i;
    fm[i]=1;
  }
  cc=0;
}

int cha(LL x)
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(LL x,LL y,LL z)
{
  LL i,j;
  i=cha(x);j=cha(y);
  if (i!=j)
  {
    mm=mm-(fm[i]-1)*fm[i]/2-(fm[j]-1)*fm[j]/2+(fm[i]+fm[j]-1)*(fm[i]+fm[j])/2;
    ff[i]=j;//总根为标志，把总根挂到另一个的总根下
    fm[j]+=fm[i];
  }
}
int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%lld%lld%lld",&n,&m,&q)!=EOF)
  {
    init(n);
    for (i=1;i<=m;i++)
      scanf("%lld%lld%lld",&ji[i].x,&ji[i].y,&ji[i].e);
    for (i=1;i<=q;i++)
    {
      scanf("%lld",&(du[i].d));
      du[i].p=i;
    }
    sort(&du[1],&du[q+1]);
    sort(&ji[1],&ji[m+1]);
    mm=0;
    for (i=1,j=0;i<=q;i++)
    {
        while (j<=m&&ji[j].e<=du[i].d)
        {
          bing(ji[j].x,ji[j].y,ji[j].e);
          j++;
        }
      qr[du[i].p]=mm;
    }
    for (i=1;i<=q;i++)
      cout<<qr[i]<<endl;
  }
  return 0;
}

		
