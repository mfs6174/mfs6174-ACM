
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;
const double ling=1e-9;

struct D
{
  double x;
  int h;
  string s;
  bool operator <(const D &y) const
  {
    //if (h!=y.h)
      return h<y.h;
      //else
      //return x<y.x;
  }
};
int i,j,k,t,n,zz,zu;
D shu[500];

double val(const string &x)
{
    istringstream t(x);
    double r;
    t>>r;
    return r;
}
bool deng(double x,double y)
{
  return abs(x-y)<ling;
}

int cha(double x,double a,double b,int c)
{
  double l=(2*a+b)/3.0,r=(a+2*b)/3.0;
  if (((x>=l))&&(x<=r))
    return c;
  if (x<l)
    return cha(x,a,l,c+1);
  else
    return cha(x,r,b,c+1);
}

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n;
    for (i=1;i<=n;i++)
    {
      inf>>shu[i].s;
      shu[i].x=val(shu[i].s);
    }
    for (i=1;i<=n;i++)
      shu[i].h=cha(shu[i].x,0.0,1.0,1);
    sort(&(shu[1]),&(shu[n+1]));
    ouf<<"Case #"<<zz<<':'<<endl;
    for (i=1;i<=n;i++)
      ouf<<shu[i].s<<endl;
  }
}



