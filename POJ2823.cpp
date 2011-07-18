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
#define ll long long 
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int d,p;
};

int i,j,k,t,n,m,mmd=-maxlongint,mmx=maxlongint;
int xiao[1200010];
deque<D> qd,qx;
D tt;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d%d",&n,&k);
  qd.clear();qx.clear();
  for (i=1;i<=n;i++)
  {
    sf("%d",&(tt.d));
    tt.p=i;
    mmd=max(mmd,tt.d);
    mmx=min(mmx,tt.d);
    while ((!qx.empty())&&(qx.back().d>tt.d)) qx.pop_back();
    qx.push_back(tt);
    while ((!qd.empty())&&(qd.back().d<tt.d)) qd.pop_back();
    qd.push_back(tt);
    if (i>=k)
    {
      while (qx.front().p<i-k+1) qx.pop_front();
      pf("%d",qx.front().d);
      if (i!=n)
        pf(" ");
      while (qd.front().p<i-k+1) qd.pop_front();
      xiao[i]=qd.front().d;
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

    
    

