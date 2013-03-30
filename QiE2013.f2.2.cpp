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

int i,j,k,t,n,m,mm;
int zu,zz;
int zhou[100];
int shu[100];
int kong[100],g[100][5];
int guo[10][100];

inline void jian(int &x,int y)
{
  x-=y;
  if (x<1)
    x=1;
}

inline bool pan(int x)
{
  if (kong[x]>5)
    return true;
  else
    return false;
}

void dfs(int x)
{
  mm=max(mm,x-1);
  if (x>k)
    return;
  int t=kong[g[x][1]];
  jian(kong[g[x][1]],2);
  kong[g[x][2]]+=2;
  kong[g[x][3]]+=2;
  bool flag=false;
  if (pan(g[x][2])||pan(g[x][3]))
    flag=true;
  // zhou[shu[g[x][2]]]+=1;
  // zhou[shu[g[x][3]]]+=1;
  for (int i=1;i<=guo[shu[g[x][2]]][0];i++)
  {
    if ( guo[shu[g[x][2]]][i]!=g[x][2])
    {
      kong[ guo[shu[g[x][2]]][i] ]+=1;
      if (pan(guo[shu[g[x][2]]][i]))
      {
        flag=true;
      }
    }
  }
  for (int i=1;i<=guo[shu[g[x][3]]][0];i++)
  {
    if ( guo[shu[g[x][3]]][i]!=g[x][3])
    {
      kong[ guo[shu[g[x][3]]][i] ]+=1;
      if (pan(guo[shu[g[x][3]]][i]))
      {
        flag=true;
      }
    }
  }
  if (!flag)
    dfs(x+1);
  kong[g[x][1]]=t;
  kong[g[x][2]]-=2;
  kong[g[x][3]]-=2;
  //zhou[shu[g[x][2]]]-=1;
  //zhou[shu[g[x][3]]]-=1;
  for (int i=1;i<=guo[shu[g[x][2]]][0];i++)
  {
    if ( guo[shu[g[x][2]]][i]!=g[x][2])
      kong[ guo[shu[g[x][2]]][i] ]-=1;
  }
  for (int i=1;i<=guo[shu[g[x][3]]][0];i++)
  {
    if ( guo[shu[g[x][3]]][i]!=g[x][3])
      kong[ guo[shu[g[x][3]]][i] ]-=1;
  }

  t=kong[g[x][2]];
  jian(kong[g[x][2]],2);
  kong[g[x][1]]+=2;
  kong[g[x][3]]+=2;
  flag=false;
  if (pan(g[x][1])||pan(g[x][3]))
    flag=true;
  zhou[shu[g[x][1]]]+=1;
  zhou[shu[g[x][3]]]+=1;
  for (int i=1;i<=guo[shu[g[x][1]]][0];i++)
  {
    if ( guo[shu[g[x][1]]][i]!=g[x][1])
    {
      kong[ guo[shu[g[x][1]]][i] ]+=1;
      if (pan(guo[shu[g[x][1]]][i]))
      {
        flag=true;
      }
    }
  }
  for (int i=1;i<=guo[shu[g[x][3]]][0];i++)
  {
    if ( guo[shu[g[x][3]]][i]!=g[x][3])
    {
      kong[ guo[shu[g[x][3]]][i] ]+=1;
      if (pan(guo[shu[g[x][3]]][i]))
      {
        flag=true;
      }
    }
  }
  if (!flag)
    dfs(x+1);
  kong[g[x][2]]=t;
  kong[g[x][1]]-=2;
  kong[g[x][3]]-=2;
  // zhou[shu[g[x][1]]]-=1;
  // zhou[shu[g[x][3]]]-=1;
for (int i=1;i<=guo[shu[g[x][1]]][0];i++)
  {
    if ( guo[shu[g[x][1]]][i]!=g[x][1])
      kong[ guo[shu[g[x][1]]][i] ]-=1;
  }
  for (int i=1;i<=guo[shu[g[x][3]]][0];i++)
  {
    if ( guo[shu[g[x][3]]][i]!=g[x][3])
      kong[ guo[shu[g[x][3]]][i] ]-=1;
  }

  t=kong[g[x][3]];
  jian(kong[g[x][3]],2);
  kong[g[x][1]]+=2;
  kong[g[x][2]]+=2;
  flag=false;
  if (pan(g[x][1])||pan(g[x][2]))
    flag=true;
  //zhou[shu[g[x][1]]]+=1;
  //zhou[shu[g[x][2]]]+=1;
  for (int i=1;i<=guo[shu[g[x][1]]][0];i++)
  {
    if ( guo[shu[g[x][1]]][i]!=g[x][1])
    {
      kong[ guo[shu[g[x][1]]][i] ]+=1;
      if (pan(guo[shu[g[x][1]]][i]))
      {
        flag=true;
      }
    }
  }
  for (int i=1;i<=guo[shu[g[x][2]]][0];i++)
  {
    if ( guo[shu[g[x][2]]][i]!=g[x][2])
    {
      kong[ guo[shu[g[x][2]]][i] ]+=1;
      if (pan(guo[shu[g[x][2]]][i]))
      {
        flag=true;
      }
    }
  }
  if (!flag)
    dfs(x+1);
  kong[g[x][3]]=t;
  kong[g[x][1]]-=2;
  kong[g[x][2]]-=2;
  // zhou[shu[g[x][1]]]-=1;
  // zhou[shu[g[x][2]]]-=1;
  for (int i=1;i<=guo[shu[g[x][2]]][0];i++)
  {
    if ( guo[shu[g[x][2]]][i]!=g[x][2])
      kong[ guo[shu[g[x][2]]][i] ]-=1;
  }
  for (int i=1;i<=guo[shu[g[x][1]]][0];i++)
  {
    if ( guo[shu[g[x][1]]][i]!=g[x][1])
      kong[ guo[shu[g[x][1]]][i] ]-=1;
  }

}
  
  
    
int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d%d",&n,&m,&k);
    memset(guo,0,sizeof(guo));
    for (i=0;i<n;i++)
    {
      sf("%d",&shu[i]);
      guo[shu[i]][0]++;
      guo[shu[i]][guo[shu[i]][0]]=i;
    }
    for (i=0;i<n;i++)
      sf("%d",&kong[i]);
    for (i=1;i<=k;i++)
      for (j=1;j<=3;j++)
        sf("%d",&g[i][j]);
    mm=0;
    memset(zhou,0,sizeof(0));
    dfs(1);
    pf("Case #%d: %d\n",zz,mm);
  }
  return 0;
}
