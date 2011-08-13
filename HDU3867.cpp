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
#include<set>
#define sf scanf
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

const double INF=1e200;
const double Ling=1e-7;

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
  bool operator<(const P &b) const//逆时针 
  {   
    return x * b.y < y * b.x;  
  }
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  double dis()
  {
    return sqrt(x*x+y*y);
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

P lcp(P aa, P ad, P ba, P bd)
{ // 求直线交点  
  ad = ad - aa;  
  bd = bd - ba;  
  double tmp = bd ^ ad;  
  return P((ad.x * bd.x * (ba.y - aa.y) + aa.x * bd.x * ad.y - ba.x * ad.x * bd.y) / tmp,  
               (ad.y * bd.y * (aa.x - ba.x) + ba.y * ad.y * bd.x - aa.y * bd.y * ad.x) / tmp);  
}  

P duan[21000],yuan,ling,dang,at,bt;
struct D
{
  int s,t;
  int tp,h;
  D(int _s=0, int _t=0, int _ty = 0, int _id = 0)  
        : s(_s), t(_t), tp(_ty), h(_id) {} 
  bool operator <(const D &b) const
  {
    if (s==b.s&&t==b.t)
      return false;
    P d1=lcp(ling,dang,duan[s],duan[t]),d2=lcp(ling,dang,duan[b.s],duan[b.t]);
    return d1.dis()<d2.dis();
  }
};

inline bool cmp(const D &a,const D &b)
{
  return cha(ling,duan[a.s],duan[b.s])<0;
}

D ss[21000];
set<D> sc;
bool fl[11000];

int i,j,k,t,n,m;

bool scwa(D &a)
{   //与射线相交判断   good 以前不知道的东西  
    P tmp(-1.0, 0.0);  
    return (duan[a.s] ^ duan[a.t]) * (duan[a.s] ^ tmp) > 0.0  
        && (duan[a.s] ^ tmp) * (tmp ^ duan[a.t]) > 0.0;  
}  

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF)
  {
    sc.clear();
    memset(fl,0,sizeof(fl));
    scanf("%lf%lf",&yuan.x,&yuan.y);
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&at.x,&at.y);
      scanf("%lf%lf",&bt.x,&bt.y);
      if (bt<at)
      {
        dang=at;
        at=bt;
        bt=dang;
      }
      duan[i]=at;duan[i+n]=bt;
      ss[i]=D(i,i+n,0,i);
      ss[i+n]=D(i+n,i,1,i);
    }
    sort(&ss[1],&ss[2*n+1],cmp);
    for (i=1;i<=2*n;i++)
    {
      dang=duan[ss[i].s];
      if (ss[i].tp==0&&scwa(ss[i]))
        sc.insert(ss[i]);
    }
    for (i=1;i<=2*n;i++)
    {
      if (ss[i].tp==0)
        sc.insert(ss[i]);
      else
        sc.erase(D(ss[i].t,ss[i].s,1,ss[i].h));
      if (!sc.empty())
        fl[(*(sc.begin())).h]=true;
    }
    int mm=0;
    for (i=1;i<=n;i++)
      if (fl[i])
        mm++;
    cout<<mm<<endl;
  }
  return 0;
}

