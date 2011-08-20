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
#define MAXN 11000
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct T
{
  int x,y,l,e,nw,ee[11],m;
};

T shu[MAXN*5];
int i,j,k,t,n,m,zz,zu,ma;
int nd[15];

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

void ud(int w,int x,int y,int d)
{
  
}

void qr(int w,int x,int y)
{
  
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d%d",&n,&ma,&m);
    stinit(n);
    for (i=2;i<=ma;i++)
      scanf("%d",nd[i]);
    printf("Case %d:\n",zz);
    for (i=1;i<=m;i++)
    {
      scanf("%c",&tc);
      if (tc=='W')
      {
        scanf("%d%d%d\n",&a,&b,&c);
        ud(1,a,b,c);
      }
      else
      {
        scanf("%d%d",&a,&b);
        cout<<qr(1,a,b)<<endl;
      }
    }
    cout<<endl;
  }
  return 0;
}


