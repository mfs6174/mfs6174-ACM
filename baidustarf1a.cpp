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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long  f[3005][3005][2],zuo[3005][3005],you[3005][3005],a[3005],b[3005],hez[3005],hey[3005];
long long  i,j,k,n,m,t;

int main()
{
  cin>>n;
  for (i=1;i<=n;i++)
  {
    cin>>a[i]>>b[i];
    hez[i]=hez[i-1]+a[i];
    hey[i]=hey[i-1]+b[i];
  }
  hez[n+1]=hez[n];
  hey[n+1]=hey[n];
  for (i=0;i<=n+1;i++)
    for (j=i+1;j<=n+1;j++)
    {
      zuo[i][j]=zuo[i][j-1]+hez[j-1]-hez[i];
      you[i][j]=you[i][j-1]+hey[j-1]-hey[i];
    }
  for (i=1;i<=n+1;i++)
  {
    for (j=0;j<i-1;j++)
    {
      f[i][j][0]=f[i-1][j][0];
      f[i][j][1]=f[i-1][j][1];
    }
    for (j=0;j<i-1;j++)
    {
      f[i][i-1][0]=max(f[i][i-1][0],f[i-1][j][1]+zuo[j][i]);
      f[i][i-1][1]=max(f[i][i-1][1],f[i-1][j][0]+you[j][i]);
    }
  }
  long long  mm=0;
  for (i=0;i<n+1;i++)
    mm=max(mm,max(f[n+1][i][0],f[n+1][i][1]));
  cout<<mm<<endl;
  return 0;
}
