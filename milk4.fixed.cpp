/*
ID: mfs.dev2
PROG: milk4
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
ifstream inf("milk4.in");
ofstream ouf("milk4.out");
const int maxlongint=2147483640;

int f[101][20100],wu[150],mmr[150],fl[20100];
int i,j,k,t,mm,n,m;
bool rr[101];

void dfs(int x,int y)
{
  bool t;
  if (!y)
  {
    int i,c=0;
    bool xiao=false;
    for (i=1;i<=n;i++)
      if (rr[i])
        c++;
    if (c>mm)
      return;
    c=0;
    for (i=1;i<=n;i++)
    {
      if (c>=mm)
        break;
      if (rr[i])
      {
        c++;
        if (wu[i]<mmr[c])
        {
          xiao=true;
          break;
        }
        else
          if (wu[i]>mmr[c])
            break;
      }
    }
    if (xiao)
    {
      c=0;
      for (i=1;i<=n;i++)
        if (rr[i])
        {
          c++;
          mmr[c]=wu[i];
        }
    }
    
    return;
  }
   if (x-1>=0)
     if (f[x][y]==f[x-1][y])
    {
      //t=rr[x];
      // rr[x]=false;
       dfs(x-1,y);
       // rr[x]=t;
    }
  if (y<wu[x])
    return;
  if ((x-1>=0)&&(f[x-1][y-wu[x]]!=maxlongint))
    if (f[x][y]==f[x-1][y-wu[x]]+1)
    {
      t=rr[x];
      rr[x]=true;
      dfs(x-1,y-wu[x]);
      rr[x]=t;
    }
  if (fl[x][y-wu[x]]||(f[x][y]==f[x][y-wu[x]]))
  {
    t=rr[x];
    rr[x]=true;
    dfs(x,y-wu[x]);
    rr[x]=t;
  }
  if ((f[x][y]==1)&&(y-wu[x]==0))
  {
    t=rr[x];
    rr[x]=true;
    dfs(x,0);
    rr[x]=t;
  }
}

int main()
{
  inf>>m>>n;
  for (i=1;i<=n;i++)
    inf>>wu[i];
  sort(&wu[1],(&wu[n])+1);
  for (i=0;i<=n;i++)
    for (j=1;j<=m;j++)
      f[i][j]=maxlongint;
  f[0][0]=0;
  for (i=1;i<=n;i++)
  {
    f[i][0]=0;
    for (j=1;j<=m;j++)
    {
      if (j<wu[i])
        continue;
      if (j==wu[i])
        f[i][j]=min(f[i][j],1);
      else
        f[i][j]=min(f[i][j],f[i][j-wu[i]]);
      if (f[i-1][j-wu[i]]!=maxlongint)
        f[i][j]=min(f[i][j],f[i-1][j-wu[i]]+1);
    }
    for (j=1;j<=m;j++)
      fl[j]=min(fl[j],f[i][j]);
  }
  mm=maxlongint;
  for (i=1;i<=140;i++)
    mmr[i]=maxlongint;
  for (i=1;i<=n;i++)
    mm=min(mm,f[i][m]);
  for (i=1;i<=n;i++)
    if (f[i][m]==mm)
    {
      memset(rr,0,sizeof(rr));
      dfs(i,m);
    }
  ouf<<mm<<' ';
  for (i=1;i<mm;i++)
    ouf<<mmr[i]<<' ';
  ouf<<mmr[mm]<<endl;
}

    
