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

llg qp,s[100010];

struct P
{
  llg p;
  bool operator <(const P &x) const
  {
    return (s[qp]-s[p])>(s[qp]-s[x.p]);
  }
};

llg i,j,k,n,m,t,w,tn,ttt;
llg shu[100010],f[100010];
mset<llg> ss;
D q[150000],tt;
P cha[100010],tp;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%lld%lld",&n,&m);
  for (i=1;i<=n;i++)
  {
    sf("%lld",&shu[i]);
    s[i]=s[i-1]+shu[i];
    cha[i].p=i;
  }
  cha[0].p=0;
  t=1;
  w=1;
  q[1].p=1;
  q[1].d=shu[1];
  f[1]=shu[1];
  for (i=2;i<=n;i++)
  {
    int cd=0;
    while ((w>=t)&&(q[w].d<shu[i]))
    {
      if (cd>0)
        ss.erase(q[w].w);
      w--;
      cd++;
    }
    if ((cd>0)&&(w>=t))
      ss.erase(q[w].w);
    if (w>=t)
      q[w].w=(ss.insert(f[q[w].p]+shu[i])).first;
    tt.d=shu[i];
    tt.p=i;
    q[++w]=tt;
    while (s[i]-s[q[t].p]>m)
    {
      if (!ss.empty())
        ss.erase(q[t].w);
      t++;
    }
    f[i]=-1;
    if (!ss.empty())
      f[i]=*(ss.begin());
    qp=i;
    tp.p=n+1;
    s[n+1]=s[i]-m;
    ttt=(lower_bound(&(cha[0]),&cha[i+1],tp))->p;
    tn=f[ttt];
    int tm=t;  
    if (ttt<i)
    {
      while  (ttt>=q[tm].p) tm++;
      tn+=q[tm].d;
      if (f[i]!=-1)
        f[i]=min(f[i],tn);
      else
        f[i]=tn;
    }
    if (f[i]==-1)
    {
      cout<<-1<<endl;
      exit(0);
    }
  }
  cout<<f[n]<<endl;
  return 0;
}

