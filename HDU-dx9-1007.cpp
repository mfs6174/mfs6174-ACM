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
#define sf scanf
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

const int MAXN=11000;

int ff[MAXN],n,m,i,j,t,tt,k;
int f[MAXN];
int shu[MAXN];
int cc,zu,zz;
bool fl[MAXN],h[MAXN];
int dui[MAXN];
int huan1[MAXN],huan2[MAXN],lian1[MAXN],lian2[MAXN];
int nt,mt;


void init(int n)
{
  int i;
  for (i=1;i<=n;i++)
    ff[i]=i;
  memset(fl,0,sizeof(fl));
  cc=0;
  memset(shu,0,sizeof(shu));
}

int cha(int x)
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(int x,int y)
{
  int i,j;
  i=cha(x);j=cha(y);
  if (i==j)
    fl[i]=true;
  else
  {
    ff[i]=j;//总根为标志，把总根挂到另一个的总根下
    fl[j]=fl[j]||fl[i];
  }
}


int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&m);
    init(n);
    memset(huan1,0,sizeof(huan1));
    memset(huan2,0,sizeof(huan2));
    memset(lian1,0,sizeof(lian1));
    memset(lian2,0,sizeof(lian2));
    for (i=1;i<=m;i++)
    {
      sf("%d%d",&j,&k);
      bing(j,k);
    }
    for (i=1;i<=n;i++)
    {
      if (ff[i]==i)
      {
        cc++;
        dui[i]=cc;
        h[cc]=fl[i];
      }
    }
    for (i=1;i<=n;i++)
      shu[dui[cha(i)]]++;
    for (i=1;i<=n;i++)
      if (ff[i]==i)
        if (fl[i])
          huan1[shu[dui[i]]]++;
        else
          lian1[shu[dui[i]]]++;
    nt=n;mt=m;
    sf("%d%d",&n,&m);
    if (n!=nt)
    {
      printf("Case #%d: NO\n",zz);
      continue;
    }
    init(n);
    for (i=1;i<=m;i++)
    {
      sf("%d%d",&j,&k);
      bing(j,k);
    }
    for (i=1;i<=n;i++)
    {
      if (ff[i]==i)
      {
        cc++;
        dui[i]=cc;
        h[cc]=fl[i];
      }
    }
    for (i=1;i<=n;i++)
      shu[dui[cha(i)]]++;
    for (i=1;i<=n;i++)
      if (ff[i]==i)
        if (fl[i])
          huan2[shu[dui[i]]]++;
        else
          lian2[shu[dui[i]]]++;
    bool flag=true;
    for (i=1;i<=n;i++)
      if (huan1[i]!=huan2[i])
      {
        flag=false;
        break;
      }
    if (flag)
      for (i=1;i<=n;i++)
        if (lian1[i]!=lian2[i])
        {
          flag=false;
          break;
        }
    if (flag)
      printf("Case #%d: YES\n",zz);
    else
      printf("Case #%d: NO\n",zz);
  }
  return 0;
}
