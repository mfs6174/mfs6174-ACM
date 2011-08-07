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

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

long long i,j,k,t,n,s,tt;
long long shu[120];

int main()
{
  cin>>n;
  for (i=1;i<=n;i++)
    cin>>shu[i];
  s+=shu[1];
  for (i=2;i<=n;i++)
  {
    s++;
    s+=((i-1)+1)*(shu[i]-1);
  }
  cout<<s<<endl;
  return 0;
}

