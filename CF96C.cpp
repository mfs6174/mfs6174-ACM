/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,p;
char cc;

int res(char x)
{
  int rt=0;
  for (int i=0;i<8;i++)
    if (x&(1<<i))
      rt=rt|(1<<(7-i));
  return rt;
}

int main()
{
  p=0;
  while (sf("%c",&cc)!=EOF)
  {
    if (cc<32||cc>126)
      continue;
    t=res(cc);
    m=((p-t)%256+256)%256;
    cout<<m<<endl;
    p=t;
  }
  return 0;
}

