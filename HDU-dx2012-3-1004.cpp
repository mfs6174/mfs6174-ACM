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

int i,j,k,t,n,m,th,c;
int zu,zz;
char ss[1600][15],s[15];

int myabs(int a)
{
  if (a<0)
    return -a;
  else
    return a;
}

int dp(char a[],char b[])
{
  int f[15][15];
  int i,j;
  int la=strlen(a+1),lb=strlen(b+1);
  for (i=1;i<=la;i++)
    for (j=1;j<=lb;j++)
      f[i][j]=maxlongint-10;
  for (i=1;i<=la;i++)
    f[i][0]=i;
  for (i=1;i<=lb;i++)
    f[0][i]=i;
  f[0][0]=0;
  for (i=1;i<=la;i++)
    for (j=1;j<=lb;j++)
      f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+(a[i]==b[j]?0:1));
  return f[la][lb];
}
int main()
{
  freopen("1004.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      sf("%s",ss[i]+1);
    pf("Case #%d:\n",zz);
    for (k=1;k<=m;k++)
    {
      sf("%s",s+1);
      sf("%d",&th);
      c=0;
      for (i=1;i<=n;i++)
      {
        if (myabs(strlen(ss[i]+1)-strlen(s+1))>th)
         continue;
        if (dp(ss[i],s)<=th)
          c++;
      }
      pf("%d\n",c);
    }
  }
  return 0;
}
      
