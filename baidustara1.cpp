/*
ID: mfs6174
PROG: baidu1
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

int n,m,i,t,tt;

int main()
{
  cin>>n>>m;
  for (i=1;i<=m;i++)
  {
    cin>>t;
    if (t!=1)
      tt++;
  }
  cout<<(n-tt)*tt<<endl;
  return 0;
}

