/*
ID: mfs.dev2
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

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxlongint=2147483647;
const int maxm=200;
int n,m,t,i,j,k;
int zhen[maxm+5][maxm+5],rong[maxm+5][maxm+5],q[maxm+5],shu[maxm+5];

int min(int x,int y)
{
  return x<y?x:y;
}

bool EKbfs(int x,int y,int n)
{
  int i,t;
  bool f[maxm+5]={false};
  queue<int> dui;
  dui.push(x);
  shu[x]=maxlongint;
  while (!dui.empty())
  {
    t=dui.front();
    dui.pop();
    for (i=1;i<=n;i++)
    {
      if (f[i])//访问标志
        continue;
      if (zhen[t][i]<rong[t][i])//正向灌流 若还有流量
      {
        f[i]=true;
        q[i]=t;
        dui.push(i);
        shu[i]=min(shu[t],rong[t][i]-zhen[t][i]);//记录改进量
        if (i==y)
          return true;
      }
      if (zhen[i][t]>0)//退流 跟上段类似 反向边
      {
        f[i]=true;
        q[i]=-t;//前驱记负,区分进流退流
        dui.push(i);
        shu[i]=min(shu[t],zhen[i][t]);
        if (i==y)
          return true;
      }
    }
  }
  return false;
}
int EK(int x,int y,int n)//起始点 结束点 点个数 返回最大流
{
  int tt,t,mm=0;
  while (EKbfs(x,y,n))
  {
    t=y;mm+=shu[y];
    while (t!=x)
    {
      tt=(q[t]>0)?q[t]:(-q[t]);
      if (q[t]>0)
        zhen[tt][t]+=shu[y];
      else
        zhen[t][tt]-=shu[y];
      t=tt;
    }
  }
  return mm;
}

int main()
{
}
