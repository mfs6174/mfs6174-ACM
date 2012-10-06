/*
ID: mfs6174
PROG: ustc 0529 G
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
  int s,x,d;
  bool w,b;
  bool operator <(const D &t) const
  {
    return s<t.s||x<t.x||d<t.d||(w^t.w)||(b^t.b);
  }
};

int i,j,k,n,m,t,mm,she,lai,a,b,cc;
int tu[310][310];
D tai[310][310];
char tc;

void dfs(int x,int y,int s,bool w,bool b)
{
  if (cc>500000)
    return;
  if (s>700)
    return;
  if (tu[x][y]==-2)
    w=true;
  if (tu[x][y]==-3)
    b=true;
  if (tu[x][y]==-1)
  {
    mm=min(mm,s);
    return;
  }
  D tmp;
  tmp.s=s;
  tmp.w=w;
  tmp.b=b;
  tmp.x=lai;
  tmp.d=she;
  if (!(tmp<tai[x][y]))
    return;
  cc++;
  tai[x][y]=tmp;
  if (x-1>0)
  {
    if (tu[x-1][y]<=0)
      dfs(x-1,y,s+1,w,b);
    else
    if (tu[x-1][y]==1)
    {
      lai--;
      tu[x-1][y]=0;
      dfs(x-1,y,s+2,w,b);
      tu[x-1][y]=1;
      lai++;
    }
    else
    if (tu[x-1][y]==2&&w)
    {
      she--;
      tu[x-1][y]=0;
      dfs(x-1,y,s+2,w,b);
      tu[x-1][y]=2;
      she++;
    }
    else
    if (tu[x-1][y]==3&&b)
      dfs(x-1,y,s+1,w,b);
  }
  if (x+1<=n)
  {
    if (tu[x+1][y]<=0)
    {
      dfs(x+1,y,s+1,w,b);
    }
    else
    if (tu[x+1][y]==1)
    {
      lai--;
      tu[x+1][y]=0;
      dfs(x+1,y,s+2,w,b);
      tu[x+1][y]=1;
      lai++;
    }
    else
    if (tu[x+1][y]==2&&w)
    {
      she--;
      tu[x+1][y]=0;
      dfs(x+1,y,s+2,w,b);
      tu[x+1][y]=2;
      she++;
    }
    else
    if (tu[x+1][y]==3&&b)
    {
      dfs(x+1,y,s+1,w,b);
    }
  }
  if (y-1>0)
  {
    if (tu[x][y-1]<=0)
    {
      dfs(x,y-1,s+1,w,b);
    }
    else
    if (tu[x][y-1]==1)
    {
      lai--;
      tu[x][y-1]=0;
      dfs(x,y-1,s+2,w,b);
      tu[x][y-1]=1;
      lai++;
    }
    else
    if (tu[x][y-1]==2&&w)
    {
      she--;
      tu[x][y-1]=0;
      dfs(x,y-1,s+2,w,b);
      tu[x][y-1]=2;
      she++;
    }
    else
    if (tu[x][y-1]==3&&b)
    {
      dfs(x,y-1,s+1,w,b);
    }
  }
  if (y+1<=m)
  {
    if (tu[x][y+1]<=0)
    {
      dfs(x,y+1,s+1,w,b);
    }
    else
    if (tu[x][y+1]==1)
    {
      lai--;
      tu[x][y+1]=0;
      dfs(x,y+1,s+2,w,b);
      tu[x][y+1]=1;
      lai++;
    }
    else
    if (tu[x][y+1]==2&&w)
    {
      she--;
      tu[x][y+1]=0;
      dfs(x,y+1,s+2,w,b);
      tu[x][y+1]=2;
      she++;
    }
    else
    if (tu[x][y+1]==3&&b)
    {
      dfs(x,y+1,s+1,w,b);
    }
  }
}

    
int main()
{
  cin>>n>>m;
  while (n)
  {
    lai=she=0;
    mm=maxlongint;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        tai[i][j].s=maxlongint;
        cin>>tc;
        if (tc=='Y')
        {
          a=i;b=j;
          tu[i][j]=0;
          continue;
        }
        if (tc=='P')
        {
          tu[i][j]=-1;
          continue;
        }
        if (tc=='L')
        {
          tu[i][j]=1;
          lai++;
          continue;
        }
        if (tc=='S')
        {
          tu[i][j]=2;
          she++;
          continue;
        }
        if (tc=='R')
          tu[i][j]=3;
        if (tc=='B')
          tu[i][j]=-3;
        if (tc=='W')
          tu[i][j]=-2;
        if (tc=='E')
          tu[i][j]=0;
        
      }
    for (i=1;i<=n;i++)
      for (j=1;j<m;j++)
      {
        tai[i][j].x=lai;
        tai[i][j].d=she;
        tai[i][j].b=false;
        tai[i][j].w=false;
      }
    cc=0;
    dfs(a,b,0,false,false);
    if (mm==maxlongint)
      mm=-1;
    cout<<mm<<endl;
    cin>>n>>m;
  }
}

