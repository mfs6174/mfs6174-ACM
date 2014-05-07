/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

llg zz,zu,n,r;
const llg mod=1000000007;
llg ff[5][200];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    r=0;
    llg m=n+1;
    memset(ff,0,sizeof(ff));
    for (llg i=1;i<=n;i++)
    {
      for (llg j=1;j<=i-1;j++)
        for (llg k=1;k<=j-1;k++)
        {
          llg t= ( (( (m-i)%mod) *( (m-j)%mod) )%mod )*( (m-k)%mod)%mod;
          r=(r+t*6%mod)%mod;
        }
      llg t= ( (( (m-i)%mod) *( (m-i)%mod) )%mod )*( (m-i)%mod)%mod;
      r=(r+t)%mod;
    }
    printf("Case %lld: %lld\n",zz,r);
  }
  return 0;
}
      
          
