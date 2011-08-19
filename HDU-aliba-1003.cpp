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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,rr;
string s,ss;

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>s>>ss;
    rr=0;
    n=s.size();m=ss.size();
    for (i=0;i<n;i++)
      rr+=s[i]-48;
    for (i=0;i<m;i++)
      rr+=ss[i]-48;
    printf("Case %d: %d\n",zz,rr);
  }
  return 0;
}
