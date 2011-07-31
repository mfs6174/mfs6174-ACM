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
#include<iomanip>
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;
const int mod=100000000;
int f[150][12][150][2];
int a[150],b[150];
bool ff[150][12][150][2];
int i,j,k,t,n,m,p,l,ra,rb;
string s,sa,sb;

inline bool check(int p,int x,int y)
{
  if (!p)
    return true;
  if (s[p-1]=='/')
    return y>x;
  if (s[p-1]=='-')
    return x==y;
  return y<x;
}

void dfs(int x,int y,int g,int p)
{
  if (ff[x][y][g][p])
    return;
  ff[x][y][g][p]=true;
  if (!g)
  {
    if (!y)
      f[x][y][g][p]=1;
    return;
  }
  if (x==1)
  {
    if (p)
    {
      if (y<a[1])
      {
        if (g==0&&y==0)
          f[x][y][g][p]=1;
        if (g==1&&y!=0)
          f[x][y][g][p]=1;
      }
    }
    else
      if (y==a[1]&&g==1)
        f[x][y][g][p]=1;
    return;
  }
  if (!p)
  {
    if (check(g,a[x-1],y))
    {
      if (g==1||s[g-1]!=s[g-2])
      {
        dfs(x-1,a[x-1],g,p);
        f[x][y][g][p]=(f[x][y][g][p]+f[x-1][a[x-1]][g][p])%mod;
      }
      if (g-1>0)
      {
        dfs(x-1,a[x-1],g-1,p);
        f[x][y][g][p]=(f[x][y][g][p]+f[x-1][a[x-1]][g-1][p])%mod;
      }
    }
  }
  else
  {
    int i;
    for (i=0;i<10;i++)
    {
      if (check(g,i,y))
      {
        if (g==1||s[g-1]!=s[g-2])
        {
          dfs(x-1,i,g,1);
          f[x][y][g][p]=(f[x][y][g][p]+f[x-1][i][g][1])%mod;
        }
        if (g-1>=0)
        {
          dfs(x-1,i,g-1,1);
          f[x][y][g][p]=(f[x][y][g][p]+f[x-1][i][g-1][1])%mod;
        }
      }
      
    }
    if (y<a[x])
    {
      if (check(g,a[x-1],y))
      {
        if (g==1||s[g-1]!=s[g-2])
        {
          dfs(x-1,a[x-1],g,0);
          f[x][y][g][p]=(f[x][y][g][p]+f[x-1][a[x-1]][g][0])%mod;
        }
        if (g-1>0)
        {
          dfs(x-1,a[x-1],g-1,0);
          f[x][y][g][p]=(f[x][y][g][p]+f[x-1][a[x-1]][g-1][0])%mod;
        }
      } 
    }
  }
}

int main()
{
  while (inf>>s>>sa>>sb)
  {
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    l=sa.size();p=sb.size();m=s.size();
    ra=rb=0;
    for (i=0;i<l;i++)
      a[i+1]=sa[i]-'0';
    for (i=0;i<p;i++)
      b[i+1]=sb[i]-'0';
    a[l]--;
    for (i=0;i<10;i++)
    {
      if (i==a[l])
        dfs(l,i,m,0);
      dfs(l,i,m,1);
      ra+=f[l][i][m][0]+f[l][i][m][1];
    }
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    l=p;
    for (i=1;i<=l;i++)
      a[i]=b[i];
    for (i=0;i<10;i++)
    {
      if (i==a[l])
        dfs(l,i,m,0);
      dfs(l,i,m,1);
      rb+=f[l][i][m][0]+f[l][i][m][1];
    }
    cout<<setfill('0')<<setw(8)<<((((rb-ra)%mod)+mod)%mod)<<endl;
    //cout<<rb-ra<<endl;
  }
  return 0;
}

