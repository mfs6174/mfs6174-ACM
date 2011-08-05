/*
ID: mfs6174
PROG: HDU3907
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
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int l[1100],q[1100],n;
  int fei,xian;
};

int i,j,k,t,n,m,zz,zu,rt,w,dd;
int f[1100][1100];
D shu[1100];

void dfs(int x,int y)
{
  if (f[x][y]!=-1)
    return;
  if (shu[x].n==0)
  {
    if (dd<=shu[x].xian)
      f[x][y]=0;
    else
      f[x][y]=shu[x].fei;
    return;
  }
  int i,t=dd,s=0;
  f[x][y]=0;
  for (i=1;i<=shu[x].n;i++)
  {
    dd=shu[x].q[i];
    dfs(shu[x].l[i],x);
    f[x][y]+=f[shu[x].l[i]][x];
  }
  f[x][y]+=shu[x].fei;
  dd=t;
  if (dd<=shu[x].xian&&x!=rt)
  {
    for (i=1;i<=shu[x].n;i++)
    {
      dd+=shu[x].q[i];
      dfs(shu[x].l[i],y);
      dd-=shu[x].q[i];
      s+=f[shu[x].l[i]][y];
    }
    f[x][y]=min(f[x][y],s);
  }
}
  
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(shu,0,sizeof(shu));
    memset(f,-1,sizeof(f));
    cin>>n;
    for (i=1;i<=n;i++)
    {
      cin>>t>>shu[i].xian>>shu[i].fei>>w;
      if (t==0)
        rt=i;
      else
      {
        shu[t].n++;
        shu[t].l[shu[t].n]=i;
        shu[t].q[shu[t].n]=w;
      }
    }
    dd=0;
    dfs(rt,rt);
    cout<<f[rt][rt]<<endl;
  }
  return 0;
}

