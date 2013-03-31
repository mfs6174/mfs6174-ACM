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
const int maxlongint=2147483647;

int i,j,k,t,n,m;
int ff[100][100];
int wei[100][100];

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d",&n,&k)!=EOF)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=k;j++)
        sf("%d",&wei[i][j]);
    for (i=0;i<=21;i++)
      for (j=1;j<=20;j++)
        ff[i][j]=maxlongint;
    for (i=1;i<=k;i++)
      ff[1][i]=0;
    for (i=2;i<=n;i++)
      for (j=1;j<=k;j++)
        for (int o=1;o<=k;o++)
          ff[i][j]=min(ff[i][j],ff[i-1][o]+abs(wei[i][j]-wei[i-1][o]));
    int mm=maxlongint;
    for (i=1;i<=k;i++)
      mm=min(mm,ff[n][i]);
    cout<<mm<<endl;
  }
  return 0;
}
