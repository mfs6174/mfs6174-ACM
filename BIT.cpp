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

#define MAXN 100000
int shu[MAXN],f[MAXN];
int n;

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int d,int n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

int downs(int x) //查找
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

void downc(int x,int d) //相反的过程，用于s[i--n]的和
{
  while (x>0)
  {
    f[x]+=d;
    x-=lowbit(x);
  }
}
int ups(int x,int d,int n)
{
  int s=0;
  while (x<=n)
  {
    s+=f[x];
    x+=lowbit(x);
  }
  return s;
}


int find(int k,int n) //树状数组上二分查找，用于寻找和为k的下标（一般是第k大的数）
{
  int x=1,y=n,m;
  while (x<=y)
  {
    m=(x+y)>>1;
    int t=k-downs(m-1);
    if (shu[m]>0&&t>=1&&t<=shu[m])
      return m;
    t=downs(m);
    if (t<k)
      x=m+1;
    else
      y=m-1;
  }
  return -1;
}

int main()
{
  return 0;
}
