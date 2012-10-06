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
const int maxlongint=2147483647;

struct A
{
  int a,h,b;
  bool operator <(const A &x) const
  {
    if (a!=x.a)
      return a<x.a;
    else
      return b>x.b;
  }
};
struct B
{
  int b,h,a;
  bool operator <(const B &x) const
  {
    return b<x.b;
  }
};
  
int i,j,k,t,n,m,zz,zu,c,t0,t1,t2;
A yi[1100];
B er[1100];
int st[1100],a[1100],b[1100];

int main()
{
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    for (i=1;i<=n;i++)
    {
      sf("%d%d",&a[i],&b[i]);
      yi[i].h=er[i].h=i;
      yi[i].a=er[i].a=a[i];
      yi[i].b=er[i].b=b[i];
    }
    sort(&yi[1],&yi[n+1]);
    sort(&er[1],&er[n+1]);
    memset(st,0,sizeof(st));
    m=0;k=0;c=0;
    while (c<n)
    {
      k++;
      t0=t1=t2=0;
      for (i=1;i<=n;i++)
      {
        if (t2==0&&st[er[i].h]==0)
          t2=er[i].h;
        if (t1==0&&st[er[i].h]==1)
          t1=er[i].h;
        if (t0==0&&st[yi[i].h]==0)
          t0=yi[i].h;
      }
      if (b[t2]<=m&&t2)
      {
        st[t2]=2;
        c++;
        m+=2;
        continue;
      }
      if (b[t1]<=m&&t1)
      {
        st[t1]=2;
        c++;
        m++;
        continue;
      }
      if (a[t0]<=m&&t0)
      {
        st[t0]=1;
        m++;
      }
      else
      {
        c=-1;
        break;
      }
    }
    if (c==-1)
      printf("Case #%d: Too Bad\n",zz);
    else
      printf("Case #%d: %d\n",zz,k);
  }
  return 0;
}
    

