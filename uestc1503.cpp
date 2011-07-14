/*
ID: mfs.dev2
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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,n,m,t,mm;
bool f[43][43][43][43];
int dui[6][45],shu[6][45][20];

void dfs(int a,int b,int c,int d,int s,int q)
{
  if (f[a][b][c][d])
    return;
  int t,tt;
  f[a][b][c][d]=true;
  mm=max(mm,s);
  if (q>=5)
    return;
  if (a<=n)
  {
    tt=dui[1][a];
    t=shu[1][a-1][tt]+shu[2][b-1][tt]+shu[3][c-1][tt]+shu[4][d-1][tt];
    t=t%2;
    if (t==1)
      dfs(a+1,b,c,d,s+1,q-1);
    else
        dfs(a+1,b,c,d,s,q+1);
  }
  if (b<=n)
  {
    tt=dui[2][b];
    t=shu[1][a-1][tt]+shu[2][b-1][tt]+shu[3][c-1][tt]+shu[4][d-1][tt];
    t=t%2;
    if (t==1)
      dfs(a,b+1,c,d,s+1,q-1);
    else
        dfs(a,b+1,c,d,s,q+1);
  }
  if (c<=n)
  {
    tt=dui[3][c];
    t=shu[1][a-1][tt]+shu[2][b-1][tt]+shu[3][c-1][tt]+shu[4][d-1][tt];
    t=t%2;
    if (t==1)
      dfs(a,b,c+1,d,s+1,q-1);
    else
        dfs(a,b,c+1,d,s,q+1);
  }
  if (d<=n)
  {
    tt=dui[4][d];
    t=shu[1][a-1][tt]+shu[2][b-1][tt]+shu[3][c-1][tt]+shu[4][d-1][tt];
    t=t%2;
    if (t==1)
      dfs(a,b,c,d+1,s+1,q-1);
    else
        dfs(a,b,c,d+1,s,q+1);
  }
}

  
  
int main()
{
  cin>>n;
  while (n)
  {
    mm=0;
    memset(f,0,sizeof(f));
    memset(shu,0,sizeof(shu));
    for (i=1;i<=n;i++)
      for (j=1;j<=4;j++)
      {
        for (k=1;k<=20;k++)
          shu[j][i][k]=shu[j][i-1][k];
        cin>>dui[j][i];
        shu[j][i][dui[j][i]]++;
      }
    dfs(1,1,1,1,0,0);
    cout<<mm<<endl;
    cin>>n;
  }
  return 0;
}




    
