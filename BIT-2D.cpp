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
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

#define MAXN 1000
int shu[MAXN],f[MAXN];
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

int main()
{
  return 0;
}
