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
const int maxlongint=2147483647;

struct D
{
  int pre,next;
  long long data;
};

D shu[2000];

int i,j,k,t,n,m,al;

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d",&n)!=EOF)
  {
    al=0;
    for (i=1;i<=n;i++)
      

