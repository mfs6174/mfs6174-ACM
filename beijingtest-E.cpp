/*
ID: mfs6174
PROG: 多边形面积
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

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

struct P 
{ 
  int x; 
  int y;
  //constructor
  P(int a=0, int b=0) 
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
  int operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  int operator *(const P &b) const
  {
    return x*b.x+y*b.y;
  }
  void input()
  {
    scanf("%d%d",&x,&y);
  }
};

inline int cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

int i,j,k,t,n,m,zz,zu,p,ss,a,b;
P shu[5000];

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d%d",&p,&a,&b);
    n=a+b+2;
    shu[1].x=shu[1].y=0;
    shu[1+a+1].x=p;shu[1+a+1].y=0;
    j=1;
    for (i=1;i<=a;i++)
    {
      j++;
      shu[j].input();
    }
    j=a+2;
    for (i=1;i<=b;i++)
    {
      j++;
      shu[j].input();
    }
    ss=0;
    for (i=1;i<n;i++)
      ss+=shu[i]^shu[i+1];
    ss+=shu[n]^shu[1];
    if (ss<0) ss=-ss;
    double rr=1.0*ss/2;
    printf("%.2lf\n",rr);
  }
  return 0;
}
