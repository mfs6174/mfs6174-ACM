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

struct D
{
  vector<int> to;
  int s,t,f;
};

D shu[MAXN];
int i,j,k,t,m,cc;
char tc[3];
bool ff[MAXN];

void dfs(int x,int ff)
{
  shu[x].f=ff;
  shu[x].s=cc;
  for (vector<int>::iterator i=shu[x].to.begin();i!=shu[x].to.end();i++)
    if ((*i)!=ff)
      dfs(*i,x);
  cc++;
  shu[x].t=cc;
}
    
int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&n);
  for (i=1;i<n;i++)
  {
    scanf("%d%d",&j,&k);
    shu[j].to.push_back(k);
    shu[k].to.push_back(j);
  }
  for (i=1;i<=n;i++)
    upc(i,1,n);
  memset(ff,1,sizeof(ff));
  dfs(1,1);
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  {
    scanf("%s%d",tc,&t);
    if (tc[0]=='C')
    {
      if (ff[t])
      {
        ff[t]=false;
        upc(shu[t].t,-1,n);
      }
      else
      {
        ff[t]=true;
        upc(shu[t].t,1,n);
      }
    }
    else
    {
      int mm=downs(shu[t].t)-downs(shu[t].s);
      cout<<mm<<endl;
    }
  }
  return 0;
}
