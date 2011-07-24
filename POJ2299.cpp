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
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int d)
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

int downs(int x)
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

void downc(int x,int d)
{
  while (x>0)
  {
    f[x]+=d;
    x-=lowbit(x);
  }
}
int ups(int x,int d)
{
  int s=0;
  while (x<=n)
  {
    s+=f[x];
    x+=lowbit(x);
  }
  return s;
}


int main()
{
  return 0;
}
