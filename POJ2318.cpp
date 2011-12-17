/*
ID: mfs6174
PROG: POJ2318
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

inline double cha(P &a,P &b,P &c)
{
  return (b-a)^(c-a);
}

int i,j,k,t,n,m,a,b;
P shang[5100],xia[5100];
P shu;
int ji[5100];

int doit(P &p)
{
  int x=0,y=n,mid=(x+y)>>1;
  while (y-x>1)
  {
    mid=(x+y)>>1;
    if (cha(xia[mid],shang[mid],p)<0)
      x=mid;
    else
      y=mid-1;
  }
  if (cha(xia[y],shang[y],p)>0)
    return x;
  else
    return y;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&n);
  while (n)
  {
    scanf("%d",&m);
    shang[0].input();
    xia[n+1].input();
    xia[0].x=shang[0].x;
    xia[0].y=xia[n+1].y;
    shang[n+1].x=xia[n+1].x;
    shang[n+1].y=shang[0].y;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a,&b);
      shang[i].x=a;xia[i].x=b;
      shang[i].y=shang[0].y;
      xia[i].y=xia[n+1].y;
    }
    memset(ji,0,sizeof(ji));
    for (i=1;i<=m;i++)
    {
      shu.input();
      t=doit(shu);
      ji[t]++;
    }
    for (i=0;i<=n;i++)
      cout<<i<<": "<<ji[i]<<endl;
    cout<<endl;
    scanf("%d",&n);
  }
  return 0;
}
