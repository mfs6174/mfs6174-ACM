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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
#define INF (1LL<<62)
const int maxlongint=2147483647;

int i,j,k,t,n,m;
int zz,zu;
int d[50000];
int ss[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
llg rr;
void dfs(int now,int k,llg s,int lst)
{
  // if((rr!=-1 && s>rr) || now>13)
  //   return;
  // if(k==1 && (rr==-1 || rr>s))
  // {
  //   rr=s;
  //   return;
  // }
  // llg a=s;
  // int i;
  // for(i=0;i<lst;i++)
  // {
  //   if (a>INF/ss[now])
  //     break;
  //   a*=ss[now];
  // }
  // for(int j=2;j<=i+1;j++)
  //   if(k%j==0)
  //   {
  //     llg a=1;
  //     for(int _=1;_<j;_++) a=a*ss[u];
  //     dfs(u+1,k/j,s*a,j-1);
  //   }
  if((rr!=-1 && s>rr) || now>13)
    return;
  if(k==1 && (rr==-1 || rr>s))
  {
    rr=s;
    return;
  }
  for (int i=lst;i>=1;i--)
  {
    int a=1;
    if (k%(i+1)!=0)
      continue;
    for (int j=1;j<=i;j++)
      a*=ss[now];
    dfs(now+1,k/(i+1),s*a,i);
  }
}
int main()
{
  freopen("ti.in","r",stdin);
  for(int i=1;i<48000;i++)
  {
    int sum=0,j;
    for(j=1;j*j<i;j++)
      if(!(i%j))
        sum+=2;
    sum+=(i%j==0);
    if(i-sum>47777)
      continue;
    if(d[i-sum]==0)
      d[i-sum]=i;
    else
      d[i-sum]=min(d[i-sum],i);
  }
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&m,&k);
    if(m)
    {
      if(! d[k]) printf("Case %d: Illegal\n",zz);
      else printf("Case %d: %d\n",zz,d[k]);
    }
    else
    {
      rr=-1;
      dfs(0,k,1,62);
      if(rr==-1) printf("Case %d: INF\n",cs);
      else printf("Case %d: %I64d\n",cs,rr);
    }
  }
  return 0;
}
