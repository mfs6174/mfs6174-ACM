/*
ID: mfs.dev2
PROG: milk6
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
ifstream inf("milk6.in");
ofstream ouf("milk6.out");
const long long  maxlongint=2147483647;

int i,j,n,m,k;
long long d[50],vd[50],bian[1200][2];
long long tu[50][50],g[50][50],lt,mm;
bool ff[50];

long long min(long long x,long long y)
{
  return (x<y)?x:y;
}

long long  dfs(int x, long long  y,int n)//x是起点,y是当前改进量,n是点数,同时也是终点....
{
  long long  mm,t;
  int v;
  if(x == n)
    return y;
  mm = 0;
  for(v=1;v<=n;v++)
    if(g[x][v] > 0 && d[x] == d[v] + 1)
    {
      t = dfs(v,min(y-mm,g[x][v]),n);
      g[x][v] -= t;
      g[v][x] += t;
      mm += t;
      if(mm == y)return mm;
    }
  
  if(d[1] >= n) return mm;
  vd[d[x]]--;
  if(vd[d[x]] == 0)d[1] = n;
  d[x]++;
  vd[d[x]]++;
  return mm;
}

void floodfill(int x)
{
  if (ff[x])
    return;
  int i;
  ff[x]=true;
  for (i=1;i<=n;i++)
    if (g[x][i])
      floodfill(i);
}

int main()
{
  inf>>n>>m;
  for (i=1;i<=m;i++)
  {
    inf>>j>>k>>lt;
    tu[j][k]+=502000+i+502000*1001*lt;
    g[j][k]=tu[j][k];
    bian[i][0]=j;
    bian[i][1]=k;
  }
  vd[0] = n;
  while(d[1] < n)
    mm+=dfs(1,maxlongint*maxlongint,n);
  ouf<<(mm/(502000*1001))<<' '<<((mm/502000)%1001)<<endl;
  floodfill(1);
  for (i=1;i<=m;i++)
    if (ff[bian[i][0]]&&(!ff[bian[i][1]]))
      ouf<<i<<endl;
}

