/*
ID: mfs6174
PROG: POJ1947
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
#define MAXN 110000
int i,j,k,t,n,m,p,mm;
int f[200][200],g[200][200],he[200];

int pos=0,head[MAXN];

struct Edge  
{  
  int next,u,v;  
}node[MAXN*2]; //使用的结构 这里由于是树，所以边数跟点数一样了，否则要单独算边数

void elinit()
{
  pos=1;  
  memset(head,-1,sizeof(head)); //2个初始化
}
void add(int u,int v)  //这里没有边权，如果加上边权则结构里加一个东西
{  
  node[pos].u=u;               
  node[pos].v=v;  
  node[pos].next=head[u];  
  head[u]=pos++;  
}

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

void dfs(int x,int fu)
{
  int i,j,k,c=0;
  bool fl=true;
  he[x]=1;
  for(i=head[x];i!=-1;i=node[i].next)//用法示例
    if (node[i].v!=fu)
    {
      fl=false;
      dfs(node[i].v,x);
      he[x]+=he[node[i].v];
    }
  if (fl)
  {
    f[x][1]=0;
    if (p==1)
      mm=min(mm,1);//注意这里，如果p是1，那么可以砍一个叶子，这里退出的时候也必须更新mm
    return;
  }
  memset(g,-1,sizeof(g));
  g[0][0]=0;
  int v;
  int tt=min(he[x],p);
  for(i=head[x];i!=-1;i=node[i].next)//用法示例
    if (node[i].v!=fu)
    {
      v=node[i].v;
      c++;
      for (j=0;j<=tt;j++)
      {
        if (g[c-1][j]!=-1)
          g[c][j]=g[c-1][j]+1;
        for (k=1;k<=he[v];k++)
        {
          if (j-k<0)
            break;
          if (g[c-1][j-k]!=-1&&f[v][k]!=-1)
            if (g[c][j]!=-1)
              g[c][j]=min(g[c][j],g[c-1][j-k]+f[v][k]);
            else
              g[c][j]=g[c-1][j-k]+f[v][k];
        }
      }
    }
  for (j=1;j<=tt;j++)
    f[x][j]=g[c][j-1];
  if (f[x][p]!=-1)
    mm=min(mm,f[x][p]+1); //这里，子树是p，非根，则要加1（砍断父亲）
}

int main()
{
  freopen("ti.in","r",stdin);
  elinit();
  n=get();p=get();
  for (i=1;i<n;i++)
  {
    j=get();k=get();
    add(j,k);
    add(k,j);
  }
  mm=maxlongint;
  memset(f,-1,sizeof(f));
  dfs(1,1);
  if (f[1][p]!=-1)
    mm=min(mm,f[1][p]);
  cout<<mm<<endl;
}


