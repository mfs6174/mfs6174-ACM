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

#define MAXN 1200
int f[MAXN][MAXN];
int n;

//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int y,int d,int n,int m)
{
  while (x<=n)
  {
    int yy=y;
    while (yy<=m)
    {
      f[x][yy]+=d;
      yy+=lowbit(yy);
    }
    x+=lowbit(x);
  }
}

int downs(int x,int y)
{
  if (x*y==0)
    return 0;
  int s=0;
  while (x>0)
  {
    int yy=y;
    while (yy>0)
    {
      s+=f[x][yy];
      yy-=lowbit(yy);
    }
    x-=lowbit(x);
  }
  return s;
}

int i,j,k,t,tt,x,y,l,r,b;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d%d",&t,&n);
  while (scanf("%d",&tt)&&(tt!=3))
  {
    if (tt==1)
    {
      scanf("%d%d%d",&x,&y,&t);
      upc(x+1,y+1,t,n,n);
    }
    else
    {
      scanf("%d%d%d%d",&l,&b,&r,&t);
      tt=downs(r+1,t+1)-downs(l,t+1)-downs(r+1,b)+downs(l,b);
      cout<<tt<<endl;
    }
  }
  return 0;
}
