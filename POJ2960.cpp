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

int i,j,k,t,n,m,z;
unsigned sg[11000];
unsigned rr;
int ss[120];

void gsg(int x)
{
  bool hash[11000];
  memset(hash,0,sizeof(hash));
  int i;
  for (i=1;i<=k;i++)
    if (x-ss[i]>=0)
      hash[sg[x-ss[i]]]=true;
  for (i=0;i<10001;i++)
    if (!hash[i])
    {
      sg[x]=i;
      break;
    }
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&k)!=EOF&&k)
  {
    for (i=1;i<=k;i++)
      scanf("%d",&ss[i]);
    memset(sg,0,sizeof(sg));
    sg[0]=0;
    for (i=1;i<=10001;i++)
      gsg(i);
    scanf("%d",&m);
    for (z=1;z<=m;z++)
    {
      rr=0;
      scanf("%d",&n);
      for (i=1;i<=n;i++)
      {
        scanf("%d",&t);
        rr=rr^sg[t];
      }
      if (rr)
        cout<<'W';
      else
        cout<<'L';
    }
    cout<<endl;
  }
  return 0;
}

