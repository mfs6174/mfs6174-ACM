/*
ID: mfs.dev2
PROG: ditch
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
ifstream inf("ditch.in");
ofstream ouf("ditch.out");
const int maxlongint=2147483647;

const int maxm=205;
int g[maxm][maxm];//,c[maxm][maxm],f[maxm][maxm];
int m,n,mm,i,j,k,t;
int vd[maxm],d[maxm];

int min(int x,int y)
{
  return x<y?x:y;
}

int dfs(int x, int y,int n)
{
  int mm,v,t;
  if(x == n )
    return y;
  mm = 0;
  for(v=1;v<=n;v++)
    if(g[x][v] > 0 && d[x] == d[v] + 1)
    {
      t = dfs(v,min(y-mm,g[x][v]),n);
      g[x][v] -= t;
      g[v][x] += t;
      //if(c[x][v] > 0)f[x][v] += t;
      //else f[v][x] -= t;
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

int main()
{
  inf>>n>>m;
  for (i=1;i<=n;i++)
  {
    inf>>j>>k>>t;
    g[j][k]+=t;
  }
  vd[0] = m;
  while(d[1] < m)
    mm+=dfs(1,maxlongint,m);
  ouf<<mm<<endl;
  return 0;
}
