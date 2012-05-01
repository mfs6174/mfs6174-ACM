/*
ID: mfs6174
PROG: GCJ2011C
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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int zz,zu,i,j,k,t,n;
unsigned xhe;
long long he,mm;
long long  shu[1200];

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>shu[1];
    xhe=he=mm=shu[1];
    for (i=2;i<=n;i++)
    {
      inf>>shu[i];
      xhe=xhe^shu[i];
      he+=shu[i];
      mm=min(mm,shu[i]);
    }
    if (xhe)
    {
      ouf<<"Case #"<<zz<<": NO"<<endl;
      continue;
    }
    else
      ouf<<"Case #"<<zz<<": "<<he-mm<<endl;
  }
}

      
    
