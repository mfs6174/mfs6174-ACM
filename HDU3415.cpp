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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int d,p;
};

int i,j,k,t,n,m,zz,zu,dt,dw,mm,st,ed;
int shu[210000];
D tt,q[350000];

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&k);
    shu[0]=0;
    for (i=1;i<=n;i++)
    {
      sf("%d",&shu[i]);
      shu[i+n]=shu[i];
      shu[i]+=shu[i-1];
    }
    for (i=1;i<=n;i++)
      shu[i+n]+=shu[i+n-1];
    dt=1;
    dw=1;
    m=2*n;
    mm=-maxlongint;
    q[dw].p=0;
    q[dw].d=0;
    for (i=1;i<=m;i++)
    {
      while (q[dt].p<i-k) dt++;
      if (q[dt].d+shu[i]>mm)
      {
        mm=q[dt].d+shu[i];
        st=q[dt].p+1;
        ed=i;
        if (ed>n)
          ed-=n;
      }
      tt.p=i;
      tt.d=-shu[i];
      while ((dw>=dt)&&(q[dw].d<tt.d)) dw--;
      q[++dw]=tt;
    }
    cout<<mm<<' '<<st<<' '<<ed<<endl;
  }
  return 0;
}

