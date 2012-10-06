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

#define MAXE 201002
#define MAXV 101001
const long long INF=((long long)1)<<63-1;
typedef pair<long long,long long> pii;
long long pos=0,head[MAXV];
long long ans,d[MAXV];
bool cannot=0;
llg i,j,k,t,n,m,ss,ll,cc,tt,u,v,w;
llg bian[120000][5];
struct Edge
{
  long long w,next,v;
}node[MAXE*2];
//无向图邻接表
void add(long long u,long long v,long long w)
{
  node[pos].v=v;
  node[pos].w=w;
  node[pos].next=head[u];
  head[u]=pos++;
}
//S为起点标号
void dijkstra(long long s)
{
  for(long long i=0;i<=n;i++) d[i]=INF;d[s]=0;
  priority_queue<pii,vector<pii>,greater<pii> > q;
  bool done[MAXV];
  memset(done,0,sizeof(done));
  q.push(make_pair(d[s],s));
  while(!q.empty())
  {
    pii u=q.top();q.pop();
    long long x=u.second;
    if(done[x]) continue;
    done[x]=true;
    for(long long i=head[x];i!=-1;i=node[i].next)       //松弛操作
      if(d[node[i].v]>d[x]+node[i].w)
      {
        d[node[i].v]=d[x]+node[i].w;
        q.push(make_pair(d[node[i].v],node[i].v));
      }
  }
}

int  main()
{
  //freopen("ti.in","r",stdin);
  pos=1;
  memset(head,-1,sizeof(head));
  sf("%lld%lld%lld",&n,&m,&ss);
  for(i=1;i<=m;i++)
  {
    scanf("%lld%lld%lld",&u,&v,&w);
    add(u,v,w);
    add(v,u,w);
    bian[i][1]=u;bian[i][2]=v;
    bian[i][3]=w;
  }
  sf("%lld",&ll);
  dijkstra(ss);
  for (i=1;i<=n;i++)
    if (d[i]==ll)
      cc++;
  for (i=1;i<=m;i++)
  {
    llg ttt;
    bool t1=false;
    t=d[bian[i][1]]+bian[i][3]-1;
    if (ll>=d[bian[i][1]]+1&&ll<=t)
    {
      t=ll-d[bian[i][1]];
      ttt=bian[i][3]-t;
      if (d[bian[i][2]]+ttt>=ll)
      {
        cc++;
        t1=true;
      }
    }
    tt=d[bian[i][2]]+bian[i][3]-1;
    if (ll>=d[bian[i][2]]+1&&ll<=tt)
    {
      tt=ll-d[bian[i][2]];
      ttt=bian[i][3]-tt;
      if (d[bian[i][1]]+ttt>=ll)
        if (t+tt!=bian[i][3]||(!t1))
          cc++;
    }
  }
  cout<<cc<<endl;
  return 0;
}
