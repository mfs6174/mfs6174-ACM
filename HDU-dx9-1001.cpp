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
#define sf scanf
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

double dd[50][50];
int i,j,k,t,n,m,zz,zu,xx,yy;
int dian[50][2];
double f[1200000];
//int ff[1200000];
unsigned st;
unsigned kk[50];
bool fl[1200000];
double jd[1200000];

inline double suan(int x,int y,int xx,int yy)
{
  return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

void dfs(unsigned d)
{
  // if (x>2*n)
  //   return;
  int i;
  if (fl[d])
    return;
  fl[d]=true;
  unsigned tt;
  int x;
  for (x=1;x<=2*n;x++)
    if (kk[x]&d)
    {
      for (i=x+1;i<=2*n;i++)
        if (kk[i]&d)
        {
          tt=d^kk[x];
          tt=tt^kk[i];
          dfs(tt);
          f[d]=min(f[d],f[tt]+min(dd[0][x]+dd[x][i],dd[0][i]+dd[i][x]));
        }
      break;
    }
}

int main()
{
  for (i=0;i<=1100000;i++)
    jd[i]=(double)maxlongint;
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  kk[1]=1;
  for (i=2;i<=22;i++)
    kk[i]=kk[i-1]<<1;
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&xx,&yy);
    sf("%d",&n);
    for (i=1;i<=n;i++)
    {
      sf("%d%d",&dian[i][0],&dian[i][1]);
      sf("%d%d",&dian[i+n][0],&dian[i+n][1]);
    }
    st=0;
    for (i=1;i<=2*n;i++)
    {
      dd[0][i]=suan(xx,yy,dian[i][0],dian[i][1]);
      st=st|kk[i];
    }
    for (i=1;i<=2*n;i++)
      for (j=1;j<=2*n;j++)
        dd[i][j]=suan(dian[i][0],dian[i][1],dian[j][0],dian[j][1]);
    memset(fl,0,sizeof(fl));
    memcpy(f,jd,sizeof(f));
    //    for (i=1;i<=2*n;i++)
      fl[0]=true;
    f[0]=0;
    dfs(st);
    printf("Case #%d: %.2lf\n",zz,f[st]);
  }
  return 0;
}
    
