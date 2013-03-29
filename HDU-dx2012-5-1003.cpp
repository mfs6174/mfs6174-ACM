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
const int maxlongint=2147483647;

int i,j,k,t,n,m;

const double INF=1e200;
const double Ling=1e-9;
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

struct G
{
  P d;
  int t,v;
};

inline double dst(P p1,P p2)                
{ 
  return( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)  ); 
}

inline bool cmp(const G &a, const G &b)
{ //中心极角排序 从-PI到-PI内
  double aa=atan2(a.d.y, a.d.x),bb=atan2(b.d.y, b.d.x);
  if (cwz(aa-bb)==0)
    return a.d.y<b.d.y;
  else
    return aa > bb;
}

G dian[500];
int f[50000];
int dui[300],dai[300];
int nn,v,zz;

int main()
{
  freopen("ti.in","r",stdin);
  while (sf("%d%d",&n,&m)!=EOF)
  {
    zz++;
    for (i=1;i<=n;i++)
    {
      dian[i].d.input();
      sf("%d%d",&dian[i].t,&dian[i].v);
    }
    sort(&dian[1],&dian[n+1],cmp);
    memset(f,0,sizeof(f));
    double tt=-6;
    for (i=1,nn=0;i<=n;i++)
    {
      if ( cwz(atan2(dian[i].d.y,dian[i].d.x)-tt)!=0)
      {
        nn++;
        dui[nn]=i;
        dai[nn]=1;
      }
      else
      {
        dai[nn]++;
      }
      tt=atan2(dian[i].d.y,dian[i].d.x);
    }
    for (i=1;i<=nn;i++)
      for (k=m;k>=0;k--)
      {
        v=t=0;
        for(j=1;j<=dai[i];j++)
        {
          v+=dian[dui[i]+j-1].v;
          t+=dian[dui[i]+j-1].t;
          if (k-t<0)
            break;
          f[k]=max(f[k],f[k-t]+v);
        }
      }
    int mm=0;
    for (i=0;i<=m;i++)
      mm=max(mm,f[i]);
    printf("Case %d: %d\n",zz,mm);
  }
  return 0;
}


