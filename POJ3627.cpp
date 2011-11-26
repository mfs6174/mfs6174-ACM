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

llg i,k,t,n,m,h,mm;
llg shu[30000];

int main()
{
  sf("%lld%lld",&n,&h);
  for (i=1;i<=n;i++)
    sf("%lld",&shu[i]);
  sort(&shu[1],&shu[n+1]);
  k=mm=0;
  for (i=n;i>=1;i--)
  {
    if (k>=h)
      break;
    k+=shu[i];
    mm++;
  }
  cout<<mm<<endl;
  return 0;
}
