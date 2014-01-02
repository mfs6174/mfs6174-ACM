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
const int maxlongint=2147483647;

#define INF ((long long)1<<62)
#define N 5000
#define M 300000
llg n,m,s,t;	llg head[N],cur[N],cnt;
struct edge{    llg v,w,next;	}e[M];
llg q[N],dis[N],start,end;
void addedge(llg u,llg v,llg w)
{	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
llg bfs()
{
    memset(dis,-1,sizeof(dis));    start=end=0; q[0]=t; dis[t]=0;
    while (start<=end)
    {
        llg u=q[start++];
        for(int i=head[u];i!=-1;i=e[i].next)
        if(dis[e[i].v]==-1 && e[i^1].w>0)  {  dis[e[i].v]=dis[u]+1;   q[++end]=e[i].v;    }
    }
    return dis[s]!=-1;
}
llg dfs(llg u,llg t,llg flow)
{
    if(u==t) return flow;    llg delta=flow;
    for(llg &i=cur[u];i!=-1;i=e[i].next)
        if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
        {
            llg d=dfs(e[i].v,t,min(delta,e[i].w));
            e[i].w-=d;    e[i^1].w+=d;   delta-=d;
            if(d==0) dis[e[i].v]=-1;
            //if(delta==0) break;
        }
    return flow-delta;
}

llg i,j,k,aa,bb,cc,zl;
llg zu,zz;
llg rs;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%lld",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%lld%lld",&n,&m);
    s=1;t=n;
    rs=0;
    cnt=0;
    memset(head,-1,sizeof(head));
    pf("Case #%lld:\n",zz);
    //int ans0=0;
    for (j=1;j<=m;j++)
    {
      sf("%lld%lld%lld",&aa,&bb,&cc);
      addedge(aa,bb,cc);
      llg ans0=0;
      while (bfs()){	for(i=1;i<=n;i++) cur[i]=head[i];		ans0+=dfs(s,t,INF);		}
      zl=ans0-rs;
      rs=ans0;
      if (ans0>0)
        pf("%lld %lld\n",j,ans0);
    }
  }
  return 0;
}
