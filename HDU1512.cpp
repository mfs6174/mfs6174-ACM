/*
ID: mfs6174
PROG: HDU 1512
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

#define MAXD 300000
struct D
{
  int l,r,d,k;
};
D shu[MAXD];
int hh[MAXD];
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

int i,j,k,t,n,m,a,b,tt,k1,k2,h,xin1,xin2;
int ff[MAXD],dui[MAXD];

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

int cha(int x)
{
  if (ff[x]==x)
    return x;
  ff[x]=cha(ff[x]);
  return ff[x];
}

inline void bing(int x,int y)
{
	int i,j;
	i=cha(x);j=cha(y);
	if (i!=j)
	ff[i]=j;//总根为标志，把总根挂到另一个的总根下
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    init();
    for (i=1;i<=n;i++)
    {
      hh[i]=get();
      ff[i]=i;
      dui[i]=mk(hh[i]);
    }
    m=get();
    for (i=1;i<=m;i++)
    {
      a=get();b=get();
      t=cha(a);tt=cha(b);
      if (t==tt)
      {
        cout<<-1<<endl;
        continue;
      }
      xin1=dui[t];xin2=dui[tt];
      k1=pop(xin1);k2=pop(xin2);
      xin1=ins(xin1,k1/2);xin2=ins(xin2,k2/2);
      xin1=mg(xin1,xin2);
      bing(t,tt);
      dui[cha(t)]=xin1;
      cout<<shu[xin1].k<<endl;
    }
  }
  return 0;
}
