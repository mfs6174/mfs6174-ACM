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
string tong1[1005],tong2[1005];
long long shang[1100],xia[1100],f[1100][1100],shu[1100][1100],mmd[1100][1100];
string ts;
int main()
{
  for (i=1;i<=1000;i++)
    for (j=1;j<=1000;j++)
      mmd[i][j]=maxlongint;
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(f,0,sizeof(f));
    memcpy(shu,mmd,sizeof(shu));
    cin>>n;
    for (i=1;i<=n;i++)
    {
      cin>>ts;
      cin>>ts>>shang[i];
      tong1[i]=ts;
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
      cin>>ts;
      cin>>ts>>xia[i];
      tong2[i]=ts;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
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
        if (f[i][j-1]==f[i-1][j])
        {
          if (f[i][j-1]>f[i][j])
          {
            f[i][j]=f[i][j-1];
            shu[i][j]=min(shu[i][j-1],shu[i-1][j]);
          }
          else
            if (f[i][j]==f[i][j-1])
              shu[i][j]=min(shu[i][j],min(shu[i][j-1],shu[i-1][j]));
        }
        else
        {
          if (f[i][j-1]>f[i-1][j])
          {
            if (f[i][j-1]>f[i][j])
            {
              f[i][j]=f[i][j-1];
              shu[i][j]=shu[i][j-1];
            }
            else
              if (f[i][j-1]==f[i][j])
                shu[i][j]=min(shu[i][j],shu[i][j-1]);
          }
          else
          {
            if (f[i-1][j]>f[i][j])
            {
              f[i][j]=f[i-1][j];
              shu[i][j]=shu[i-1][j];
            }
            else
              if (f[i-1][j]==f[i][j])
                shu[i][j]=min(shu[i][j],shu[i-1][j]);
          }
        }
      }
    cout<<f[n][m]<<' '<<shu[n][m]<<endl;
  }
  return 0;
}

    
