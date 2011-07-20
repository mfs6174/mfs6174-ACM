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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;
#define N 5100
#define M 100100
struct Edge
{
    int v;
    int next;
};
Edge edge[M];//边的集合
Edge xinb[M];
int node[N];//顶点集合
int xin[N];
int instack[N];//标记是否在stack中
int stack[N];
int Belong[N];//各顶点属于哪个强连通分量
int DFN[N];//节点u搜索的序号(时间戳)
int LOW[N];//u或u的子树能够追溯到的最早的栈中节点的序号(时间戳)
int n, m;//n：点的个数；m：边的条数
int cnt_edge;//边的计数器
int Index;//序号(时间戳)
int top;
int Bcnt;//有多少个强连通分量
bool ff[N];
int cc,zu,zz;
int ru[N];
vector<int> ke;

void add_edge(int u, int v)//邻接表存储
{
    edge[cnt_edge].next = node[u];
    edge[cnt_edge].v = v;
    node[u] = cnt_edge++;
}
void addn(int u, int v)//邻接表存储
{
    xinb[cnt_edge].next = xin[u];
    xinb[cnt_edge].v = v;
    xin[u] = cnt_edge++;
}
void tarjan(int u)
{
    int i,j;
    int v;
    DFN[u]=LOW[u]=++Index;
    instack[u]=true;
    stack[++top]=u;
    for (i = node[u]; i != -1; i = edge[i].next)
    {
        v=edge[i].v;
        if (!DFN[v])//如果点v没被访问
        {
            tarjan(v);
            if (LOW[v]<LOW[u])
                LOW[u]=LOW[v];
        }
        else//如果点v已经被访问过
            if (instack[v] && DFN[v]<LOW[u])
                LOW[u]=DFN[v];
    }
    if (DFN[u]==LOW[u])
    {
        Bcnt++;
        do
        {
            j=stack[top--];
            instack[j]=false;
            Belong[j]=Bcnt;
        }
        while (j!=u);
    }
}
void solve()
{
    int i;
    top=Bcnt=Index=0;
    memset(DFN,0,sizeof(DFN));
    memset(LOW,0,sizeof(LOW));
    for (i=1;i<=n;i++)
        if (!DFN[i])
            tarjan(i);
}

void mfs(int x)
{
  int i;
  bool tf=false;
  ff[x]=true;
  for (i = xin[x]; i != -1; i = xinb[i].next)
  {
    int v=xinb[i].v;
    if (!ff[v])
    {
      if (!tf)
      {
        mfs(v);
        tf=true;
      }
    }
    ru[v]--;
    if (ru[v]==0)
      ke.push_back(v);
  }
}

      
int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    int i,j,k;
    cnt_edge=0;
    memset(node,-1,sizeof(node));
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d",&j,&k);
      add_edge(j,k);
    }
    solve();
    cnt_edge=0;
    memset(xin,-1,sizeof(xin));
    for(int u=1;u<=n;u++)
      for (i = node[u]; i != -1; i = edge[i].next)
      {
        int v=edge[i].v;
        if (Belong[u]!=Belong[v])
        {
          addn(Belong[u],Belong[v]);
          ru[Belong[v]]++;
        }
      }
    cc=0;
    memset(ff,0,sizeof(ff));
    ke.clear();
    for (i=1;i<=Bcnt;i++)
      if (ru[i]==0)
        ke.push_back(i);
    while (!ke.empty())
    {
      int t=*ke.rbegin();
      ke.pop_back();
      if (ff[t])
        continue;
      cc++;
      mfs(t);
    }
    cout<<cc<<endl;
  }
  return 0;
}
