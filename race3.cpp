/*
ID: mfs.dev2
PROG: race3
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
ifstream inf("race3.in");
ofstream ouf("race3.out");
const int maxlongint=2147483647;

int tu[60][60],zhong[60],fen[60];
int i,j,m,n,t,c;
bool f[60],ff[60],zhan[60],s;

bool dfs(int x)
{
  int i,t=true;
  if (((!s)&&(x==n))||(s&&ff[x]))
    return false;
  if (f[x]&&(!s))
    return true;
  zhan[x]=true;
  if (!s)
    ff[x]=true;
  for (i=1;i<=tu[x][0];i++)
    if (!zhan[tu[x][i]])
        t=t&&dfs(tu[x][i]);
  return t;
}

int main()
{
  inf>>t;
  while (t!=-1)
  {
    while (t!=-2)
    {
      tu[n][0]++;
      tu[n][tu[n][0]]=t;
      inf>>t;
    }
    n++;
    inf>>t;
  }
  n--;
  for (i=1;i<n;i++)
  {
    f[i-1]=false;
    f[i]=true;
    memset(zhan,0,sizeof(zhan));
    memset(ff,0,sizeof(ff));
    s=false;
    if (dfs(0))
    {
      m++;
      s=true;
      memset(zhan,0,sizeof(zhan));
      zhong[m]=i;
      if (dfs(i))
      {
        c++;
        fen[c]=i;
      }
    }
  }
  ouf<<m;
  for (i=1;i<=m;i++)
    ouf<<' '<<zhong[i];
  ouf<<endl<<c;
  for (i=1;i<=c;i++)
    ouf<<' '<<fen[i];
  ouf<<endl;
}
