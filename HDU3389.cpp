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

int i,j,k,n,zz,zu;
unsigned t,r;

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    r=0;
    for (i=1;i<=n;i++)
    {
      cin>>t;
      if (((i%6)==0)||(i%6==2)||(i%6==5))
        r=r^t;
    }
    cout<<"Case "<<zz<<": ";
    if (r)
      cout<<"Alice"<<endl;
    else
      cout<<"Bob"<<endl;
  }
  return 0;
}

