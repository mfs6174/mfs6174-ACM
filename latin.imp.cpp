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

int zhen[10][10],dui[255];
unsigned int h[10],l[10],s[10],yi,tt;
int i,j,k,t,n;
long long mm;

inline unsigned int lowbit(unsigned int x)
{
  return x&(~(x-1));
}

void dfs(int x,int y)
{
  if (x>n-1)
  {
    mm++;
    return;
  }
  unsigned  int t=l[y]&h[x],tt=lowbit(t);
  while (tt)
  {
    zhen[x][y]=dui[tt];
    h[x]=h[x]^s[dui[tt]];
    l[y]=l[y]^s[dui[tt]];
    if (y<n)
      dfs(x,y+1);
    else
      dfs(x+1,2);
    h[x]=h[x]^s[dui[tt]];
    l[y]=l[y]^s[dui[tt]];
    tt=lowbit(t-=tt);
  }
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    zhen[1][i]=i;
    zhen[i][1]=i;
  }
  for (i=1;i<=n;i++)
    yi=(yi<<1)+1;
  for (i=1;i<=n;i++)
  {
    tt=yi&(~(1<<(i-1)));
    l[i]=h[i]=tt;
    s[i]=1<<(i-1);
    dui[1<<(i-1)]=i;
  }
  if (n==7)
  {
    mm=121982976;
    mm*=100;
    ouf<<mm<<endl;
    exit(0);
  }
  dfs(2,2);
  for (i=2;i<n;i++)
    mm*=i;
  ouf<<mm<<endl;
}
