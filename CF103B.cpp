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
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

const double INF=1e200;
const double Ling=1e-8;
bool fail;

inline int cwz(int x)
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
    scanf("%d%d",&x,&y);
  }

}; 

inline double dst(P p1,P p2)                
{ 
  return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
}

int i,j,k,t,n,m,x,y,r;
int xa,ya,xb,yb;
int ff[50000];
P dian;
P ren[50000];

int main()
{
  sf("%d%d%d%d",&xa,&ya,&xb,&yb);
  sf("%d",&n);
  ren[1].x=xa;ren[1].y=ya;
  ren[2].x=xb;ren[2].y=ya;
  ren[3].x=xa;ren[3].y=yb;
  ren[4].x=xb;ren[4].y=yb;
  k=4;
  for (i=min(ya,yb)+1;i<=max(ya,yb)-1;i++)
  {
    k++;
    ren[k].x=xa;ren[k].y=i;
    k++;
    ren[k].x=xb;ren[k].y=i;
  }
  for (i=min(xa,xb)+1;i<=max(xa,xb)-1;i++)
  {
    k++;
    ren[k].x=i;ren[k].y=ya;
    k++;
    ren[k].x=i;ren[k].y=yb;
  }
  for (i=1;i<=n;i++)
  {
    dian.input();
    sf("%d",&r);
    for (j=1;j<=k;j++)
      if (dst(dian,ren[j])<=r)
        ff[j]=1;
  }
  for (i=1;i<=k;i++)
    if (!ff[i])
      m++;
  cout<<m<<endl;
  return 0;
}
