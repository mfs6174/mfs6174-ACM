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
#define LL long long
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

LL shu[110000];
LL i,j,k,t,n,m,tt,a,b,zu,zz;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%I64d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    for (i=1;i<=n;i++)
      scanf("%I64d",&shu[i]);
    tt=0;
    tt=a+b;
    for (i=2;i<=n;i++)
    {
      t=min(a*2+b,(shu[i]-shu[i-1])*b);
      tt+=t;
    }
    tt+=a;
    printf("Case #%I64d: %I64d\n",zz,tt);
  }
  return 0;
}

  


