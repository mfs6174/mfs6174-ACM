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
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  long long  p,b;
  bool operator <(const D &x) const
  {
    return p<x.p;
  }
};

long long  i,j,k,t,n,m,s,zz,zu,w,v,he;
long long f[1010][1010][2],zuo[1010],you[1010];
D d[1010],tt;

void mfs(long long x,long long y)
{
  long long t=zuo[x-1]+you[y+1];
  if (f[x][y][0]<maxlongint)
    return;
  if (x>y)
    return;
  if (x<w)
  {
    mfs(x+1,y);
    //    t=ff[x+1][y][0]+d[x+1].p-d[x].p;
    f[x][y][0]=min(f[x+1][y][0]+(t+d[x].b)*v*(d[x+1].p-d[x].p),f[x+1][y][1]+(t+d[x].b)*v*(d[y].p-d[x].p));
  }
    //    tt=ff[x+1][y][1]+d[y].p-d[x].p;
  if (y>w-1)
  {
    mfs(x,y-1);
    f[x][y][1]=min(f[x][y-1][1]+(t+d[y].b)*v*(d[y].p-d[y-1].p),f[x][y-1][0]+(t+d[y].b)*v*(d[y].p-d[x].p));
  }
}
  
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>v>>s;
    for (i=0;i<=n+1;i++)
      for (j=0;j<=n+1;j++)
        f[i][j][0]=f[i][j][1]=maxlongint;
    memset(zuo,0,sizeof(zuo));
    memset(you,0,sizeof(you));
    he=0;
    for (i=1;i<=n;i++)
    {
      cin>>d[i].p>>d[i].b;
      he+=d[i].b;
    }
    sort(&(d[1]),&(d[n+1]));
    w=n+1;
    for (i=1;i<=n;i++)
    {
      zuo[i]=zuo[i-1]+d[i].b;
      you[i]=he-zuo[i-1];
    }
    for (i=1;i<=n;i++)
      if (d[i].p>=s)
      {
        w=i;
        break;
      }
    f[w][w][1]=f[w][w][0]=abs(s-d[w].p)*v*he;
    f[w-1][w-1][0]=f[w-1][w-1][1]=abs(s-d[w-1].p)*v*he;
    // ff[w][w][0]=ff[w][w][1]=abs(s-d[w].p);
    // ff[w-1][w-1][0]=ff[w-1][w-1][1]=abs(s-d[w-1].p);
    mfs(1,n);
    long long mm=min(f[1][n][0],f[1][n][1]);
    cout<<mm<<endl;
  }
  return 0;
}

    
      
