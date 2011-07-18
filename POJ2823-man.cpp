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
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int d,p;
};

int i,j,k,t,n,m,mmd=-maxlongint,mmx=maxlongint,dw,dt=1,xw,xt=1;
int xiao[1000100];
D qd[1000100],qx[1000110];
D tt;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  {
    sf("%d",&(tt.d));
    tt.p=i;
    mmd=max(mmd,tt.d);
    mmx=min(mmx,tt.d);
    while ((xw>=xt)&&(qx[xw].d>tt.d)) xw--;
    qx[++xw]=tt;
    while ((dw>=dt)&&(qd[dw].d<tt.d)) dw--;
    qd[++dw]=tt;
    if (i>=k)
    {
      while (qx[xt].p<i-k+1) xt++;
      pf("%d",qx[xt].d);
      if (i!=n)
        pf(" ");
      while (qd[dt].p<i-k+1) dt++;
      xiao[i]=qd[dt].d;
    }
  }
  if (n<k)
  {
    cout<<mmd<<endl<<mmx<<endl;
    exit(0);
  }
  pf("\n");
  for (i=k;i<n;i++)
    pf("%d ",xiao[i]);
  pf("%d",xiao[n]);
  return 0;
}

    
    

