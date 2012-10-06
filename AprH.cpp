
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,zz,zu,n,mm,t;

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    mm=0;
    if (n==3)
      mm=8;
    else
    {
      n--;
      mm+=16*(n%9973)%9973;
      mm=(mm+6*((n%9973)*(n%9973)%9973)%9973)%9973;
      mm=(mm+2*((n%9973)*(n%9973)%9973*(n%9973)%9973)%9973)%9973;
      mm=(mm-72+8*12)%9973;
      mm=9973-(mm*831%9973);
    }
    cout<<mm<<endl;
  }
}
