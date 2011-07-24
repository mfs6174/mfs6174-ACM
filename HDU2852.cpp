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
int f[MAXN];
int n;

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int d,int n)
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

int i,j,k,m,t,tt,a;
int shu[MAXN];

inline int  get()
{
    char c;
    while (c=getchar(),c<'0'||c>'9');
    int ret=c-'0';
    while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
    return ret;
}

int find(int k)
{
  int x=1,y=100000,m;
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
  freopen("ti.in","r",stdin);
  while (scanf("%d",&m)!=EOF)
  {
    memset(shu,0,sizeof(shu));
    memset(f,0,sizeof(f));
    for (i=1;i<=m;i++)
    {
      tt=get();
      if (tt==0)
      {
        t=get();
        shu[t]++;
        upc(t,1,100000);
        continue;
      }
      if (tt==1)
      {
        t=get();
        if (!shu[t])
          cout<<"No Elment!"<<endl;
        else
        {
          shu[t]--;
          upc(t,-1,100000);
        }
        continue;
      }
      a=get();k=get();
      t=downs(a);
      j=find(t+k);
      if (j==-1)
        cout<<"Not Find!"<<endl;
      else
        cout<<j<<endl;
    }
  }
  return 0;
}
