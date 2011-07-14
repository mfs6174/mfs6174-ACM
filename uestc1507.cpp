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
#include<queue>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  short x,y,l,d;
};

short f[901][8101],ff[901][8101];
int i,j,t,n,m,zz,zu;
queue<D> q;
D tt,ttt;

void shuchu(int x,int y)
{
  int nn=n,mm=m,l=x;
  int shu[105];
  while (nn>0)
  {
    shu[x]=y;
    nn-=y;
    mm-=y*y;
    x=f[nn][mm];
    y=ff[nn][mm];
  }
  for (int i=1;i<=l;i++)
    cout<<shu[i];
  cout<<endl;
}

int bi(int x,int y,int xx,int yy,int d,int dd)
{
  int b;
  if (x==0)
    return 0;
  if ((b=bi(x-d,y-d*d,xx-dd,yy-dd*dd,ff[x-d][y-d*d],ff[xx-dd][yy-dd*dd]))==0)
  {
    if (d>dd)
      return 1;
    else
      if (d<dd)
        return -1;
      else
        return 0;
  }
  else
    return b;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  memset(f,-1,sizeof(f));
  while (!q.empty())
    q.pop();
  tt.d=1;
  tt.x=0;
  tt.y=0;
  tt.l=0;
  ff[0][0]=1;
  q.push(tt);
  while (!q.empty())
  {
    tt=q.front();q.pop();
    if (tt.d!=ff[tt.x][tt.y])
      continue;
    ttt.l=tt.l+1;
    for (i=tt.d;i<=9;i++)
    {
      ttt.x=tt.x+i;
      ttt.y=tt.y+i*i;
      if (ttt.x>810||ttt.y>8100||ttt.l>100)
        continue;
      ttt.d=i;
      if (f[ttt.x][ttt.y]==-1)
      {
        q.push(ttt);
        f[ttt.x][ttt.y]=ttt.l;
        ff[ttt.x][ttt.y]=ttt.d;
      }
      // else
      // if (f[ttt.x][ttt.y]>=ttt.l)
      //   if (bi(ttt.x,ttt.y,ttt.x,ttt.y,ttt.d,ff[ttt.x][ttt.y])==-1)
      //   {
      //     ff[ttt.x][ttt.y]=ttt.d;
      //     f[ttt.x][ttt.y]=ttt.l;
      //     q.push(ttt);
      //   }
    }
  }
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&n,&m);
    if (n>900||m>8100)
    {
      cout<<"No solution"<<endl;
      continue;
    }
    if (f[n][m]==-1)
      cout<<"No solution"<<endl;
    else
      shuchu(f[n][m],ff[n][m]);
  }
  return 0;
}

    
      
