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
#include<ctime>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int r,h;
  bool operator <(const D &x) const
  {
    return r>x.r;
  }
};

int i,j,k,t,n,m,zz,zu,w,l,tk;
D shu[1100];
int dui[1000],f[1100],cf[1100];
double pt[1100][2];
bool yong[1100],cyong[1100];
int tt[10];


void myoutput(int zz)
{
  int i;
  printf("Case #%d:",zz);
  for (i=1;i<=n;i++)
    printf(" %.2lf %.2lf",pt[dui[i]][1],pt[dui[i]][0]);
  printf("\n");
}

inline int myrandom(int x)
{
  return rand()%x;
}

inline double dist(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline bool check(int z,int p,double x,double y)
{
  int i;
  for (i=1;i<=z;i++)
    if (dist(pt[f[i]][0],pt[f[i]][1],x,y)<shu[p].r+shu[f[i]].r)
      return false;
  return true;
}

int main()
{
  srand((int)time(NULL));
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d%d",&n,&w,&l);
    for (i=1;i<=n;i++)
    {
      sf("%d",&(shu[i].r));
      shu[i].h=i;
    }
    sort(&shu[1],&shu[n+1]);
    memset(yong,0,sizeof(yong));
    for (i=1;i<=n;i++)
      dui[shu[i].h]=i;
    k=0;
    pt[1][0]=pt[1][1]=0;
    yong[1]=true;
    k++;
    f[k]=1;
    tt[1]=tt[3]=shu[1].r;
    for (i=2;i<=n;i++)
      if (check(k,i,0,w)&&(!yong[i]))
      {
        pt[i][0]=0;pt[i][1]=w;
        yong[i]=true;
        k++;
        f[k]=i;
        tt[4]=tt[5]=shu[i].r;
        break;
      }
    for (i=2;i<=n;i++)
      if (check(k,i,l,w)&&(!yong[i]))
      {
        pt[i][0]=l;pt[i][1]=w;
        yong[i]=true;
        k++;
        f[k]=i;
        tt[6]=tt[7]=shu[i].r;
        break;
      }
    for (i=2;i<=n;i++)
      if (check(k,i,l,0)&&(!yong[i]))
      {
        pt[i][0]=l;pt[i][1]=0;
        yong[i]=true;
        k++;
        f[k]=i;
        tt[2]=tt[8]=shu[i].r;
        break;
      }
    if (k>=n)
    {
      myoutput(zz);
      continue;
    }
    j=tt[1]+shu[n].r;
    while (j<=l-tt[2]-shu[n].r)
    {
      for (i=2;i<=n;i++)
        if (check(k,i,j,0)&&(!yong[i]))
        {
          pt[i][0]=j;pt[i][1]=0;
          yong[i]=true;
          k++;
          f[k]=i;
          j=j+shu[i].r+shu[n].r;
          break;
        }
      if (i>n)
        break;
    }
    j=tt[3]+shu[n].r;
    while (j<=w-tt[4]-shu[n].r)
    {
      for (i=2;i<=n;i++)
        if (check(k,i,0,j)&&(!yong[i]))
        {
          pt[i][0]=0;pt[i][1]=j;
          yong[i]=true;
          k++;
          f[k]=i;
          j=j+shu[i].r+shu[n].r;
          break;
        }
      if (i>n)
        break;
    }
    j=tt[8]+shu[n].r;
    while (j<=w-tt[7]-shu[n].r)
    {
      for (i=2;i<=n;i++)
        if (check(k,i,l,j)&&(!yong[i]))
        {
          pt[i][0]=l;pt[i][1]=j;
          yong[i]=true;
          k++;
          f[k]=i;
          j=j+shu[i].r+shu[n].r;
          break;
        }
      if (i>n)
        break;
    }
    j=tt[5]+shu[n].r;
    while (j<=l-tt[6]-shu[n].r)
    {
      for (i=2;i<=n;i++)
        if (check(k,i,j,w)&&(!yong[i]))
        {
          pt[i][0]=j;pt[i][1]=w;
          yong[i]=true;
          k++;
          f[k]=i;
          j=j+shu[i].r+shu[n].r;
          break;
        }
      if (i>n)
        break;
    }
    if (k>=n)
    {
      myoutput(zz);
      continue;
    }
    memcpy(cyong,yong,sizeof(cyong));
    memcpy(cf,f,sizeof(cf));
    tk=k;
    while (1)
    {
      memcpy(yong,cyong,sizeof(cyong));
      memcpy(f,cf,sizeof(cf));
      k=tk;
      int x,y;
      for (i=2;i<=n;i++)
      {
        if (yong[i])
          continue;
        while (1)
        {
          x=myrandom(l);
          y=myrandom(w);
          if (check(k,i,x,y))
          {
            pt[i][0]=x;pt[i][1]=y;
            yong[i]=true;
            k++;
            f[k]=i;
            break;
          }
        }
      }
      myoutput(zz);
      break;
    }
  }
  return 0;
}

 
 
    



