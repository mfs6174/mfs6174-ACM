#include<cstdio>
#include<cstring>
#include<queue>
#include<ctime>
#define MAXE 1100000
#define MAXV 1100
using namespace std;
const long long INF=(long long)1<<63-1;
typedef pair<long long,long long> pii;
long long t,m,n,V,E,pos=0,head[MAXV];
long long ans,d[MAXV];
bool cannot=0,done[MAXV];
struct Edge
{
    long long w,next,v;
}node[MAXE];
//无向图邻接表
void add(long long v,long long u,long long w)
{
    if(u==v) return;             //如果指向自己的边则舍去
    node[pos].v=v;
    node[pos].w=w;
    node[pos].next=head[u];
    head[u]=pos++;
}
//S为起点标号
struct dian
{
    long long a,b,c,d;
}ss[MAXV];

 long long dfs(long long v)
{
    if(done[v]) return d[v];
    done[v]=1;
    long long tmp=0;
    for(long long i=head[v];i!=-1;i=node[i].next)
        tmp=max(tmp,dfs(node[i].v));
    return d[v]=tmp+ss[v].c;
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    long long u,v,w,s,t;
    while(EOF!=scanf("%I64d",&n)){
        if(n==0) break;
        pos=1;V=n*2+2;s=0;t=n+1;
        memset(head,-1,sizeof(head));
        memset(done,0,sizeof(done));
        memset(d,0,sizeof(d));
        memset(node,0,sizeof(node));
        memset(ss,0,sizeof(ss));
        for(long long i=1;i<=n;i++){
            scanf("%I64d%I64d%I64d%I64d",&ss[i].a,&(ss[i].b),&(ss[i].c),&(ss[i].d));
            add(s,i,0);
            add(i,t,0);
        }
        for(long long i=1;i<=n;i++)
            for(long long j=1;j<=n;j++) if(i!=j)
                if(ss[i].d==0 && ss[j].d==0 && ss[i].a==ss[j].a && ss[i].b==ss[j].b){
                    ss[i].c+=ss[j].c;
                    ss[j].a=ss[j].b=0;ss[j].c=0;ss[j].d=2;
                }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++)if(i!=j){
                if(ss[i].a<=ss[j].a && ss[i].b<=ss[j].b){
                    if(ss[i].d==0)
                        add(j,i,1);
                    else if(ss[i].d==1 && !(ss[i].a==ss[j].a && ss[i].b==ss[j].b))
                        add(j,i,1);
                    else if(ss[i].d==2 && ss[i].a<ss[j].a && ss[i].b<ss[j].b)
                        add(j,i,1);
                }
            }
        }

        ans=dfs(t);
        printf("%I64d\n",ans);
    }
    return 0;
}

