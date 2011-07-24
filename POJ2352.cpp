/*
ID: mfs6174
PROG: POJ2352
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

#define MAXN 35000
int shu[MAXN],f[MAXN];
int n;

//f[x]表示x-lowbit+1 到 x的和
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

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

int i,j,k,t,xx,yy,m;

int main()
{
  freopen("ti.in","r",stdin);
  m=get();
  n=32002;
  for (i=1;i<=m;i++)
  {
    xx=get()+1;yy=get();
    t=downs(xx);
    shu[t]++;
    upc(xx,1);
  }
  for (i=0;i<m;i++)
    cout<<shu[i]<<endl;
  return 0;
}
