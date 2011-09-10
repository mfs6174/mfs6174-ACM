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
#define MAXN 110000
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

struct T
{
  int x,y,l,d;
};

T shu[MAXN*5];
int i,j,k,t,n,m,zz,zu;

void stinit(int p,int x,int y)
{
  shu[p].x=x;shu[p].y=y;shu[p].l=1;shu[p].e=0;shu[p].nw=0;shu[p].ee=0;shu[p].m=0;
  if (x==y)
    return;
  stinit(p<<1,x,(x+y)>>1);
  stinit((p<<1)+1,((x+y)>>1)+1,y);
}
char tc;
int a,b,c;

void pd(int x)//pushdown函数 用延迟标记影响节点，把延迟标记传到子节点（比较懒所以只传递并不递归处理）
{
  if (shu[x].nw)
    
  shu[x<<1].d=
  shu[(x<<1)+1].d=shu[(x<<1)+1].d^shu[x].d;
  shu[x].d=0;
}
