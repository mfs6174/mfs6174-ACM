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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

const double INF=1e200;
const double Ling=1e-8;
bool fail;

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

// 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0 
struct L           
{ 
   double a; 
   double b; 
   double c; 
   L(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;} 
};

struct RECT
{
  P zs,yx;
  double w,h;
  RECT(){}
  RECT(P a,P b)
  {
    zs=a;
    yx=b;
    w=yx.x-zs.x;
    h=zs.y-yx.y;
  }
  P mid()
  {
    return P(zs.x+w/2,yx.y+h/2);
  }
  RECT sub(int x,int y,int fks)
  {
    return RECT(P(zs.x+(x-1)*w/fks,yx.y+y*h/fks),P(zs.x+x*w/fks,yx.y+(y-1)*h/fks));
  }
};

inline double dst(P p1,P p2)                
{ 
  return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
}

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

bool scwa(P &a,P &b)
{   //与射线相交判断 a,b是线段两端点  
  P tmp(-1.0, 0.0);//其实是坐标轴  
  return (a^b) * (a^tmp) > 0.0  
    && (a ^tmp) * (tmp^b) > 0.0;  
}

inline bool os(SEG &l,P &p) //点在线段上
{ 
  return( (cwz(cha(l.s,l.e,p))==0) &&( ( cwz((p.x-l.s.x)*(p.x-l.e.x))<=0 )&&( cwz((p.y-l.s.y)*(p.y-l.e.y))<=0 ) ) ); 
}

inline P scp(SEG l1,SEG l2) //线段交点 不考虑（部分）重合的数据 fail表示不相交
{
  P rr;
  rr=lcp(l1.s,l1.e,l2.s,l2.e);
  if (!fail)
    if (os(l1,rr)&&os(l2,rr))
      return rr;
  fail=true;
  return P(0,0);
}

inline bool scwl(SEG s,const SEG l)//线段与直线相交判度
{
  double d1,d2;
  d1=cha(l.s,s.s,l.e);
  d2=cha(l.s,s.e,l.e);
  if( (d1>Ling&&d2<-Ling || d1<-Ling&&d2>Ling) ) //跨立试验
    return true ;
  if( abs(d1)<Ling || abs(d2)<Ling )//这里特判了共线的情况，共线认为是相交
    return true ;
  return false ;
}

inline bool cmp(const P &a, const P &b)
{ //中心极角排序 从-PI到-PI内   
  return atan2(a.y, a.x) > atan2(b.y, b.x);
}

inline double polys(P shu[],int n)//多边形面积
{
  int i;
  double ss;
  for (i=1;i<n;i++)
    ss+=shu[i]^shu[i+1];
  ss+=shu[n]^shu[1];
  if (ss<0) ss=-ss;
  ss/=2;
  return ss;
}


