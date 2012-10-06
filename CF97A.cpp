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

int i,j,k,t,n,m;
int shu[110000];
bool ff=false;
int main()
{
  sf("%d",&n);
  for (i=1;i<=n;i++)
  {
    sf("%d",&shu[i]);
    if (shu[i]!=1)
      ff=true;
  }
  if (n==1)
  {
    if (shu[1]==1)
      pf("%d\n",2);
    else
      pf("%d\n",1);
  }
  else
  {
    sort(&shu[1],&shu[n+1]);
    pf("%d",1);
    for (i=2;i<n;i++)
      pf(" %d",shu[i-1]);
    if (ff)
      pf(" %d\n",shu[n-1]);
    else
      pf(" %d\n",2);
  }
  return 0;
}


