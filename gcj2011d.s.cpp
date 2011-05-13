/*
ID: mfs6174
PROG: GCJ2011D.s
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
#include<iomanip>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int x,h;
  bool operator <(const D &y) const
  {
    return x<y.x;
  }
};

int i,j,k,n,t,zz,zu,mm;
int hao[2000];
D shu[2000];

    

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n;
    mm=0;
    for (i=1;i<=n;i++)
    {
      inf>>shu[i].x;
      shu[i].h=i;
    }
    sort(&(shu[1]),&(shu[n+1]));
    for (i=1;i<=n;i++)
      hao[shu[i].h]=i;
    for (i=1;i<=n;i++)
      if (hao[i]!=i)
        mm++;
    ouf<<"Case #"<<zz<<": "<<fixed<<setw(6)<<double(mm)<<endl;
  }
}

