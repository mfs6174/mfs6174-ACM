/*
  LANG:C++
  PROB:milk6
*/
#include <iostream>
#include <string.h>
#include<cstdio>
using namespace std;
#define int64 long long 
int64 n,m;
struct edge
{
  int64 x,y,f;
}e[200001];
int64 c[1100][1100];
int64 c2[1100][1100];
int64 ans[200001];
void init()
{
  //freopen("milk6.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  int cc=0;
  for(int i=1;i<=m;i++)
  {
    int64 x,y,z,t;
    scanf("%lld%lld%lld%lld",&x,&y,&z,&t);
    x++;y++;
    cc++;
    e[cc].x=x;
    e[cc].y=y;
    e[cc].f=z*100001+1;
    c[x][y]+=z*100001+1;
    if (t==1)
    {
      cc++;
      e[cc].x=y;
      e[cc].y=x;
      e[cc].f=z*100001+1;
      c[y][x]+=z*100001+1;
    }
  }
}
class NETFLOW
{
public:
  int64 vh[100],h[100];
  int64 ans;
  int64 flow;
  bool found;
  void aug(int x)
  {
    if(x==n)
    {
      found=true;
      ans+=flow;
      return;
    }
    int64  minh=n-1,old=flow,i;
    for(i=1;i<=n;i++)
      if(c2[x][i]>0)
      {
        if(h[i]+1==h[x])
        {
          if(c2[x][i]<flow)
            flow=c2[x][i];
          aug(i);
          if(h[1]>=n) return;
          if(found) break;
        }
        if(minh>h[i])
          minh=h[i];
      }
    if(found)
    {
      c2[x][i]-=flow;
      c2[i][x]+=flow;
    }
    else
    {
      vh[h[x]]--;
      if(vh[h[x]]==0)
        h[1]=n;
      h[x]=minh+1;
      vh[h[x]]++;
    }
  }
  int64 getmax()
  {
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    h[0]=n;
    ans=0;
    while(h[1]<n)
    {
      flow=0x7FFFFFFF;
      found=false;
      aug(1);
    }
    return ans;
  }
}maxflow;


int main()
{
  int zu,zz;
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(ans,0,sizeof(ans));
    init();
    memcpy(c2,c,sizeof(c2));
    int64 max=maxflow.getmax();
    for(int64 i=1;i<=m;i++)
    {
      if(max==0) break;
      memcpy(c2,c,sizeof(c2));
      c2[e[i].x][e[i].y]-=e[i].f;
      int64 now=maxflow.getmax();
      if(now+e[i].f==max)
      {
        max-=e[i].f;
        c[e[i].x][e[i].y]-=e[i].f;
        ans[0]++;
        ans[ans[0]]=i;
      }
    }
    printf("Case %d: %lld\n",zz,ans[0]);
  }
  return 0;
}
