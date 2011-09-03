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
#include<set>
#include<vector>
#define LL long long
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

LL i,j,k,t,n,m,l,zuo,you,mid;
LL dd[600000];
bool fl;

bool check(LL x)
{
  int i,c=0,l=0;
  for (i=1;i<=n;i++)
    if (dd[i]-dd[l]<=x&&dd[i+1]-dd[l]>x)
    {
      c++;
      if (c>m)
        return false;
      l=i;
    }
  if (dd[n+1]-dd[l]<=x&&c+1<=m)
    return true;
  else
    return false;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%I64d%I64d%I64d",&l,&n,&m)!=EOF)
  {
    for (i=1;i<=n;i++)
    {
      dd[0]=0;
      scanf("%I64d",&dd[i]);
    }
    sort(&dd[1],&dd[n+1]);
    dd[n+1]=l;
    zuo=0;you=l;
    while (zuo!=you)
    {
      mid=(zuo+you)>>1;
      fl=check(mid);
      if (fl)
        you=mid;
      else
        zuo=mid+1;
    }
    cout<<zuo<<endl;
  }
  return 0;
}

      
      
