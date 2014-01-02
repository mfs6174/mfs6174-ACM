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
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

const double INF=1e200;
const double Ling=1e-8;
bool fail;
#define maxn 50050
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


bool cmp(const P& a,const P& b)
{
	return a.x < b.x;
}

int i,j,k,t,n,m;
double dd[100][100];
P p[60000];
int zu,zz;

double ccct[maxn<<1];
int idx;
double cal(P a,P b)
{
	if (a.x - b.x <= Ling) return a.x;
	double rs = ((a.x+b.x) - (b.y*b.y - a.y*a.y)/(a.x - b.x))/2.0;
	if (rs >= 10000 || rs<= -10000) return 0;
	return rs;
}
double val(double x0,double y0,double x1,double y1)
{
	double rs;
	rs = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
	rs = sqrt(rs);
	return rs;
}
double gdis(double pos)
{
	int i;
	double dis = 0;
	for ( i=1 ; i<=n ; i++ )
	{
		double tmp = val(pos,0.0,p[i].x,p[i].y);
		dis = max(dis,tmp);
	}
	return dis;
}

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    for (i=1;i<=n;i++)
      p[i].input();
    sort(p+1,p+1+n,cmp);
	idx=0;
	for ( i=1 ; i<=n ; i++ )
      for ( j=1 ; j<=i ; j++ )
        ccct[idx++] = cal(p[i],p[j]);
	sort(ccct,ccct+idx);
    double dis=1e20;
    int rcd;
	for ( i=0 ; i<idx ; i++ )
	{
      if (i && (ccct[i]-ccct[i-1])<=Ling)
        continue;
      double tmp = gdis(ccct[i]);
      if (dis > tmp)
      {
        rcd = i;
			dis = tmp;
      }
	}
	printf("Case #%d: %.6lf\n",zz,ccct[rcd]);
  }
  return 0;
}
    
