/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: HDU3530
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

int i,j,k,t,n,m,mm,xt,dt,xw,dw;
int shu[120000];
D tt,qx[120000],qd[120000];

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d%d",&n,&m,&k)!=EOF)
  {
    for (i=1;i<=n;i++)
      sf("%d",&shu[i]);
    shu[0]=0;
    xt=dt=1;
    xw=dw=0;
    mm=0;
    for (i=1;i<=n;i++)
    {
      tt.p=i;
      tt.d=shu[i];
      while ((xw>=xt)&&(qx[xw].d>tt.d)) xw--;
      qx[++xw]=tt;
      while ((dw>=dt)&&(qd[dw].d<tt.d)) dw--;
      qd[++dw]=tt;
      while (qd[dt].d-qx[xt].d>k)
      {
        if (qd[dt].p<qx[xt].p)
          dt++;
        else
          xt++;
      }
      if (qd[dt].d-qx[xt].d>=m)
        mm=max(mm,i-max(qd[dt-1].p+1,qx[xt-1].p+1)+1);
    }
    cout<<mm<<endl;
  }
  return 0;
}

