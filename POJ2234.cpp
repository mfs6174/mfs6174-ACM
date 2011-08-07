/*
ID: mfs6174
PROG: POJ2234
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

unsigned shu[30];
int i,j,n;
unsigned t;

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&shu[i]);
    t=shu[1];
    for (i=2;i<=n;i++)
      t=t^shu[i];
    if (t)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}

