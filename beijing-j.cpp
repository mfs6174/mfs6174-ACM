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
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,mm,cc;
int f[20][2000];
bool ff[20][2000];
unsigned wei[20];
unsigned dd;
int jia[20];
int M[20][20],B[20][20];
int yu[1200],de[20][1200];
unsigned cao[1200];

void dfs(int x,unsigned d)
{
  int i,j;
  if (x>n)
  {
    cc++;
    cao[cc]=d;
    for (j=1;j<=m;j++)
      for (i=1;i<=n;i++)
        if (d&wei[i])
          de[j][d]+=M[i][j];
    for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
        if ((d&wei[i])&&(d&wei[j]))
          yu[d]+=B[i][j];
    return;
  }
  dfs(x+1,d);
  dfs(x+1,d|wei[x]);
}

void mfs(int x,unsigned d)
{
  if (ff[x][d])
    return;
  ff[x][d]=true;
  if (x>m)
  {
    f[x][d]=0;
    return;
  }
  vector<int> tt;
  tt.clear();
  int i,j,ss=0,rr=0;
  unsigned t;
  for (i=1;i<=n;i++)
    if (d&wei[i])
    {
      tt.push_back(i);
      ss++;
    }
  rr=-ss*jia[x];
  if (x)
  {
    rr+=yu[d];
    rr+=de[x][d];
  }
  int mm=-maxlongint;
  for (i=1;i<=cc;i++)
  {
    mfs(x+1,d&cao[i]);
    mm=max(mm,f[x+1][d&cao[i]]);
  }
  f[x][d]=mm+rr;
}

int main()
{
  freopen("ti.in","r",stdin);
  wei[1]=1;
  for (i=2;i<=12;i++)
    wei[i]=wei[i-1]<<1;
  while (scanf("%d%d",&n,&m)!=EOF&&n)
  {
    for (i=0;i<=n;i++)
      for (j=0;j<=1200;j++)
        f[i][j]=-maxlongint;
    jia[0]=0;cc=0;
    memset(yu,0,sizeof(yu));
    memset(de,0,sizeof(de));
    for (i=1;i<=m;i++)
      scanf("%d",&jia[i]);
    memset(M,0,sizeof(M));
    memset(B,0,sizeof(B));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&M[i][j]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&B[i][j]);
    mm=-maxlongint;
    dd=0;
    for (i=1;i<=n;i++)
      dd=dd|wei[i];
    dfs(1,0);
    //f[0][dd]=0;
    memset(ff,0,sizeof(ff));
    mfs(0,dd);
    mm=f[0][dd];
    if (mm>0)
      cout<<mm<<endl;
    else
      cout<<"STAY HOME"<<endl;
  }
  return 0;
}

