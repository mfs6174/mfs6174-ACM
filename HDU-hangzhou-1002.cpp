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

int i,j,k,t,n,m,nn;
int d[120][120],dd[120][120];
int ff[30][120];

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d",&n,&m,&nn)!=EOF)
  {
    if (n==0&&m==0&&nn==0)
      break;
    memset(dd,0,sizeof(dd));
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
        if (i!=j)
          dd[i][j]=maxlongint;
    for (i=1;i<=m;i++)
    {
      sf("%d%d%d",&j,&k,&t);
      if (j==k)
        continue;
      dd[j][k]=min(dd[j][k],t);
      dd[k][j]=dd[j][k];
    }
    for (k=0;k<=n;k++)
      for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
        {
          if (dd[i][k]==maxlongint||dd[k][j]==maxlongint)
            continue;
          dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
        }
    t=0;
    for (j=1;j<=n;j++)
    {
      t+
  
