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
  int p[2];
  int rx;
  int d;
};

int i,j,k,t,n,m,zz,zu,c;
int L,R;

D pp[2100000];

void moveleft(lr)
{
  if (lr==1)
    L=pp[L].p[1-rx];
  else
    R=pp[R].p[1-rx];
}

void moveright(lr)
{
  if (lr==1)
    L=pp[L].p[rx];
  else
    R=pp[R].p[rx];
}

void insl(int x)
{
  c++;
  pp[cc].d=x;
  int t=pp[L].p[1-rx];
  pp[t].p[rx]=cc;
  pp[L].p[1-rx]=cc;
  pp[cc].p[rx]=L;
  pp[cc].p[1-rx]=pp[L].p[1-rx];
}

void insr(int x)
{
  c++;
  pp[cc].d=x;
  int t=pp[R].p[rx];
  pp[t].p[1-rx]=cc;
  pp[R].p[rx]=cc;
  pp[cc].p[1-rx]=R;
  pp[cc].p[rx]=pp[R].p[rx];
}

void dell()
{
  int t=PP[L].p[1-rx],tt=PP[L].p[rx];
  pp[t].p[rx]=tt;
  p[tt].p[1-rx]=t;
}

void delr()
{
  int t=PP[R].p[1-rx],tt=PP[R].p[rx];
  pp[t].p[rx]=tt;
  p[tt].p[1-rx]=t;
}

void rvs()
{
}

int main()
{
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    c=0;
    sf("%d",&n);
    for (i=1;i<=n;i++)
    {
      sf("%d",&t);
      c++;
      PP[c].d=t;
      pp[c].p[0]=c+1;
      pp[c].p[1]=c-1;
      pp[c].rx=0;
    }
    pp[0].d=maxlongint;
    pp[c+1].d=maxlongint;
    sf("%d%d",&L,&R);
    

