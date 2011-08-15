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
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;
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

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

P lcp(P aa, P ad, P ba, P bd)
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

int i,j,t,n,m,zz,zu;
P a1,a2,b1,b2,rr;

int main()
{
  cin>>zu;
  cout<<"INTERSECTING LINES OUTPUT"<<endl;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>a1.x>>a1.y>>a2.x>>a2.y>>b1.x>>b1.y>>b2.x>>b2.y;
    rr=lcp(a1,a2,b1,b2);
    if (fail)
    {
      if (cwz((b2-a1)^(b1-a2))==0)
        cout<<"LINE"<<endl;
      else
        cout<<"NONE"<<endl;
    }
    else
    {
      printf("POINT %.2lf %.2lf\n",rr.x,rr.y);
    }
  }
  cout<<"END OF OUTPUT"<<endl;
  return 0;
}

