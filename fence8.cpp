/*
ID: mfs.dev2
PROG: fence8
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
ifstream inf("fence8.in");
ofstream ouf("fence8.out");

int hh,ss,n,m,i,j,t,cai[55],xu[1100],mm,he[1100];
bool ff=false;

void sort(int a[],int n,int x)
{
  int i,j;
  for (i=1;i<n;i++)
    for (j=i;j<=n;j++)
      if ((x)?(a[j]<a[i]):(a[j]>a[i]))
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
}

bool dfs(int x,int q)
{
  if (ff||(x<1))
    return true;
  int t,i;
  hh=0;
  ss=0;
  for (i=1;i<=n;i++)
  {
    if (cai[i]>=xu[1])
    {
      hh+=cai[i];
      ss+=cai[i]/xu[1];
    }
  }
  if (x-ss>0)
  {
    return false;
  }
  if (hh<he[x])
  {
    return false;
  }
  // if (ma[x][maxx>xu[m]?xu[m]:maxx]+x-1<=mm)
  for (i=1;i<=n;i++)
  {
    if ((cai[i]<xu[x])||(cai[i]==cai[i-1])||((xu[x]==xu[x+1])&&(i<q)))
      continue;
    t=cai[i];
    cai[i]-=xu[x];
    if (dfs(x-1,i))
    {
      ff=true;
      return true;
    }
    cai[i]=t;
  }
  return false;
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    inf>>cai[i];
  inf>>m;
  for (i=1;i<=m;i++)
    inf>>xu[i];
  sort(cai,n,0);
  sort(xu,m,1);
  for (i=1;i<=m;i++)
  {
    he[i]=he[i-1]+xu[i];
  }
  for (i=m;i>=1;i--)
    if (dfs(i,1))
    {
      mm=i;
      break;
    }
  ouf<<mm<<endl;
}

