
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
const int maxlongint=2147483000;

int f[50][5],g[50][5],tt[50][5],wei[50],shi[50];
int i,j,k,t,m,n,zz;

inline int d(int x,int y)
{
  return abs(wei[x]-wei[y]);
}

int main()
{
  wei[0]=0;
  cin>>n;
  while (n)
  {
    for (i=1;i<=n;i++)
      cin>>wei[i]>>shi[i];
    for (i=1;i<=n+1;i++)
      for (j=0;j<=3;j++)
      {
        f[i][j]=maxlongint;
        g[i][j]=maxlongint;
      }
    memset(tt,0,sizeof(tt));
    if (wei[1]>shi[1])
    {
      cout<<"NG "<<1<<endl;
      cin>>n;
      continue;
    }
    f[1][1]=wei[1];
    bool ff=true;
    for (i=2;i<=n;i++)
    {
      for (j=0;j<=3;j++)
      {
        if (f[i-1][j]<maxlongint)
          g[i-1][j]=f[i-1][j]+d(0,i-1);
        tt[i-1][j]=shi[i-1]+wei[i-1]*(j+1);
        if ((tt[i-1][j]+wei[i]<=shi[i])&&(g[i-1][j]<maxlongint))
          f[i][1]=min(f[i][1],g[i-1][j]+wei[i]);
      }
      for (j=2;j<=3;j++)
        if ((f[i-1][j-1]<maxlongint)&&(shi[i-1]+d(i,i-1)*j<=shi[i]))
          f[i][j]=f[i-1][j-1]+d(i,i-1);
      bool fff=false;
      for (j=1;j<=3;j++)
        if (f[i][j]<maxlongint)
        {
          fff=true;
          break;
        }
      if (!fff)
      {
        cout<<"NG "<<i<<endl;
        ff=false;
        break;
      }
    }
    if (ff)
      cout<<"OK "<<min(min(f[n][1],f[n][2]),f[n][3])+wei[n]<<endl;
    cin>>n;
  }
}

  

