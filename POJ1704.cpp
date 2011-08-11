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

unsigned wei[1100],shu[1100];
int i,j,k,t,n,m,zz,zu;
unsigned rr;
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    rr=0;
    cin>>n;
    for (i=1;i<=n;i++)
      cin>>wei[i];
    sort(&wei[1],&wei[n+1]);
    for (i=1;i<=n;i++)
      shu[n+1-i]=wei[i]-wei[i-1]-1;
    shu[0]=0;
    for (i=1;i<=n;i+=2)
      rr=rr^shu[i];
    if (!rr)
      cout<<"Bob will win"<<endl;
    else
      cout<<"Georgia will win"<<endl;
  }
  return 0;
}

      
