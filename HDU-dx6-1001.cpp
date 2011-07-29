/*
ID: mfs6174
PROG: POJ2352
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

#define MAXN 70000
double shu[MAXN];
int f[MAXN];
int n,cc;

//f[x]表示x-lowbit+1 到 x的和
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void bitinit()
{
  memset(f,0,sizeof(f));
  memset(shu,0,sizeof(shu));
}

void upc(int f[],int x,int d)
{
  while (x<=cc)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}
void upc(double f[],int x,double d)
{
  if (x==0)
    return;
  while (x<=cc)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

int downs(int f[],int x)
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}
double downs(double f[],int x)
{
  double s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

struct C
{
  int x,y,s,f,p;
  bool operator <(const C &p) const
  {
    if (y!=p.y)
      return y<p.y;
    else
      return x<p.x;
  }
};
struct D
{
  int x,y,s,p;
  double d;
  bool operator <(const D &p) const
  {
    if (y!=p.y)
      return y<p.y;
    else
      return x<p.x;
  }
};

struct T
{
  int x,f,s;
};


int i,j,k,t,xx,yy,m,p;
D xing[61000];
C cha[420000];
int ge[210000];
double deng[210000];
T tmp[300000];

bool cmp(const T &a,const T &b)
{
  return a.x<b.x;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    memset(ge,0,sizeof(ge));
    memset(deng,0,sizeof(deng));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%lf",&xing[i].x,&xing[i].y,&xing[i].d);
      xing[i].s=i;
      tmp[i].x=xing[i].x;
      tmp[i].f=1;
      tmp[i].s=i;
    }
    int c=0;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d%d",&cha[i].x,&cha[i].y,&cha[i+m].x,&cha[i+m].y);
      cha[i].s=cha[m+i].s=i;
      cha[i].f=0;cha[m+i].f=1;
      c++;
      tmp[c+n].x=cha[i].x;
      tmp[c+n].f=2;tmp[c+n].s=i;
      c++;
      tmp[c+n].x=cha[m+i].x;
      tmp[c+n].f=2;tmp[c+n].s=m+i;
    }
    sort(&tmp[1],&tmp[n+c+1],cmp);
    t=-maxlongint;
    cc=0;
    for (i=1;i<=c+n;i++)
    {
      if (tmp[i].x!=t)
      {
        cc++;
        t=tmp[i].x;
      }
      if (tmp[i].f==1)
        xing[tmp[i].s].p=cc;
      else
        cha[tmp[i].s].p=cc;
    }
    sort(&xing[1],&xing[n+1]);
    sort(&cha[1],&cha[2*m+1]);
    bitinit();
    p=1;
    for (i=1;i<=n;i++)
    {
      while (xing[i].y>=cha[p].y&&xing[i].x>cha[p].x&&p<=2*m)
      {
        if (cha[p].f)
        {
          ge[cha[p].s]+=downs(f,cha[p].p);
          deng[cha[p].s]+=downs(shu,cha[p].p);
        }
        else
        {
          ge[cha[p].s]-=downs(f,cha[p].p-1);
          deng[cha[p].s]-=downs(shu,cha[p].p-1);
        }
        p++;
      }
      upc(f,xing[i].p,1);
      upc(shu,xing[i].p,xing[i].d);
    }
    while (p<=2*m)
    {
     if (cha[p].f)
        {
          ge[cha[p].s]+=downs(f,cha[p].p);
          deng[cha[p].s]+=downs(shu,cha[p].p);
        }
        else
        {
          ge[cha[p].s]-=downs(f,cha[p].p-1);
          deng[cha[p].s]-=downs(shu,cha[p].p-1);
        }
        p++;
    }
    for (i=1;i<=m;i++)
    {
      printf("%.2lf",deng[i]);
      cout<<'/'<<ge[i]<<endl;
    }
  }
  return 0;
}
