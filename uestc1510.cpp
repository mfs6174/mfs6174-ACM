/*
ID: mfs.dev2
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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int w,s;
  bool operator <(const D &x) const
  {
    return s>x.s;
  }
};

int i,j,k,t,n,m,mm;
int f[6000];
D gui[6000];

int main()
{
  while (cin>>t>>m)
  {
    n++;
    gui[n].w=t;
    gui[n].s=m;
  }
  sort(&(gui[1]),&(gui[n+1]));
  memset(f,-1,sizeof(f));
  for (i=1;i<=n;i++)
  {
    for (j=i;j>=2;j--)
    {
      if (f[j-1]>=gui[i].w)
        f[j]=max(min(f[j-1]-gui[i].w,gui[i].s-gui[i].w),f[j]);
    }
    f[1]=max(f[1],gui[i].s-gui[i].w);
  }
  for (i=n;i>=1;i--)
    if (f[i]>=0)
    {
      mm=i;
      break;
    }
  cout<<mm<<endl;
  return 0;
}

             
      
