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
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
}; 
struct LINESEG 
{ 
	POINT s; 
	POINT e; 
	LINESEG(POINT a, POINT b) { s=a; e=b;} 
	LINESEG() { } 
}; 

// 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0 
struct L           
{ 
   double a; 
   double b; 
   double c; 
   L(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;} 
};

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

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

inline bool cmp(const P &a, const P &b)
{ //中心极角排序 从-PI到-PI内   
  return atan2(a.y, a.x) > atan2(b.y, b.x);
}


