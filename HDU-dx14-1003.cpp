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

#define MAXN 55000
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct T
{
  int x,y,d,lt;
};

T shu[MAXN*5];

void stinit(int p,int x,int y)
{
  shu[p].x=x;shu[p].y=y;shu[p].d=shu[p].lt=-1;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}

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

int i,j,k,t,n,m,zu,zz,ti;
int shex[MAXN],shey[MAXN];
int du[MAXN];

void init()
{
  pos=1;
  memset(head,-1,sizeof(head));
  memset(du,0,sizeof(du));
}

void ud(int p,int x,int y,int d)
{
  int mid=(shu[p].x+shu[p].y)>>1;
  if (x<=shu[p].x&&y>=shu[p].y)
  {
    shu[p].d=d;
    return;
  }
  if (shu[p].d!=-2)//这里必须判断，不然就把和谐的压成不和谐的了
  {
    ud(p<<1,shu[p].x,mid,shu[p].d);
    ud((p<<1)+1,mid+1,shu[p].y,shu[p].d);
    shu[p].d=-2;
  }
  if (x<=mid)
    ud(p<<1,x,y,d);
  if (y>mid)
    ud((p<<1)+1,x,y,d);
}

int qr(int p,int w)
{
  int mid=(shu[p].x+shu[p].y)>>1;
  if (shu[p].d!=-2)
    return shu[p].d;
  if (w<=mid)
    return qr(p<<1,w);
  else
    return qr((p<<1)+1,w);
}

void dfs(int x)
{
  shex[x]=ti;
  for(int i=head[x];i!=-1;i=node[i].next)
    dfs(node[i].v);
  ti++;
  shey[x]=ti-1;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d",&n);
    init();
    for (i=1;i<n;i++)
    {
      scanf("%d%d",&j,&k);
      add(k,j);
      du[j]++;
    }
    ti=1;
    for (i=1;i<=n;i++)
      if (du[i]==0)
      {
        dfs(i);
        break;
      }
    stinit(1,1,n);
    scanf("%d",&m);
    printf("Case #%d:\n",zz);
    for (k=1;k<=m;k++)
    {
      char tc;
      scanf("\n%c",&tc);
      if (tc=='C')
      {
        scanf("%d",&t);
        cout<<qr(1,shey[t])<<endl;
      }
      else
      {
        scanf("%d%d",&j,&t);
        ud(1,shex[j],shey[j],t);
      }
    }
  }
  return 0;
}
      
