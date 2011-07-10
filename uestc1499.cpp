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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int n,f;
  int dao[1505];
};

int i,j,k,t,n,m,mm,c;
D shu[1505];
char tc;
bool ff[1505],fl;
int gen[1505],f[1505][2],mmd[1505][2];

void floodfill(int x,int fu)
{
  int i;
  if (ff[x])
    return;
  ff[x]=true;
  if (fl)
  {
    c++;
    gen[c]=x;
    fl=false;
  }
  else
  {
    shu[x].f=fu;
  }
  for (i=1;i<=shu[x].n;i++)
    floodfill(shu[x].dao[i],x);
}

void mfs(int x)
{
  int i,he=0,he1=0;
  bool fl=false;
  for (i=1;i<=shu[x].n;i++)
    if (shu[x].dao[i]!=shu[x].f)
    {
      fl=true;
      mfs(shu[x].dao[i]);
      he+=min(f[shu[x].dao[i]][0],f[shu[x].dao[i]][1]);
      he1+=f[shu[x].dao[i]][1];
    }
  if (!fl)
  {
    f[x][0]=0;
    f[x][1]=1;
    return;
  }
  f[x][1]=he+1;
  f[x][0]=he1;
}

int main()
{
  for (i=0;i<=1500;i++)
  {
    mmd[i][0]=maxlongint;
    mmd[i][1]=maxlongint;
  }
  //freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    memset(shu,0,sizeof(shu));
    c=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d:(%d)",&t,&m);
      for (j=1;j<=m;j++)
      {
        shu[t].n++;
        scanf("%d",&(shu[t].dao[shu[t].n]));
        shu[shu[t].dao[shu[t].n]].n++;
        shu[shu[t].dao[shu[t].n]].dao[shu[shu[t].dao[shu[t].n]].n]=t;
      }
    }
    memset(ff,0,sizeof(ff));
    for (i=0;i<n;i++)
    {
      fl=true;
      floodfill(i,i);
    }
    mm=0;
    memcpy(f,mmd,sizeof(f));
    for (i=1;i<=c;i++)
    {
      mfs(gen[i]);
      mm+=min(f[gen[i]][0],f[gen[i]][1]);
    }
    cout<<mm<<endl;
  }
  return 0;
}

    
      
  

