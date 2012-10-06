//#pragma comment(linker, "/STACK:65536000")
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
#define N 105
#define M 1005
#define E
#define inf 0x3f3f3f3f
#define dinf 1e10
#define linf (LL)1<<60
#define LL long long
#define clr(a,b) memset(a,b,sizeof(a))
 
struct Edge
{
    LL a,b,c;
    bool operator<(const Edge & t)const
    {
        return c<t.c;
    }
}edge[M];
LL ans;
LL fa[N],ka[N],vis[N];
LL gk[N][N],tmp[N][N];
vector<LL>gra[N];

LL i,j,k,t,n,m,mod;

LL fffa(LL a,LL b[]){return a==b[a]?a:b[a]=fffa(b[a],b);}
 
LL ddt(LL a[][N],LL n)
{
    for(LL i=0;i<n;i++)for(LL j=0;j<n;j++)a[i][j]%=mod;
    LL ret=1;
    for(LL i=1;i<n;i++)
    {
        for(LL j=i+1;j<n;j++)
            while(a[j][i])
            {
                LL t=a[i][i]/a[j][i];
                for(LL k=i;k<n;k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(LL k=i;k<n;k++)
                  swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        if(a[i][i]==0)return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}
 
int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%I64d%I64d%I64d",&n,&m,&mod)!=EOF)
  {
    for (LL i=0;i<=n;i++)
      gra[i].clear();
    memset(ka,0,sizeof(ka));
    memset(gk,0,sizeof(gk));
    if (n==0&&m==0&&mod==0)
      break;
    for(LL i=0;i<m;i++)
      sf("%I64d%I64d%I64d",&edge[i].a,&edge[i].b,&edge[i].c);
    sort(edge,edge+m);
    for(LL i=1;i<=n;i++)fa[i]=i,vis[i]=0;
    LL pre=-1;ans=1;
    for(LL h=0;h<=m;h++)
    {
      if(edge[h].c!=pre||h==m)
      {
        for(LL i=1;i<=n;i++)
          if(vis[i])
          {
            LL u=fffa(i,ka);
            gra[u].push_back(i);
            vis[i]=0;
          }
        for(LL i=1;i<=n;i++)
          if(gra[i].size()>1)
          {
            for(LL a=1;a<=n;a++)
              for(LL b=1;b<=n;b++)
                tmp[a][b]=0;
            LL len=gra[i].size();
            for(LL a=0;a<len;a++)
              for(LL b=a+1;b<len;b++)
              {
                LL la=gra[i][a],lb=gra[i][b];
                tmp[a][b]=(tmp[b][a]-=gk[la][lb]);
                tmp[a][a]+=gk[la][lb];tmp[b][b]+=gk[la][lb];
              }
            LL ret=ddt(tmp,len);
            ans=(ans*ret)%mod;
            for(LL a=0;a<len;a++)fa[gra[i][a]]=i;
          }
        for(LL i=1;i<=n;i++)
        {
          ka[i]=fa[i]=fffa(i,fa);
          gra[i].clear();
        }
        if(h==m)break;
        pre=edge[h].c;
      }
      LL a=edge[h].a,b=edge[h].b;
      LL pa=fffa(a,fa),pb=fffa(b,fa);
      if(pa==pb)continue;
      vis[pa]=vis[pb]=1;
      ka[fffa(pa,ka)]=fffa(pb,ka);
      gk[pa][pb]++;gk[pb][pa]++;
    }
    LL flag=0;
    for(LL i=2;i<=n&&!flag;i++)if(ka[i]!=ka[i-1])flag=1;
    printf("%I64d\n",flag?0:ans);
  }
  return 0;
}
