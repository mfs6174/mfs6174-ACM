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

long long i,j,k,n,m,t,p,zz,zu,a,b;
long long f[30][12][2][2],g[30][12];
string s,ss,xian;
  
int main()
{
  for (i=0;i<=9;i++)
    f[1][i]=xx1;
  g[1][0]=1;
  for (i=1;i<=9;i++)
    for (j=i;j<=9;j++)
      for (k=1;k<j;k++)
        f[i][j]+=f[i-1][k];
  for (i=1;i<=10;i++)
    for (j=i-1;j<=9;j++)
      for (k=1;k<j;k++)
        g[i][j]+=g[i-1][k];
  for (i=3;i<=20;i++)
    for (j=1;j<=i;j++)
      for (k=0;k<=9;k++)
        shu[i]+=(f[j][k]*g[i+1-j][k]);
  // for (p=1;p<=9;p++)
  // {
  //   memset(d,0,sizeof(d));
  //   d[1][p]=1;
  //   for (i=1;i<=9;i++)
  //     for (j=i;j<=9;j++)
  //       for (k=1;k<j;k++)
  //         d[i][j]+=d[i-1][k];
  //   for (i=3;i<=20;i++)
  //     for (j=1;j<=i;j++)
  //       for (k=0;k<=9;k++)
  //         dd[p][i]+=(d[j][k]*g[i+1-j][k]);
  // }
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>s>>ss;
    long long mm=0;
    if (abs(ss.size()-s.size())>1)
      for (i=s.size()+1;i<ss.size();i++)
        mm+=shu[i];
    if (s.size()==ss.size())
    {
      dfs(s,ss);
    }
    else
    {
    }
    cout<<"Case #"<<zz<<": "<<mm<<endl;
  }
  return 0;
}

    
