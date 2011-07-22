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
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const long long maxlongint=2147483647;
const long long maxn=11000000;

long long ff[maxn];
long long j,t,i,n,m,l,r,f[1100000][32];


void rmqchuli(long long x)
{
  long long i,j,t=(long long)(log((double)x)/log(2.0));
	for (j=1;j<=t;j++)
      for (i=x-(1<<j)+1;i>=1;i--)
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

long long cha(long long x,long long y)
{
	long long k;
	k=(long long)(log((double)(y-x+1))/log(2.0));
	return max(f[x][k],f[y-(1<<k)+1][k]);
}

long long dfs(long long x)
{
  long long t;
  if (x<maxn&&ff[x])
    return ff[x];
  if (x&1)
    t=dfs(3*x+1)+1;
  else
    t=dfs(x/2)+1;
  if (x<maxn)
    ff[x]=t;
  if (x<=1000010)
    f[x][0]=ff[x];
  return t;
}

int main()
{
  ff[1]=1;
  f[1][0]=1;
  for (i=2;i<=1000010;i++)
    dfs(i);
  rmqchuli(1000010);
  while (cin>>i>>j)
  {
    int ii,jj;
    jj=max(i,j);ii=min(i,j);
    cout<<i<<' '<<j<<' '<<cha(ii,jj)<<endl;
  }
  return 0;
}

    

