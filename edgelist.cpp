/*
ID: mfs6174
PROG: BIT
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

void dfs(int x,int ff)
{
  shu[x].f=ff;
  shu[x].s=cc;
  for(int i=head[x];i!=-1;i=node[i].next)//用法示例
    if (node[i].v!=ff)
      dfs(node[i].v,x);
  cc++;
  shu[x].t=cc;
}
    
int main()
{
  scanf("%d",&n);
  pos=1;  
  memset(head,-1,sizeof(head)); //2个初始化
  for (i=1;i<n;i++)
  {
    scanf("%d%d",&j,&k);
    add(j,k);//加边，也可以有边权
    add(k,j);
  }
  return 0;
}
