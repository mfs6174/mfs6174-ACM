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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int sg[1200];
int i,j,k,t,n,m,zz,zu;

void gsg(int x)
{
  if (sg[x]!=-1)
    return;
  bool ff[1200];
  memset(ff,0,sizeof(ff));
  gsg(x-m);
  ff[sg[x-m]]=true;
  int tt=x-m,t=tt/2,i;
  for (i=1;i<=t;i++)
  {
    gsg(i);
    gsg(tt-i);
    int tsg=sg[i]^sg[tt-i];
    ff[tsg]=true;
  }
  for (i=0;i<=n+1;i++)
    if (!ff[i])
    {
      sg[x]=i;
      return;
    }
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&n,&m);
    memset(sg,-1,sizeof(sg));
    for (i=0;i<m;i++)
      sg[i]=0;
    for (i=m;i<=n;i++)
      gsg(i);
    if (n<m)
      printf("Case #%d: abcdxyzk\n",zz);
    else
    {
      if (sg[n-m]==0)
        printf("Case #%d: aekdycoin\n",zz);
      else
        printf("Case #%d: abcdxyzk\n",zz);
    }
  }
  return 0;
}
