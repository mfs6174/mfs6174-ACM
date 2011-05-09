#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
ifstream inf("ti1.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647,sudu=70,shi=10,k1=2,k2=3;

int n,m,i,j,k,t,mm,tt,cc;
int tu[100][100],zhen[100][100],zhong[100][100],he[100][100],ren[100],che[100][100][4];

void floyd(int n)
{
  int i,j,k;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        zhen[i][j]=0;
      zhen[i][j]=maxlongint;
      if (tu[i][j])
        zhen[i][j]=tu[i][j];
      zhong[i][j]=i;
    }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        if ((zhen[i][k]==maxlongint)||(zhen[k][j]==maxlongint))
          continue;
        if (zhen[i][k]+zhen[k][j]<zhen[i][j])
        {
          zhen[i][j]=zhen[i][k]+zhen[k][j];
          zhong[i][j]=k;
        }
      }
}

int tongji(int n)
{
  int i,j,k,d,w;
  mm=maxlongint;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        continue;
      for (k=1;k<=n;k++)
      {
        if (zhen[i][k]<zhen[j][k])
        {
          d=i;
          w=1;
        }
        else
        {
          d=j;
          w=2;
        }
        if (zhen[d][k]<=sudu*shi)
          he[i][j]+=zhen[d][k]*ren[k]*k1;
        else
          he[i][j]+=zhen[d][k]*ren[k]*k2;
        che[i][j][w]+=ren[k];
      }
      cc=0;
      for (int ww=1;ww<=2;ww++)
        cc+=(che[i][j][ww]+46)/47;
      if ((cc<=54)&&(he[i][j]<mm))
      {
        mm=he[i][j];
        t=i;
        tt=j;
      }
    }
  return mm;
}

int main()
{
  n=50;
  for (i=1;i<=n;i++)
  {
    inf>>t>>tt;
    ren[t]=tt;
  }
  while (inf>>i>>j>>k)
  {
    tu[i][j]=tu[j][i]=k;
  }
  floyd(n);
  tongji(n);
  ouf<<t<<' '<<tt<<' '<<mm<<' '<<cc<<endl;
//   for (i=1;i<=n;i++)
//     ouf<<i<<' '<<he[i]<<endl;
  return 0;
}

