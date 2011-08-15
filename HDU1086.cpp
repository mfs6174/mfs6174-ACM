/*
ID: mfs6174
PROG: 判断线段相交
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

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

inline double cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

inline P lcp(P aa, P ad, P ba, P bd)//返回fail如果true说明平行或重合再交叉相减叉积即可
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

inline bool os(SEG &l,P &p) 
{ 
  return( (cwz(cha(l.s,l.e,p))==0) &&( ( cwz((p.x-l.s.x)*(p.x-l.e.x))<=0 )&&( cwz((p.y-l.s.y)*(p.y-l.e.y))<=0 ) ) ); 
}

int i,j,t,n,m,mm;
SEG shu[110];
P rr;

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF&&n)
  {
    mm=0;
    for (i=1;i<=n;i++)
      shu[i].input();
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        rr=lcp(shu[i].s,shu[i].e,shu[j].s,shu[j].e);
        if (!fail)
          if (os(shu[i],rr)&&os(shu[j],rr))
            mm++;
      }
    cout<<mm<<endl;
  }
  return 0;
}

