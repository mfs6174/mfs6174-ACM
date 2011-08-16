/*
ID: mfs6174
PROG: 计算几何基本函数
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

const double INF=1e200;
const double Ling=1e-8;
bool fail;
bool fl;

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

struct P 
{ 
  double x; 
  double y;
  //constructor
  P(double a=0, double b=0) 
  { x=a; y=b;}
  P operator+(const P &b) const
  {  
    return P(x + b.x, y + b.y);  
  }
  P operator - (const P &b) const
  {  
    return P(x - b.x, y - b.y);  
  }  
  bool operator<(const P &b) const//a在b逆时针 
  {   
    return x * b.y < y * b.x;  
  }
  bool operator==(const P &b) const
  {
    return ((cwz(x-b.x)==0)&&(cwz(y-b.y)==0));
  }
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  double operator *(const P &b) const
  {
    return x*b.x+y*b.y;
  }
  void input()
  {
    scanf("%lf%lf",&x,&y);
  }

}; 

struct SEG 
{ 
  P s,e; 
  SEG(P a=P(0,0), P b=P(0,0)) { s=a; e=b;}
  void input()
  {
    s.input();e.input();
  }
};

inline double cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

inline bool scwl(SEG s,const SEG l)
{
  double d1,d2;
  d1=cha(l.s,s.s,l.e);
  d2=cha(l.s,s.e,l.e);
  if( (d1>Ling&&d2<-Ling || d1<-Ling&&d2>Ling) )
    return true ;
  if( abs(d1)<Ling || abs(d2)<Ling )//这里特判了共线的情况
    return true ;
  return false ;
}

int i,j,k,t,n,m,aa,bb;
int zz,zu;
SEG shu[120],nw;
P dd;

bool check(const SEG &ta)
{
  int i;
  for (i=1;i<=n;i++)
  {
    if (i==aa||i==bb)
      continue;
    if (!scwl(shu[i],ta))
      return false;
  }
  return true;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    fl=false;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      shu[i].input();
    if (n==1||n==2)
    {
      cout<<"Yes!"<<endl;
      continue;
    }
    for (i=1;i<=n;i++)
    {
      //if (!(shu[i].s==shu[i].e))
      //  fl=fl||check(shu[i]);
      if (fl)
        break;
      dd=shu[i].s;
      aa=i;
      for (j=i;j<=n;j++)
      {
        bb=j;
        if (!(dd==shu[j].s))
          fl=fl||check(SEG(dd,shu[j].s));
        if (!(dd==shu[j].e))
          fl=fl||check(SEG(dd,shu[j].e));
      }
      dd=shu[i].e;
      for (j=i;j<=n;j++)
      {
        bb=j;
        if (!(dd==shu[j].s))
          fl=fl||check(SEG(dd,shu[j].s));
        if (!(dd==shu[j].e))
          fl=fl||check(SEG(dd,shu[j].e));
      }
    }
    if (fl)
      cout<<"Yes!"<<endl;
    else
      cout<<"No!"<<endl;
  }
  return 0;
}
