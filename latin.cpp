/*
ID: mfs.dev2
PROG: latin
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
ifstream inf("latin.in");
ofstream ouf("latin.out");
const int maxlongint=2147483647;

bool ff[10][10],fff[10][10];
int zhen[10][10];
int i,j,k,t,n;
long long mm;

void dfs(int x,int y)
{
  if (x>n)
  {
    mm++;
    return;
  }
  for (int i=1;i<=n;i++)
    if (!(ff[y][i]||fff[x][i]))
    {
      ff[y][i]=true;
      fff[x][i]=true;
      zhen[x][y]=i;
      if (y<n)
        dfs(x,y+1);
      else
        dfs(x+1,2);
      ff[y][i]=false;
      fff[x][i]=false;
    }
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    zhen[1][i]=i;
    zhen[i][1]=i;
    ff[i][i]=true;
    fff[i][i]=true;
  }
  dfs(2,2);
  for (i=2;i<n;i++)
    mm*=i;
  cout<<mm<<endl;
}
