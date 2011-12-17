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
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const double Ling=1e-9;
struct D
{
  int n;
  int wu[20];
};

int i,j,k,t,n,m,zz,zu;
D shu[20];
bool ff[20],tu[20][20];
int mm,dd;
int xx[20],yy[20],rr[20];


inline int fang(int x)
{
  return x*x;
}

inline double dst(int x,int y,int xx,int yy)
{
  return sqrt(fang(x-xx)+fang(y-yy)+0.0);
}
inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

void dfs(int x)
{
  if (x>n)
  {
    mm=max(mm,dd);
    return;
  }
  int i;
  if (!ff[x])
  {
    bool ft[16];
    memcpy(ft,ff,sizeof(ft));
    dd+=fang(rr[x]);
    for (i=1;i<=shu[x].n;i++)
      ff[shu[x].wu[i]]=true;
    dfs(x+1);
    dd-=fang(rr[x]);
    memcpy(ff,ft,sizeof(ft));
    dfs(x+1);
    
  }
  else
    dfs(x+1);
}    
int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(ff,0,sizeof(ff));
    memset(tu,0,sizeof(tu));
    memset(shu,0,sizeof(shu));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d%d",&xx[i],&yy[i],&rr[i]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (i!=j)
          if (cwz(dst(xx[i],yy[i],xx[j],yy[j])-(rr[i]+rr[j]))<=0)
          {
            shu[i].n++;
            shu[i].wu[shu[i].n]=j;
          }
    dd=mm=0;
    dfs(1);
    cout<<mm<<endl;
  }
  return 0;
}

