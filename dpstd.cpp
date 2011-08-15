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
ifstream inf("dpin.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,a,b,zz,zu,mm;
int shu[1100],s[1100];
int f[1100][40];
int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>m>>a>>b;
    for (i=1;i<=n;i++)
    {
      inf>>shu[i];
      s[i]=s[i-1]+shu[i];
    }
    for (i=1;i<=m;i++)
      f[0][i]=-maxlongint;
    f[0][0]=0;
    for (i=1;i<=n;i++)
      for (j=0;j<=m;j++)
      {
        f[i][j]=-maxlongint;
        if (f[i-1][j]!=-maxlongint)
          f[i][j]=max(f[i][j],f[i-1][j]+shu[i]);
        t=max(i-b-1,0);
        if (i-a-1>=0&&j>0)
          for (k=t;k<=i-a-1;k++)
            if (f[k][j-1]!=-maxlongint)
              f[i][j]=max(f[i][j],f[k][j-1]+shu[k+1]+(s[i]-s[k+1])*2);
      }
    mm=-maxlongint;
    for (i=0;i<=m;i++)
      mm=max(mm,f[n][i]);
    cout<<mm<<endl;
  }
  return 0;
}

