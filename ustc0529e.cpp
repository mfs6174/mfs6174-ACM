/*
ID: mfs6174
PROG: ustc 0529 E
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

int i,j,k,mm,zu,zz;
int he[15];
string n,m;

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>m;
    for (i=0;i<=9;i++)
    {
      he[i]=0;
      for (j=0;j<m.size();j++)
        he[i]+=i%(m[j]-48);
    }
    mm=0;
    for (i=0;i<m.size();i++)
      mm+=he[n[i]-48];
    cout<<mm<<endl;
  }
}
