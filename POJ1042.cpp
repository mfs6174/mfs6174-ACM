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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int n,p;
  bool operator <(const D &x) const
  {
    return n>x.n;
  }
};

int i,j,k,t,n,m,tt,rr,h,he;
int chu[50],dd[50],ji[50];
set<D> ss;
D ttt;

int main()
{
  while (sf("%d",&n)!=EOF&&n)
  {
    ss.clear();
    sf("%d",&h);
    h=h*60/5;
    for (i=1;i<=n;i++)
    {
      sf("%d",&chu[i]);
      ttt.n=chu[i];ttt.p=i;
      ss.insert(ttt);
    }
    for (i=1;i<=n;i++)
      sf("%d",&dd[i]);
    he=0;
    for (i=1;i<n;i++)
    {
      sf("%d",&t);
      he+=t;
    }
    
  }
  

