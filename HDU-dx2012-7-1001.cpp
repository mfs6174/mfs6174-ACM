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
const llg maxlongint=(llg)2147483647*2147483647;


llg i,j,k,t,n,m,mm,dang;
llg shu[320][320],mask[320][320];
llg h[2][330];
// struct P
// {
//   llg x,m;
// };

void dfs(queue<llg> q)
{
  if (q.empty())
  {
    mm=min(dang,mm);
    return;
  }
  if (dang>=mm)
    return;
  while (1)
  {
    if (q.empty())
    {
      mm=min(dang,mm);
      return;
    }
    llg t=q.front();
    q.pop();
    if (h[0][t]!=h[1][t])
      break;
  }
  if (h[0][t]<h[1][t])
  {
    for (int i=2;i<=n;i++)
    {
      if (mask[i][t])
        continue;
      mask[i][t]=1;
      h[1][i]++;
      h[0][t]++;
      dang+=shu[i][t];
      if (i<n)
        q.push(i);
      dfs(q);
      h[1][i]--;
      h[0][t]--;
      mask[i][t]=0;
      dang-=shu[i][t];
    }
  }
  else
  {
    for (int i=1;i<n;i++)
    {
      if (mask[t][i])
        continue;
      mask[t][i]=1;
      h[1][t]++;
      h[0][i]++;
      dang+=shu[t][i];
      if (i>1)
        q.push(i);
      dfs(q);
      h[1][t]--;
      h[0][i]--;
      mask[t][i]=0;
      dang-=shu[t][i];
    }
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%lld",&n)!=EOF)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        sf("%lld",&shu[i][j]);
    mm=maxlongint;
    for (i=2;i<=n;i++)
      for (j=1;j<=n-1;j++)
      {
        queue<llg> q;
        while (!q.empty()) q.pop();
        memset(h,0,sizeof(h));
        memset(mask,0,sizeof(mask));
        dang=shu[1][i];
        h[0][i]=1;
        h[1][j]=1;
        if (i>1&&i<n)
          q.push(i);
        if (j>1&&j<n)
          q.push(j);
        if (!(1==j&&i==n))
          dang+=shu[j][n];
        mask[1][i]=mask[j][n]=1;
        if (dang>mm)
          continue;
        dfs(q);
      }
    cout<<mm<<endl;
  }
  return 0;
}
        
  
  
