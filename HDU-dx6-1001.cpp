/*
ID: mfs6174
PROG: HDU3890
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
#define MAXT 500000

double shu[MAXT];
int f[MAXT];
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

void upc(int x,double d)
{
  // if (x==0)
  //   return;
  while (x<=cc)
  {
    shu[x]+=d;
    f[x]++;
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
  int x,y;
};
struct D
{
  int x,y;
  double d;
};

int i,j,k,t,m,p;
D xing[MAXN];
C cha[420000];
int chap[420000],xingp[MAXN];
int ge[210000];
double deng[210000];
map<int,int> hash;

inline bool cmpx(const int &a,const int &b)
{
  return xing[a].y<xing[b].y;
}
inline bool cmpc(const int &a,const int &b)
{
  return cha[a].y<cha[b].y;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    memset(ge,0,sizeof(ge));
    memset(deng,0,sizeof(deng));
    hash.clear();
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%lf",&xing[i].x,&xing[i].y,&xing[i].d);
      xingp[i]=i;
      hash[xing[i].x]=1;
    }
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d%d",&cha[i].x,&cha[i].y,&cha[i+m].x,&cha[i+m].y);
      chap[i]=i;chap[i+m]=i+m;
      cha[i].x--;cha[i].y--;
      hash[cha[i].x]=1;hash[cha[i+m].x]=1;
    }
    i=0;
    for (map<int,int>::iterator it=hash.begin();it!=hash.end();it++)
    {
      i++;
      (*it).second=i;
    }
    cc=i;
    sort(&xingp[1],&xingp[n+1],cmpx);
    sort(&chap[1],&chap[2*m+1],cmpc);
    bitinit();
    p=1;
    for (i=1;i<=n;i++)
    {
      while (xing[xingp[i]].y>cha[chap[p]].y&&p<=2*m)
      {
        if (chap[p]<=m)
        {
          ge[chap[p]]-=(downs(f,hash[cha[chap[p]+m].x])-downs(f,hash[cha[chap[p]].x]));
          deng[chap[p]]-=(downs(shu,hash[cha[chap[p]+m].x])-downs(shu,hash[cha[chap[p]].x]));
        }
        else
        {
          ge[chap[p]-m]+=(downs(f,hash[cha[chap[p]].x])-downs(f,hash[cha[chap[p]-m].x]));
          deng[chap[p]-m]+=(downs(shu,hash[cha[chap[p]].x])-downs(shu,hash[cha[chap[p]-m].x]));
        }
        p++;
      }
      upc(hash[xing[xingp[i]].x],xing[xingp[i]].d);
    }
    while (p<=2*m)
    {
      if (chap[p]<=m)
      {
        ge[chap[p]]-=(downs(f,hash[cha[chap[p]+m].x])-downs(f,hash[cha[chap[p]].x]));
        deng[chap[p]]-=(downs(shu,hash[cha[chap[p]+m].x])-downs(shu,hash[cha[chap[p]].x]));
      }
      else
      {
        ge[chap[p]-m]+=(downs(f,hash[cha[chap[p]].x])-downs(f,hash[cha[chap[p]-m].x]));
        deng[chap[p]-m]+=(downs(shu,hash[cha[chap[p]].x])-downs(shu,hash[cha[chap[p]-m].x]));
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
