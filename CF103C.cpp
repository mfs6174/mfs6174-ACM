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

int i,j,k,t,n,m,mm;
int ff[110000][30];
int shu[30];
char s[110000],ss[110000];

int main()
{
  sf("%s%s",s,ss);
  m=strlen(ss);
  n=strlen(s);
  if (m>n)
  {
    cout<<0<<endl;
    exit(0);
  }
  for (i=1;i<=n;i++)
  {
    for (j=0;j<=26;j++)
      ff[i][j]=ff[i-1][j];
    if (s[i-1]=='?')
      ff[i][0]++;
    else
      ff[i][s[i-1]-'a'+1]++;
  }
  for (i=1;i<=m;i++)
    shu[ss[i-1]-'a'+1]++;
  i=1;
  while (i+m-1<=n)
  {
    t=i+m-1;
    k=0;
    bool can=true;
    for (j=1;j<=26;j++)
      if (shu[j]<(ff[t][j]-ff[i-1][j]))
      {
        can=false;
        break;
      }
      else
        k+=shu[j]-(ff[t][j]-ff[i-1][j]);
    if (can&&(k==(ff[t][0]-ff[i-1][0])))
      mm++;
    i++;
  }
  cout<<mm<<endl;
  return 0;
}


