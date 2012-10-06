/*
ID: mfs.dev2
PROG: bigbrn
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
ifstream inf("bigbrn.in");
ofstream ouf("bigbrn.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,mm;
int f[1005][1005],ff[1005][1005][2];
bool tu[1005][1005]; 

int main()
{
  inf>>n>>m;
  for (i=1;i<=m;i++)
  {
    inf>>t>>j;
    tu[t][j]=true;
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (tu[i][j-1])
      {
        ff[i][j][0]=1;
        ff[i][j-1][0]=0;
      }
      else
        ff[i][j][0]=ff[i][j-1][0]+1;
      if (tu[j-1][i])
      {
        ff[j][i][1]=1;
        ff[j-1][i][1]=0;
      }
      else
        ff[j][i][1]=ff[j-1][i][1]+1;
    }
  for (i=1;i<=n;i++)
  {
    f[1][i]=1;
    f[i][1]=1;
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      f[i][j]=min(f[i-1][j-1]+1,min(ff[i][j][0],ff[i][j][1]));
      mm=max(mm,f[i][j]);
    }
  ouf<<mm<<endl;
}

    

