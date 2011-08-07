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

int t,n;

int main()
{
  cin>>n;
  t=n-10;
  if (t==10)
  {
    cout<<15<<endl;
    exit(0);
  }
  if ((t>=1&&t<=9)||(t==11))
  {
    cout<<4<<endl;
    exit(0);
  }
  cout<<0<<endl;
  return 0;
}
