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

int i,j,k,t,n,m,s,mm;
int shu[22000];

int main()
{
  sf("%d%d",&n,&s);
  for (i=1;i<=n;i++)
    sf("%d",&shu[i]);
  sort(&shu[1],&shu[n+1]);
  j=n;mm=0;
  for (i=1;i<=n;i++)
  {
    while (shu[i]+shu[j]>s&&j>i)
      j--;
    if (j-i>0)
      mm+=j-i;
    else
      break;
  }
  cout<<mm<<endl;
  return 0;
}

