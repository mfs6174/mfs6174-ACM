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

int i,j,k,y,n,m,rr,c;
int du[200],tu[200][200];
bool chu[200];
int gua[200];

int main()
{
  sf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    sf("%d%d",&j,&k);
    tu[j][k]=tu[k][j]=1;
    du[j]++;du[k]++;
  }
  bool fl=true;
  while (fl)
  {
    fl=false;
    c=0;
    for (i=1;i<=n;i++)
      if (du[i]==1&&(!chu[i]))
      {
        c++;
        gua[c]=i;
      }
    for (i=1;i<=c;i++)
    {
      chu[gua[i]]=true;
      du[gua[i]]--;
      for (j=1;j<=n;j++)
        if (tu[gua[i]][j])
          du[j]--;
    }
    if (c) fl=true;
    if (fl)
      rr++;
  }
  cout<<rr<<endl;
  return 0;
}

