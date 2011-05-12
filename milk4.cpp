/*
ID: mfs.dev2
PROG: milk4
LANG: C++
*/

#include<fstream>
#include<algorithm>

using namespace std;
ifstream inf("milk4.in");
ofstream ouf("milk4.out");
const int maxlongint=2147483640;

struct D
{
  int a[20];
};
D f[5][20001],tt;
int wu[150];
int i,j,k,t,mm,n,m,ii;

bool min(D x,D y)
{
  int i;
  if (x.a[0]==maxlongint)
    return false;
  else if (y.a[0]==maxlongint)
    return true;
  for (i=0;i<=x.a[0];i++)
    if (x.a[i]<y.a[i])
      return true;
    else if (x.a[i]>y.a[i])
      return false;
  return true;
}

int main()
{
  inf>>m>>n;
  for (i=1;i<=n;i++)
    inf>>wu[i];
  sort(&wu[1],(&wu[n])+1);
  for (j=1;j<=m;j++)
    f[0][j].a[0]=maxlongint;
  f[0][0].a[0]=0;
  for (k=1;k<=n;k++)
  {
    i=k%2;
    ii=(k-1)%2;
    for (j=1;j<=m;j++)
      f[i][j].a[0]=maxlongint;
    f[i][0].a[0]=0;
    for (j=1;j<=m;j++)
    {
      if (j<wu[k])
        continue;
      if (j==wu[k])
      {
        f[i][j].a[0]=1;
        f[i][j].a[1]=wu[k];
      }
      else
        f[i][j]=f[i][j-wu[k]];
      if (f[ii][j-wu[k]].a[0]!=maxlongint)
      {
        tt=f[ii][j-wu[k]];
        tt.a[0]++;
        tt.a[tt.a[0]]=wu[k];
        if (!min(f[i][j],tt))
          f[i][j]=tt;
      }
    }
    for (j=1;j<=m;j++)
      if (!min(f[i][j],f[ii][j]))
        f[i][j]=f[ii][j];
  }
  n=n%2;
  ouf<<f[n][m].a[0]<<' ';
  for (i=1;i<f[n][m].a[0];i++)
    ouf<<f[n][m].a[i]<<' ';
  ouf<<f[n][m].a[f[n][m].a[0]]<<endl;
}

    
