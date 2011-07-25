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

#define MAXD 200000
struct D
{
  int l,r,d,k;
};
D shu[MAXD];
int fu[MAXD];
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
  if (shu[y].k<shu[x].k) sw(x,y);//将大的合并到小的下面的右子树上（小根堆）
  shu[x].r=mg(shu[x].r,y);//递归合并
  fu[shu[x].r]=x;//记录父亲，如果不删除任意节点则不需要
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
  return cc;
}
int ins(int r,int x)//插入一个数
{
  int t=mk(x);
  return mg(r,t);
}

int bd(int a[],int n)//用a中每个元素O(n)建树，用了队列
{
  int q[2*MAXD];
  int *s=q,*e=q,i,t;
  for (i=1;i<=n;i++)
    *e++=mk(a[i]);
  while ((s+1)!=e)
  {
    i=*s++;t=*s++;
    t=mg(i,t);
    *e++=t;
  }
  return *s;
}

void del(int x)//删除节点x，向上调整
{
  int q=fu[x];
  int p=mg(shu[x].l,shu[x].r);
  fu[p]=q;
  if (q&&shu[q].l==x) shu[q].l=p;
  if (q&&shu[q].r==x) shu[q].r=p;
  while (q)
  {
    if (shu[shu[q].l].d<shu[shu[q].r].d)
      sw(shu[q].l,shu[q].r);
    if (shu[shu[q].r].d+1==shu[q].d)
      return;
    shu[q].d=shu[shu[q].r].d+1;
    p=q;q=fu[q];
  }
}

int main()
{
  return 0;
}
