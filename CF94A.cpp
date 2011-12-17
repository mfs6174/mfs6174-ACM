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

int i,j,k,t,n,m;
int shu[1000];

int main()
{
  sf("%d",&n);
  m=0;
  for (i=1;i<=n;i++)
  {
    sf("%d",&shu[i]);
    m+=shu[i];
  }
  k=0;
  for (i=1;i<=n;i++)
    if (((m-shu[i])&1)==0)
      k++;
  cout<<k;
  return 0;
}

    
