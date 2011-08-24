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

int i,j,k,t,n,m;
int shu[15][15];
string ss;
bool ff[15];

void dfs(int x)
{
  int i;
  if (ff[x])
    return;
  ff[x]=true;
  ss.push_back(x+48);
  if (shu[x][k])
    printf("%s\n",ss.c_str());
  for (i=k;i<n;i++)
    if (shu[x][i])
      dfs(i);
  ss.erase(ss.end()-1);
  ff[x]=false;
}

int main()
{
  freopen("ti.in","r",stdin);
  while(scanf("%d",&n)!=EOF)
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        scanf("%d",&shu[i][j]);
    for (i=0;i<n;i++)
    {
      memset(ff,0,sizeof(ff));
      k=i;
      dfs(i);
    }
    printf("\n");
  }
  return 0;
}
    

