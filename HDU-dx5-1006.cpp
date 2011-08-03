/*
ID: mfs6174
PROG: ti
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
set<int> dui[1010];

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
      dui[i].clear();
    }
     if (m+l>n)
    {
      cout<<0<<endl;
      continue;
    }
    dui[0].clear();
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    g[0][0]=0;
    int mm=0;
    for (i=0;i<l;i++)
    {
      f[i][i]=0;
      if (i>=m)
        mm=max(mm,f[i][i]);
    }
    for (i=l;i<=n;i++)
    {
      f[i][i]=0;
      for (j=0;j<=m;j++)
      {
        if (f[i-l][j]!=-1)
          dui[j].insert(f[i-l][j]-s[i-l]);
        if (!dui[j].empty())
          g[i][j]=s[i]+*(--(dui[j].end()));
        i=i;
        if (j<m-n+i||g[i][j]==-1)
          continue;
        for (k=i+1;k<=n;k++)
        {
           if (j+k-i>m)
            break;
          if (g[i][j]>f[k][j+k-i])
            f[k][j+k-i]=g[i][j];
        }
      }
      mm=max(mm,max(f[i][m],g[i][m]));
    }
    cout<<mm<<endl;
  }
  return 0;
}

    
