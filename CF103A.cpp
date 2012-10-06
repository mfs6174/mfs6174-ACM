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

int i,j,k,t,n,ma,mi,m,c,tt;
int shu[200];

int main()
{
  sf("%d",&n);
  ma=-1;
  mi=maxlongint;
  for (i=1;i<=n;i++)
  {
    sf("%d",&shu[i]);
    if (shu[i]>ma)
    {
      ma=shu[i];
      t=i;
    }
    if (shu[i]<=mi)
    {
      mi=shu[i];
      tt=i;
    }
  }
  m=t-1;
  if (tt>=t)
    m+=n-tt;
  else
    m+=n-1-tt;
  cout<<m<<endl;
  return 0;
}
