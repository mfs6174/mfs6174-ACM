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

P lcp(P aa, P ad, P ba, P bd)//返回fail如果true说明平行或重合再交叉相减叉积即可
{ // 求直线交点  
  ad = ad - aa;  
  bd = bd - ba;  
  double tmp = bd ^ ad;
  fail=false;
  if (cwz(tmp)==0)
  {
    fail=true;
    return P(0,0);
  }
  else
    return P((ad.x * bd.x * (ba.y - aa.y) + aa.x * bd.x * ad.y - ba.x * ad.x * bd.y) / tmp,  
             (ad.y * bd.y * (aa.x - ba.x) + ba.y * ad.y * bd.x - aa.y * bd.y * ad.x) / tmp);  
}  

inline bool os(SEG &l,P &p) //点在线段上
{ 
  return( (cwz(cha(l.s,l.e,p))==0) &&( ( cwz((p.x-l.s.x)*(p.x-l.e.x))<=0 )&&( cwz((p.y-l.s.y)*(p.y-l.e.y))<=0 ) ) ); 
}

inline P scp(const SEG &l1,SEG &l2) //线段交点 不考虑（部分）重合的数据 fail表示不相交
{
  P rr;
  rr=lcp(l1.s,l1.e,l2.s,l2.e);
  if (!fail)
  {
    if (os(l2,rr))
      return rr;
  }
  else
  {
    if (cwz((l2.e-l1.s)^(l2.s-l1.e))==0)
    {
      fail=false;
      return rr;
    }
  }
  fail=true;
  return P(0,0);
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
    scp(ta,shu[i]);
    if (fail)
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
      for (j=1;j<=n;j++)
      {
        bb=j;
        if (!(dd==shu[j].s))
          fl=fl||check(SEG(dd,shu[j].s));
        if (!(dd==shu[j].e))
          fl=fl||check(SEG(dd,shu[j].e));
      }
      dd=shu[i].e;
      for (j=1;j<=n;j++)
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
