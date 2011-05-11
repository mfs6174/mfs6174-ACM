/*
ID: mfs.dev2
PROG: shuttle
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

using namespace std;
ifstream inf("shuttle.in");
ofstream ouf("shuttle.out");
const int maxlongint=2147483647;

int n,i,j,t,k,tt,c=1;

void shu(int x)
{
  c++;
  if (c==20)
  {
    ouf<<x<<endl;
    c=0;
  }
  else
    ouf<<x<<' ';
}

int main()
{
  inf>>n;
  ouf<<n<<' ';
  tt=n;
  t=1;
  k=1;
  for (i=1;i<n;i++)
  {
    for (j=1;j<=i;j++)
    {
      tt+=k*2;
      shu(tt);
    }
    tt+=t;
    shu(tt);
    t=-t;k=-k;
  }
  t=-t;
  for (i=n;i>=1;i--)
  {
    for (j=1;j<=i;j++)
    {
      tt+=k*2;
      shu(tt);
    }
    tt+=t;
    if (i!=1)
      shu(tt);
    else
      ouf<<tt<<endl;
    t=-t;k=-k;
  }
}
