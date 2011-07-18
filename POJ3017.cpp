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
  llg d,p;
  set<llg>::iterator w;
};

llg i,j,k,n,m,t,w,tn,ttt;
llg shu[100010],f[100010],s[100010];
multiset<llg> ss;
D q[150000],tt;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%lld%lld",&n,&m);
  for (i=1;i<=n;i++)
  {
    sf("%lld",&shu[i]);
    s[i]=s[i-1]+shu[i];
  }
  t=1;
  w=1;
  q[1].p=0;
  q[1].d=0;
  q[1].w=ss.insert(0);
  for (i=1;i<=n;i++)
  {
    while ((w>=t)&&(q[w].d<shu[i]))
    {
      //ttt=f[q[w].p];
      ss.erase(q[w].w);
      w--;
    }
    if (w<t)
      tn=f[q[w+1].p]+shu[i];
    else
      tn=f[q[w].p]+shu[i];
    q[w].w=(ss.insert(tn));
    if (q[w].d<shu[i])
      w--;
    tt.d=shu[i];
    tt.p=i;
    q[++w]=tt;
    while (s[i]-s[q[t].p]>m)
    {
      ss.erase(q[t].w);
      t++;
    }
    if (!ss.empty())
      f[i]=*(ss.begin());
    else
    {
      cout<<-1<<endl;
      exit(0);
    }
  }
  cout<<f[n]<<endl;
  return 0;
}

