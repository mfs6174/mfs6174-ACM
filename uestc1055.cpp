/*
ID: mfs6174
PROG: uestc 1055 set dp
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
#include<iomanip>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,m,n,t,zu,zz;
double dui[20][20],mm,f[18][200000];
bool ff[18][200000];
unsigned tt;

void mfs(int x,unsigned d)
{
  int i;
  if (x<1)
    return;
  if (ff[x][d])
    return;
  ff[x][d]=true;
  if (!(d&(1<<(x-1))))
  {
    mfs(x-1,d);
    f[x][d]=max(f[x][d],f[x-1][d]);
    return;
  }
  unsigned t=d&(~(1<<(x-1)));
  for (i=1;i<=n;i++)
  {
    unsigned tt;
    if (!(d&(1<<(i-1))))
      continue;
    tt=t&(~(1<<(i-1)));
    mfs(x-1,tt);
    f[x][d]=max(f[x][d],f[x-1][tt]+dui[x][i]);
  }
}

  
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        cin>>dui[i][j];
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    tt=1;
    for (i=2;i<=n;i++)
    {
      tt=tt<<1;
      tt=tt|1;
    }
    mfs(n,tt);
    mm=0;
    for (i=0;i<=n;i++)
      mm=max(mm,f[n][tt]);
    cout<<fixed<<setprecision(2)<<mm<<endl;
  }
  return 0;
}


