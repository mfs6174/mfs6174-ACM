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

int i,j,k,n,m,t,zu,zz;
map<int,string> tong1,tong2;
long long shang[1100],xia[1100],f[1100][1100],shu[1100][1100],mmd[1100][1100];
string ts;
int main()
{
  for (i=1;i<=1000;i++)
    for (j=1;j<=1000;j++)
      mmd[i][j]=maxlongint;
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(f,0,sizeof(f));
    memcpy(shu,mmd,sizeof(shu));
    inf>>n;
    for (i=1;i<=n;i++)
    {
      inf>>ts;
      inf>>ts>>shang[i];
      tong1[i]=ts;
    }
    inf>>m;
    for (i=1;i<=m;i++)
    {
      inf>>ts;
      inf>>ts>>xia[i];
      tong2[i]=ts;
    }
    for (i=1;i<=m;i++)
      if (tong1[1]==tong2[i])
      {
        f[1][i]=shang[1]+xia[i];
        shu[1][i]=1;
      }
      else
      {
        f[1][i]=0;
        shu[1][i]=0;
      }
    for (i=1;i<=n;i++)
      if (tong2[1]==tong1[i])
      {
        f[i][1]=shang[i]+xia[1];
        shu[i][1]=1;
      }
      else
      {
        f[i][1]=0;
        shu[i][1]=0;
      }
    for (i=2;i<n;i++)
      for (j=2;j<=m;j++)
      {
        if (tong1[i]==tong2[j])
        {
          long long tt=f[i-1][j-1]+shang[i]+xia[j];
          if (tt>f[i][j])
          {
            f[i][j]=tt;
            shu[i][j]=shu[i-1][j-1]+1;
          }
          else
            if (tt==f[i][j])
              shu[i][j]=min(shu[i][j],shu[i-1][j-1]);
        }
        else
        {
          if (f[i][j-1]==f[i-1][j])
          {
            f[i][j]=f[i][j-1];
            shu[i][j]=min(f[i][j-1],f[i-1][j]);
          }
          else
          {
            if (f[i][j-1]>f[i-1][j])
            {
              f[i][j]=f[i][j-1];
              shu[i][j]=shu[i][j-1];
            }
            else
            {
              f[i][j]=f[i-1][j];
              shu[i][j]=shu[i-1][j];
            }
          }
        }
      }
    cout<<f[n][m]<<' '<<shu[n][m]<<endl;
  }
  return 0;
}

    
