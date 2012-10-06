/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


int i,j,k,t,n,m,zu,zz,my,h,cst;
int dd[200][200],d[200][200];
int dui[20];
int qian[20][2];
unsigned int st,tt,ma;
int ff[17][80000];
queue<unsigned int> Q;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d%d",&n,&m,&my);
    memset(d,0,sizeof(d));
    memset(dd,0,sizeof(dd));
    for (i=1;i<=101;i++)
      for (j=1;j<=101;j++)
        if (i!=j)
          dd[i][j]=maxlongint;
    for (i=1;i<=m;i++)
    {
      sf("%d%d%d",&j,&k,&t);
      d[j][k]=t;
      d[k][j]=t;
      dd[j][k]=dd[k][j]=d[j][k];
    }
    sf("%d",&h);
    for (i=1;i<=h;i++)
    {
      sf("%d%d%d",&t,&qian[i][0],&qian[i][1]);
      dui[i]=t;
    }
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          if (dd[i][k]!=maxlongint&&dd[k][j]!=maxlongint)
            dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
    memset(ff,-1,sizeof(ff));
    for (i=1;i<=h;i++)
    {
      cst=dd[1][dui[i]]+qian[i][1];
      if (cst<=my)
      {
        tt=0^(1<<(i-1));
        ff[i][tt]=my-cst+qian[i][0];
      }
    }
    ma=0;
    for (i=1;i<=h;i++)
      ma=(ma<<1)+1;
    for (k=1;k<h;k++)
    {
      for (st=1;st<=ma;st++)
        for (j=1;j<=h;j++)
        {
          if (ff[j][st]==-1)
            continue;
          for (i=1;i<=h;i++)
            if ((st&(1<<(i-1)))==0)
            {
              cst=dd[dui[j]][dui[i]]+qian[i][1];
              if (cst<=ff[j][st])
              {
                tt=st^(1<<(i-1));
                ff[i][tt]=max(ff[i][tt],ff[j][st]-cst+qian[i][0]);
              }
            }
        }
    }
    bool flag=false;
    for (i=1;i<=h;i++)
      if (ff[i][ma]>=dd[dui[i]][1])
        flag=true;
    if (flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}

