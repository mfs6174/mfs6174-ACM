/*
ID: mfs.dev2
PROG: theme
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
ifstream inf("theme.in");
ofstream ouf("theme.out");
const int maxlongint=2147483647;

int n,m,t,i,j,mm,tt;
int shu[5100],f[3][5100];

int max(int x,int y)
{
  return x>y?x:y;
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    inf>>shu[i];
  f[1][1]=1;
  t=1;mm=1;
  for (i=2;i<=n;i++)
  {
    tt=t;
    t=1-t;
    f[t][1]=1;
    for (j=2;j<i;j++)
    {
      f[t][j]=1;
      if ((shu[i]-shu[j])==(shu[i-1]-shu[j-1])&&((f[tt][j-1]+1)<=i-j))
        f[t][j]=f[tt][j-1]+1>f[t][j]?(f[tt][j-1]+1):f[t][j];
      if (f[t][j]>mm)
        mm=f[t][j];
    }
  }
  mm=mm<5?0:mm;
  ouf<<mm<<endl;
}

