/*
ID: mfs6174
PROG: uestc1480 WFS
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

struct D
{
  int x,y;
};

int zz,zu,i,j,k,t,n,m,mm,s,e,nn;
bool ff[300][300],fl,fff[300][300];
int f[300][300];
D dui[300*300],d;
char tc;

void push(int x,int y,int z)
{
  D t;
  ff[x][y]=true;
  f[x][y]=z+1;
  e=(e+1)%nn;
  t.x=x;t.y=y;
  dui[e]=t;
}

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>m;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        cin>>tc;
        if (tc=='0')
          fff[i][j]=true;
        else
          fff[i][j]=false;
      }
    memset(ff,0,sizeof(ff));
    memset(f,0,sizeof(f));
    s=e=0;
    e++;
    dui[e].x=dui[e].y=1;
    ff[1][1]=true;
    nn=n*n;
    fl=false;
    while (s!=e)
    {
      s=(s+1)%nn;
      d=dui[s];
      if ((d.x==n)&&(d.y==m))
      {
        fl=true;
        break;
      }
      if ((d.x-1>=1)&&(!ff[d.x-1][d.y])&&(fff[d.x-1][d.y]))
        push(d.x-1,d.y,f[d.x][d.y]);
      if ((d.x+1<=n)&&(!ff[d.x+1][d.y])&&(fff[d.x+1][d.y]))
        push(d.x+1,d.y,f[d.x][d.y]);
      if ((d.y-1>=1)&&(!ff[d.x][d.y-1])&&(fff[d.x][d.y-1]))
        push(d.x,d.y-1,f[d.x][d.y]);
      if ((d.y+1<=m)&&(!ff[d.x][d.y+1])&&(fff[d.x][d.y+1]))
        push(d.x,d.y+1,f[d.x][d.y]);
      
    }
    if (!fl)
      f[n][m]=-1;
    cout<<"Case #"<<zz<<": "<<f[n][m]<<endl;
  }
}

      

