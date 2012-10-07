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
int dd[10000],ff[10000];

void arr(int x,int m,int n)
{
  for (int i=1;i<=n;i++)
    if (!ff[i])
    {
      dd[x]=i;ff[i]=true;
      if (x==m)
      {
        //do_something_with_dd
      }
      else
        arr(x+1,m,n);
      ff[i]=false;
    }
}

void com(int x,int m,int n)
{
  for (int i=dd[x-1]+1;i<=n-(m-x);i++)
  {
    dd[x]=i;
    if (x==m)
    {
      //do_something_with_dd
    }
    else
      com(x+1,m,n);
  }
}

int main()
{
  memset(ff,0,sizeof(ff));
  arr(1,m,n);
  com(1,m,n);
  //chose m from n
  return 0;
}
