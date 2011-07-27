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
const int maxlongint=2147483647;

int a,b,m,s,mm,i,k,t;

int main()
{
  //freopen("ti.in","r",stdin);
  while (scanf("%d%d%d",&a,&b,&m)!=EOF)
  {
    if (a>b)
    {
      t=a;
      a=b;
      b=t;
    }
    if (b==1)
    {
      cout<<m<<endl;
      continue;
    }
    mm=m/b;
    k=mm/b;
    s=mm-k;
    cout<<s<<endl;
  }
  return 0;
}

    
