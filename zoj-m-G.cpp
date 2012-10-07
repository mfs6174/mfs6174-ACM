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

int i,j,k,t,n,m,ll,rr,o;
int shu[1100];
int f[1010][55][55];
int isqrt[100];
 
void init()
{
  for(int i = 0; i < 10; i++)
    for(int j = i * i; j < (i + 1) * (i + 1); j++)
      isqrt[j] = i;
}

int main()
{
  init();
  freopen("ti.in","r",stdin);
  while (sf("%d%d%d",&ll,&rr,&n)!=EOF)
  {
    for (i=1;i<=n;i++)
      sf("%d",&shu[i]);
    for (i=0;i<=n;i++)
      for (j=0;j<=52;j++)
        for (k=0;k<=52;k++)
          f[i][j][k]=maxlongint;
    f[0][ll][rr]=0;
    for (i=1;i<=1;i++)
    {
      for (j=max(shu[i],4);j<=min(shu[i]+8,51);j++)
        for (k=0;k<=47;k++)
        {
          if ((k>=j-8&&k<=j)||(shu[i]>=k&&shu[i]<=k+4))
            continue;
          for (o=4;o<=51;o++)
            if (f[i-1][o][k]!=maxlongint)
              f[i][j][k]=min(f[i][j][k],f[i-1][o][k]+(int)(floor(sqrt(abs(o-j)))+1e-7));
        }
      for (k=max(shu[i]-8,0);k<=min(shu[i],47);k++)
        for (j=4;j<=51;j++)
        {
          if ( (k>=j-8&&k<=j) || (shu[i]<=j&&shu[i]>=j-4))
            continue;
          for (o=0;o<=47;o++)
            if (f[i-1][j][o]!=maxlongint)
              f[i][j][k]=min(f[i][j][k],f[i-1][j][o]+(int)(floor(sqrt(abs(o-k)))+1e-7));
        }
    }
    for (i=1;i<n;i++)
    {
      for (j=max(shu[i],4);j<=min(shu[i]+8,51);j++)
        for (k=0;k<=47;k++)
        {
          if (f[i][j][k]==maxlongint)
            continue;
          for (o=max(shu[i+1],4);o<=min(shu[i+1]+8,51);o++)
            f[i+1][o][k]=min(f[i+1][o][k],f[i][j][k]+isqrt[abs(o-j)]);
          for (o=max(shu[i+1]-8,0);o<=min(shu[i+1],47);o++)
            f[i+1][j][o]=min(f[i+1][j][o],f[i][j][k]+isqrt[abs(o-k)]);
        }
      for (k=max(shu[i]-8,0);k<=min(shu[i],47);k++)
        for (j=4;j<=51;j++)
        {
          if (f[i][j][k]==maxlongint)
            continue;
          for (o=max(shu[i+1],4);o<=min(shu[i+1]+8,51);o++)
            f[i+1][o][k]=min(f[i+1][o][k],f[i][j][k]+isqrt[abs(o-j)]);
          for (o=max(shu[i+1]-8,0);o<=min(shu[i+1],47);o++)
            f[i+1][j][o]=min(f[i+1][j][o],f[i][j][k]+isqrt[abs(o-k)]);
        }
    }
    int mm=maxlongint;
    for (j=4;j<=51;j++)
      for (k=0;k<=47;k++)
        if (f[n][j][k]!=maxlongint)
          mm=min(mm,f[n][j][k]);
    cout<<mm<<endl;
  }
  return 0;
}
