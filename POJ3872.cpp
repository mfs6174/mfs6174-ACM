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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long i,j,k,t,n,m,zz,zu;
long long shu[110000],dao[110000],f[110000],wei[110000];

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}


int main()
{
  freopen("ti.in","r",stdin);
  scanf("%lld",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(wei,0,sizeof(wei));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      t=get();
      if (wei[t]==0)
      {
        wei[t]=i;
        dao[i]=0;
      }
      else
      {
        dao[i]=wei[t];
        wei[t]=i;
      }
    }
    for (i=1;i<=n;i++)
      shu[i]=get();
    
