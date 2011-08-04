/*
ID: mfs6174
PROG: POJ3905
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,l;
int f[1100][1100],s[1100],g[1100][1100];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d%d",&n,&m,&l)!=EOF)
  {
    s[0]=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&s[i]);
      s[i]+=s[i-1];
    }
    if (m+l>n)
    {
      cout<<0<<endl;
      continue;
    }
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    g[0][0]=0;
    int mm=0;
    for (i=0;i<l;i++)
      f[i][i]=0;
    for (i=l;i<=n;i++)
    {
      f[i][i]=0;
      for (j=0;j<=m;j++)
      {
        if (j-1>=0)
        {
          if (f[i-1][j-1]!=-1)
            f[i][j]=max(f[i-1][j-1],f[i][j]);
          if (g[i-1][j-1]!=-1)
            f[i][j]=max(f[i][j],g[i-1][j-1]);
        }
        if (g[i-1][j]!=-1)
          g[i][j]=max(g[i][j],g[i-1][j]+s[i]-s[i-1]);
        if (f[i-l][j]!=-1)
          g[i][j]=max(g[i][j],f[i-l][j]+s[i]-s[i-l]);
      }
      mm=max(mm,max(f[i][m],g[i][m]));
    }
    cout<<mm<<endl;
  }
  return 0;
}

