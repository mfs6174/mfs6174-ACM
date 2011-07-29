/*
ID: mfs6174
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
#define LL long long 
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
struct D
{
  LL x,d;
  bool operator <(const D &b) const
  {
    return x<b.x;
  }
};

LL i,j,k,n,m,t,x,y;
D shu[15000];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%lld%lld",&n,&k)!=EOF)
  {
    for (i=1;i<=n;i++)
      scanf("%lld%lld",&(shu[i].x),&(shu[i].d));
    sort(&shu[1],&shu[n+1]);
    

