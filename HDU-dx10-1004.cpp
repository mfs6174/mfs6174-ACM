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
const int maxlongint=2147480647;

int f[1100][110];
int shu[1100];
int i,j,k,t,n,m,s,a,b,mm;

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)&&n)
  {
    scanf("%d%d%d",&b,&a,&s);
    for (i=1;i<=n;i++)
      scanf("%d",&shu[i]);
      for (j=0;j<=s;j++)
        f[0][j]=maxlongint;
    f[0][0]=0;
    for (i=1;i<=n;i++)
      for (j=0;j<=s;j++)
      {
        f[i][j]=maxlongint;
        if (f[i-1][j]!=maxlongint)
          f[i][j]=min(f[i][j],f[i-1][j]+shu[i]);
        if (j>0)
        {
          int ta=max(0,i-b);
          for (k=ta;k<=i-a;k++)
            if (f[k][j-1]!=maxlongint)
              f[i][j]=min(f[i][j],f[k][j-1]);
        }
      }
    mm=maxlongint;
    for (i=0;i<=s;i++)
      mm=min(mm,f[n][i]);
    cout<<mm<<endl;
  }
  return 0;
}
