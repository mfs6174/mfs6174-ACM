/*
ID: mfs6174
PROG: ti
LANG: C++
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define sf scanf
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int cao[5][2]={{0,0},{0,1},{-1,0},{0,-1},{1,0}};
int bb[5][5]={{0,0,0,0,0},{0,4,1,2,3},{0,1,2,3,4},{0,2,3,4,1},{0,3,4,1,2}};
bool tu[510][510][5],f[510][510];
int i,j,k,t,n,m,tt,zz,zu,st,ed,df;
bool fl;

void dfs(int x,int y,int z)
{
  f[x][y]=true;
  if (x==n+1&&y==ed)
  {
    return;
  }
  int i;
  for (i=1;i<=4;i++)
    if (tu[x][y][bb[z][i]])
    {
      dfs(x+cao[bb[z][i]][0],y+cao[bb[z][i]][1],bb[z][i]);
      break;
    }
}

void dfsf(int x,int y,int z)
{
  f[x][y]=true;
  if (x==0&&y==st)
  {
    fl=true;
    return;
  }
  int i;
  for (i=1;i<=4;i++)
    if (tu[x][y][bb[z][i]])
    {
      dfsf(x+cao[bb[z][i]][0],y+cao[bb[z][i]][1],bb[z][i]);
      break;
    }
}

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(tu,0,sizeof(tu));
    memset(f,0,sizeof(f));
    sf("%d%d%d%d",&n,&m,&st,&ed);
    for (i=1;i<=n;i++)
    {
      for (j=1;j<m;j++)
      {
        sf("%d",&t);
        if (!t)
        {
          tu[i][j][1]=true;
          tu[i][j+1][3]=true;
        }
      }
      if (i==n)
        continue;
      for (j=1;j<=m;j++)
      {
        sf("%d",&t);
        if (!t)
        {
          tu[i][j][4]=true;
          tu[i+1][j][2]=true;
        }
      }
    }
    st++;ed++;
    tu[1][st][2]=true;
    tu[n+1][ed][4]=true;
    dfs(1,st,4);
    fl=false;
    dfsf(n,ed,2);
    bool rr=true;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        rr=rr&&f[i][j];
    if (rr)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}

