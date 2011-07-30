/*
ID: mfs6174
PROG: ti
LANG: C++
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define MAXN 110000

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int pos=0,head[MAXN];
struct Edge  
{  
  int next,u,v,w;  
}node[MAXN*2]; //使用的结构 这里由于是树，所以边数跟点数一样了，否则要单独算边数
void add(int u,int v,int w)  //这里没有边权，如果加上边权则结构里加一个东西
{  
  if(u==v) return;  
  node[pos].u=u;                 //如果指向自己的边则舍去  
  node[pos].v=v;
  node[pos].w=w;
  node[pos].next=head[u];  
  head[u]=pos++;  
}
void elinit()
{
  pos=1;  
  memset(head,-1,sizeof(head)); //2个初始化
}
int f[MAXN],gg[MAXN],g[MAXN],shu[MAXN],ff[MAXN];
int i,j,k,t,n,m,mm;

inline long long  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    long long ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

void dfs1(int x,int fu)
{
  int i;
  f[x]=ff[x]=0;
  for(i=head[x];i!=-1;i=node[i].next)
    if (node[i].v!=fu)
    {
      dfs1(node[i].v,x);
      f[x]+=f[node[i].v];
      ff[x]+=(ff[node[i].v]+f[node[i].v]*node[i].w);
    }
  f[x]+=shu[x];
}

void dfs2(int x,int q,int fu,int g,int gg)
{
  int i;
  ff[x]+=(g*q+gg);
  f[x]+=g;
  mm=min(mm,ff[x]);
  for(i=head[x];i!=-1;i=node[i].next)
    if (node[i].v!=fu)
      dfs2(node[i].v,node[i].w,x,f[x]-f[node[i].v],ff[x]-ff[node[i].v]-f[node[i].v]*node[i].w);
}
  
int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    elinit();
    for (i=1;i<=n;i++)
      shu[i]=get();
    for (i=1;i<n;i++)
    {
      j=get();k=get();t=get();
      add(j,k,t);
      add(k,j,t);
    }
    mm=maxlongint;
    dfs1(1,1);
    dfs2(1,0,0,0,0);
    cout<<mm<<endl;
  }
  return 0;
}

