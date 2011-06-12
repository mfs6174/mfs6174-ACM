#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
const int maxlongint=2147483647;
ifstream inf("ti.in");
ofstream ouf("ti.out");

struct R
{
  int p,q,a,h;
  bool opetator < (const R &x) const
  {
    return p<x.p;
  }
};

int i,j,k,t,n,m,zz,zu,c,a,b;
vector<vector<int>> ss;
R ren[10010],ling[110];

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>m>>c;
    for (i=1;i<=n;i+=)
        {
          inf>>ren[i].p>>ren[i].q>>ren[i].a;
          ren[i].h=i;
        }
      sort(&(ren[1]),&(ren[n+1]));
      for (i=1;i<=c;i+=)
        inf>>ling[i].p>>ling[i].q>>ling[i].a;
      sort(&(ling[1]),&(ling[i+1]));
      
        
        
