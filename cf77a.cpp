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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long  i,j,m,n;
string ss;
char t;
int main()
{
  cin>>ss;
  m=ss.size();
  t=ss[0];
  n=1;
  for (i=1;i<m;i++)
  {
    if (ss[i]==t)
      n++;
    else
    {
      n=1;
      t=ss[i];
    }
    if (n>=7)
    {
      j=1;
      break;
    }
  }
  if (j)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
