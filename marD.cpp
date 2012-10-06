
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

struct Z
{
  int zhen[105][105],n;
};

int i,j,k,t,m,n,zz,zu,tt;
bool tu[105][105];
Z chu,rr;

Z cheng(Z &x,Z &y,int n)
{
  int i,j,k;
  Z r;
  r.n=n;
  memset(r.zhen,0,sizeof(r.zhen));
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      for (k=1;k<=n;k++)
        r.zhen[i][j]=(r.zhen[i][j]+(x.zhen[i][k])*(y.zhen[k][j])%9997)%9997;
  return r;
}

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>m;
    memset(chu.zhen,0,sizeof(chu.zhen));
    memset(rr.zhen,0,sizeof(rr.zhen));
    memset(tu,0,sizeof(tu));
    chu.n=n;
    rr.n=n;
    for (i=1;i<=m;i++)
    {
      cin>>t>>tt;
      tu[t][tt]=true;
      tu[tt][t]=true;
      chu.zhen[t][tt]=1;
      chu.zhen[tt][t]=1;
      rr.zhen[t][tt]=1;
      rr.zhen[tt][t]=1;
    }
    for (i=2;i<=23;i++)
      rr=cheng(rr,chu,n);
    cin>>k;
    for (i=1;i<=k;i++)
    {
      cin>>t>>tt;
      cout<<rr.zhen[t][tt]%9997<<endl;
    }
  }
}

      
      
