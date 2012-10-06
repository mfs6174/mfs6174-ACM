/*
ID: mfs6174
PROG: gcj2010-A
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
ifstream inf("A-large-practice.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long  t,k,n,q;
long long  mi[35];
int i,j,zz,zu;

int main()
{
  inf>>zu;
  mi[0]=1;
  for (i=1;i<=32;i++)
    mi[i]=mi[i-1]*2;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>k;
    q=2;
    for (i=1;i<=n-1;i++)
      q+=mi[i];
    k=k%q;
    if ((k==q-1)||((n==1)&&(k==1)))
      ouf<<"Case #"<<zz<<": "<<"ON"<<endl;
    else
      ouf<<"Case #"<<zz<<": "<<"OFF"<<endl;
  }
}

