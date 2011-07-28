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

int g[110][110][110][2],shu[110][110];
int i,j,k,t,n,m,mm=-maxlongint;
bool ff[110][110][110][2],fl[110][110];

void mfs(int x,int y)
{
  if (fl[x][y])
    return;
  fl[x][y]=true;
  int f[2]={-maxlongint,-maxlongint};
  int t=abs(shu[x][y]);
  if (x>1)
  {
    mfs(x-1,y);
    if (ff[x-1][y][t][1])
      f[0]=max(f[0],g[x-1][y][t][1]);//这里取max是因为，你选了这里，这里决定权给对手对手知道那个更多，当然选多的
    if (ff[x-1][y][t][0])
      f[1]=max(f[1],g[x-1][y][t][0]);
  }
  if (y>1)
  {
    mfs(x,y-1);
    if (ff[x][y-1][t][1])
      f[0]=max(f[0],g[x][y-1][t][1]);
    if (ff[x][y-1][t][0])
      f[1]=max(f[1],g[x][y-1][t][0]);
  }
  int i;
  for (i=0;i<2;i++)
    if (f[i]!=-maxlongint)
      f[i]=shu[x][y]-f[i];//这里再变－的，表示是扣去对手的
    else
      f[i]=shu[x][y];
  for (i=1;i<=100;i++)
  {
    g[x][y][i][1]=g[x][y][i][0]=-maxlongint;
    if (x>1)
    {
      if (ff[x-1][y][i][1])
      {
        ff[x][y][i][1]=true;
        g[x][y][i][1]=max(g[x][y][i][1],g[x-1][y][i][1]);//以下全取max，因为实际上是记录对手的决策，所以都是教大的
      }
      if (ff[x-1][y][i][0])
      {
        ff[x][y][i][0]=true;
        g[x][y][i][0]=max(g[x][y][i][0],g[x-1][y][i][0]);
      }
    }
    if (y>1)
    {
      if (ff[x][y-1][i][1])
      {
        ff[x][y][i][1]=true;
        g[x][y][i][1]=max(g[x][y][i][1],g[x][y-1][i][1]);
      }
      if (ff[x][y-1][i][0])
      {
        ff[x][y][i][0]=true;
        g[x][y][i][0]=max(g[x][y][i][0],g[x][y-1][i][0]);
      }
    }
    if (t>i)
    {
      if (f[0]!=-maxlongint)
      {
        g[x][y][i][0]=max(g[x][y][i][0],f[0]);
        ff[x][y][i][0]=true;
      }
      if (f[1]!=-maxlongint)
      {
        g[x][y][i][1]=max(g[x][y][i][1],f[1]);
        ff[x][y][i][1]=true;
      }
    }
  }
  mm=max(mm,f[0]);
}


int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&shu[i][j]);
    memset(ff,0,sizeof(ff));
    memset(fl,0,sizeof(fl));
    mm=-maxlongint;
    mfs(n,m);
    cout<<mm<<endl;
  }
  return 0;
}


