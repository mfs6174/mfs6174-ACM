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
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long  a,b,i,t,k;
double f=(1.0+sqrt(5))/2.0;

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%lld%lld",&a,&b)!=EOF)
  {
    if (a>b)
    {
      t=a;
      a=b;
      b=t;
    }
    k=b-a;
    t=floor(k*f);
    if (t==a)
      cout<<0<<endl;
    else
      cout<<1<<endl;
  }
  return 0;
}
