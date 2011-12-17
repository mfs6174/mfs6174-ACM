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
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,c,cc,ccc;
int shu[1100],qi[1100],zhong[1100],f[1100],tt[1100][1100];
bool tu[1100][1100],ff[1100];

void dfs(int x)
{
  ff[x]=true;
  if (f[x]==1)
    return;
  int i;
  for (i=1;i<=tt[x][0];i++)
  {
    tu[tt[x][i]][x]=true;
    dfs(tt[x][i]);
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  while(scanf("%d",&n)!=EOF)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&shu[i]);
    c=cc=0;
    f[1]=1;
    for (i=2;i<=n;i++)
    {
      f[i]=1;
      for (j=1;j<i;j++)
        if (shu[j]<shu[i])
        {
          if (f[j]+1>f[i])
          {
            f[i]=f[j]+1;
            ccc=1;tt[i][ccc]=j;
          }
          else
            if (f[j]+1==f[i])
            {
              ccc++;tt[i][ccc]=j;
            }
        }
      tt[i][0]=ccc;
    }
    int mm=0;
    for (i=1;i<=n;i++)
      mm=max(mm,f[i]);
    memset(ff,0,sizeof(ff));
    memset(tu,0,sizeof(tu));
    for (i=1;i<=n;i++)
      if (f[i]==mm)
      {
        cc++;
        zhong[cc]=i;
        dfs(i);
      }  
    for (i=1;i<=n;i++)
      if (f[i]==1&&ff[i])
      {
        c++;
        qi[c]=i;
      }
    cout<<mm<<endl;
  }
  return 0;
}
    
