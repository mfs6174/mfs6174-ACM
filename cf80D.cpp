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

long long i,j,n,a,t,m,q,tt,ttt;

int main()
{
  cin>>n>>m>>q;
  t=n-m;
  if (t&1)
    tt=t/2+1;
  else
    tt=t/2;
  ttt=m;
  t=n-2*ttt;
  if (t>0)
    if (t&1)
      ttt+=t/2+1;
    else
      ttt+=t/2;
  if (tt>=ttt)
  {
    for (i=1;i<=q;i++)
    {
      cin>>t;
      if (t<=n-m)
        cout<<'.';
      else
        cout<<'X';
    }
  }
  else
  {
    cin>>j;
    if (j<=t)
      cout<<'.'<<endl;
    
  }
  return 0;
}
