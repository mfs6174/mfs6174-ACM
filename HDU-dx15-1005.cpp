#include<cstdio>
#include<cstring>
#include<queue>
#define MAXE 200002
#define MAXV 100001
using namespace std;
const long long INF=(long long)1<<63-1;
typedef pair<long long,long long> pii;
long long t,m,n,V,E,pos=0,head[MAXV],from[MAXV],lai[MAXV];
long long ans,d[MAXV];
bool cannot=0,cut[MAXE];
struct Edge
{
  long long w,next,v;
}node[MAXE*2];
//无向图邻接表
void add(long long u,long long v,long long w)
{
  if(u==v) return;                  //如果指向自己的边则舍去
  node[pos].v=v;
  node[pos].w=w;
  node[pos].next=head[u];
  head[u]=pos++;
}
//S为起点标号
void dijkstra(long long s)
{
  for(long long i=0;i<=V;i++) d[i]=INF;d[s]=0;
  priority_queue<pii,vector<pii>,greater<pii> > q;
  bool done[MAXV];
  memset(done,0,sizeof(done));
  q.push(make_pair(d[s],s));
  while(!q.empty()){
    pii u=q.top();q.pop();
    long long x=u.second;
    if(done[x]) continue;
    done[x]=true;
    for(long long i=head[x];i!=-1;i=node[i].next)       //松弛操作
      if(d[node[i].v]>d[x]+node[i].w){
        from[node[i].v]=x;
        lai[node[i].v]=i;
        d[node[i].v]=d[x]+node[i].w;
        q.push(make_pair(d[node[i].v],node[i].v));
      }
  }
}
long long sou(int s)
{
  for(long long i=0;i<=V;i++) d[i]=INF;d[s]=0;
  priority_queue<pii,vector<pii>,greater<pii> > q;
  bool done[MAXV];
  memset(done,0,sizeof(done));
  q.push(make_pair(d[s],s));
  while(!q.empty()){
    pii u=q.top();q.pop();
    long long x=u.second;
    if(done[x]) continue;
    done[x]=true;
    for(long long i=head[x];i!=-1;i=node[i].next)       //松弛操作
      if(d[node[i].v]>d[x]+node[i].w && (!cut[i])){
        d[node[i].v]=d[x]+node[i].w;
        q.push(make_pair(d[node[i].v],node[i].v));
      }
  }
}
int  main()
{
  freopen("ti.in","r",stdin);
  long long i,u,v,w,s,T;
  scanf("%lld",&T);
  while(T--){
    scanf("%lld%lld",&V,&E);
    pos=0;
    memset(from,0,sizeof(from));
    memset(cut,0,sizeof(cut));
    memset(head,-1,sizeof(head));
    for(i=0;i<E;i++){
      scanf("%lld%lld%lld",&u,&v,&w);
      add(u,v,w);
      add(v,u,w);
    }
    s=1;t=V;pos=0;
    dijkstra(s);
    //printf("%lld\n",d[t]);
    ans=-1;
    memset(cut,0,sizeof(cut));
    for(i=V;i>1;i=from[i]){
      cut[lai[i]]=cut[lai[i]^1]=true;
      sou(1);
      ans=max(d[V],ans);
      //if(d[t]>=INF) break;
      cut[lai[i]]=cut[lai[i]^1]=false;
    }
    if(ans>=INF) printf("-1\n");
    else printf("%lld\n",ans);
  }
  return 0;
}
