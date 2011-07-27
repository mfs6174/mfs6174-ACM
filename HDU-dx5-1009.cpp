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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

#define MAXD 4000000
struct D
{
  int l,r,d,k,m;
};
D shu[MAXD];
int cc;

void sw(int &x,int &y)
{
  int t=x;
  x=y;y=t;
}

void init()//初始化，每组数据执行
{
  memset(shu,0,sizeof(shu));
  cc=0;shu[0].d=-1;
}

int mg(int x,int y)//合并，将x，y合并，返回合并后的根
{
  if (!x) return y;
  if (!y) return x;
  if (shu[y].k>shu[x].k) sw(x,y);//将大的合并到小的下面的右子树上（小根堆）
  shu[x].r=mg(shu[x].r,y);//递归合并
  shu[x].m+=shu[y].m;
  if (shu[shu[x].r].d>shu[shu[x].l].d)
    sw(shu[x].l,shu[x].r);
  shu[x].d=shu[shu[x].r].d+1;//交换维持性质并更新距离
  return x;
}

int pop(int &x)//弹出根，返回值，x将变为弹出后的堆根
{
  int t=shu[x].k;
  x=mg(shu[x].l,shu[x].r);
  return t;
}

int mk(int d)//生成一个只有一个点的堆
{
  cc++;
  shu[cc].k=d;
  shu[cc].m=1;
  return cc;
}
int ins(int r,int x)//插入一个数
{
  int t=mk(x);
  return mg(r,t);
}

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

#define MAXN 110000

int pos=0,head[MAXN];
struct Edge  
{  
  int next,u,v;  
}node[MAXN*2]; //使用的结构 这里由于是树，所以边数跟点数一样了，否则要单独算边数
void add(int u,int v)  //这里没有边权，如果加上边权则结构里加一个东西
{  
  if(u==v) return;  
  node[pos].u=u;                 //如果指向自己的边则舍去  
  node[pos].v=v;  
  node[pos].next=head[u];  
  head[u]=pos++;  
}

int i,j,t,k,n,m,p;
int f[MAXN],zhi[MAXN];

void mfs(int x)
{
  int t=mk(x),tt;
  for(int i=head[x];i!=-1;i=node[i].next)
  {
    mfs(node[i].v);
    t=mg(t,zhi[node[i].v]);
  }
  tt=mk(pop(t));
  while (shu[t].k>=x)
    tt=ins(tt,pop(t));
  f[x]=shu[t].m;
  zhi[x]=mg(t,tt);
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&p)!=EOF&&n)
  {
    pos=1;  
    memset(head,-1,sizeof(head)); //2个初始化
    for (i=1;i<=n;i++)
    {
      j=get();k=get();
      add(j,k);
    }
    memset(f,0,sizeof(f));
    init();
    mfs(p);
    for (i=1;i<n;i++)
      cout<<f[i]<<' ';
    cout<<f[n]<<endl;
  }
  return 0;
}
