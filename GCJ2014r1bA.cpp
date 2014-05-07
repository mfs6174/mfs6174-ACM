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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m;

struct D
{
  int id;
  int len;
  int shu[200],clen;
  char code[200];
  bool operator <(const D &x) const
  {
    return len<x.len;
  }
};

D chuan[200];
string dd[200];
int op[200];

int main()
{
   freopen("ti.out","w",stdout);
  int zu;
  inf>>zu;
  for (int zz=1;zz<=zu;zz++)
  {
    inf>>n;
    for (i=1;i<=n;i++)
    {
      inf>>dd[i];
      chuan[i].id=i;
      chuan[i].len=dd[i].size();
      char t=-1;
      chuan[i].clen=0;
      for (j=0;j<dd[i].size();j++)
      {
        if (dd[i][j]!=t)
        {
          chuan[i].clen++;
          chuan[i].code[chuan[i].clen]=dd[i][j];
          chuan[i].shu[chuan[i].clen]=1;
          t=dd[i][j];
        }
        else
        {
          chuan[i].shu[chuan[i].clen]++;
        }
      }
    }
    bool fail=false;
    int rr=0;
    for (int j=1;j<=chuan[1].clen;j++)
    {
      op[1]=chuan[1].shu[j];
      for (i=2;i<=n;i++)
      {
        if (chuan[i].clen!=chuan[1].clen)
        {
          fail=true;
          break;
        }
        if (chuan[i].code[j]!=chuan[1].code[j])
        {
          fail=true;
          break;
        }
        op[i]=chuan[i].shu[j];
      }
      if (fail)
        break;
      sort(&op[1],&op[n+1]);
      for (i=1;i<=n;i++)
        rr+=abs(op[i]-op[n/2+1]);
    }
    if (fail)
    {
      pf("Case #%d: Fegla Won\n",zz);
    }
    else
      pf("Case #%d: %d\n",zz,rr);
  }
  return 0;
}
        
