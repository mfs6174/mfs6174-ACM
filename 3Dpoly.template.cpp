/*
  ID: mfs6174
  email: mfs6174@gmail.com
  PROG: 3Dpoly
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
const int maxlongint=2147483647;


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

const int maxn=1000;
typedef double longd;
const longd eps=1e-9;
typedef long long lld;
class Point3
{
public:
  longd x,y,z;
  Point3(){x=y=z=0;}
  void iin()
  {
    scanf("%lf%lf%lf",&x,&y,&z);
  }
};
Point3 operator -(Point3 a,Point3 b)
{
  Point3 c;
  c.x=a.x-b.x;
  c.y=a.y-b.y;
  c.z=a.z-b.z;
  return c;
}
Point3 operator +(Point3 a,Point3 b)
{
  Point3 c;
  c.x=a.x+b.x;
  c.y=a.y+b.y;
  c.z=a.z+b.z;
  return c;
}
Point3 operator *(Point3 a,longd d)
{
  a.x*=d;
  a.y*=d;
  a.z*=d;
  return a;
}
Point3 operator /(Point3 a,longd d)
{
  a.x/=d;
  a.y/=d;
  a.z/=d;
  return a;
}
longd leng(Point3 a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
Point3 multi(Point3 a,Point3 b)
{
  Point3 r;
  r.x=a.y*b.z-a.z*b.y;
  r.y=a.z*b.x-a.x*b.z;
  r.z=a.x*b.y-a.y*b.x;
  return r;
}
longd dj(Point3 a,Point3 b)
{
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
longd area(Point3 a,Point3 b,Point3 c)
{
  longd d1=leng(b-c),d2=leng(c-a),d3=leng(a-b);
  longd p=(d1+d2+d3)/2;
  longd rs=sqrt(p*(p-d1)*(p-d2)*(p-d3));
  return rs;
}
longd V(Point3 a,Point3 b,Point3 c,Point3 d)
{
  return dj(multi(a-c,b-c),d-c)/6.0;
}
Point3 p[maxn];
int pp;
Point3 a[maxn];
int aa;
class stPt
{
public:
  Point3 pt;
  longd mt;
} stpt[maxn];
int operator <(stPt a,stPt b)
{
  return a.mt<b.mt;
}
 
void suant(Point3* a,int aa,Point3 &ht, longd &totv,Point3 pzx)
{
  Point3 zx;
  zx.x=zx.y=zx.z=0;
  int i,j;
  for (i=0;i<aa;i++)
    zx=zx+a[i];
  zx=zx/aa;
 
  for (j=1;j<aa;j++)
    if (cwz(leng(multi(a[0]-zx,a[j]-zx)))>0)
      break;
 
 
  for (i=1;i<aa;i++)
  {
    Point3 xj=multi(a[1]-a[0],a[i]-a[0]);
    double l10=leng(a[1]-a[0]);
    double li0=leng(a[i]-a[0]);
    double l1i=leng(a[i]-a[1]);
    stpt[i].pt=a[i];
    stpt[i].mt=acos((l10*l10+li0*li0-l1i*l1i)/(2*l10*li0)); 
    if (cwz(dj(xj,multi(a[1]-a[0],a[2]-a[0])))==-1)
      stpt[i].mt*=-1;
  }
  sort(stpt+1,stpt+aa);
  for (i=1;i<aa;i++) a[i]=stpt[i].pt;
  a[aa]=a[0];
 
  longd thisv=0;
  for (i=0;i<aa;i++)
  {
    longd tiji=fabs(V(a[i],a[i+1],zx,pzx));
    thisv+=tiji;
    ht=ht+(a[i]+a[i+1]+zx+pzx)*tiji/4;
  }
  totv+=thisv;

}
longd minds(Point3* p,int n)
{
  int i,j,k;
  Point3 ht;
  ht.x=ht.y=ht.z=0;
  longd totv=0;
  longd polymindis=-1;
  Point3 pzx=p[n-1];
  for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
      for (k=j+1;k<n;k++)
      {
        int sg=0;
        int t;
        aa=0;
        for (t=0;t<n;t++) 
        {
          longd tj=V(p[i],p[j],p[k],p[t]);
          if (sg==0) sg=cwz(tj);
          if (cwz(tj)==0&&t!=i&&t!=j&&t!=k&&t<k)
            break;
          if (cwz(tj)*cwz(sg)==-1)
            break;
          if (cwz(tj)==0)
            a[aa++]=p[t];
        }
        if (t>=n)
        {
          suant(a,aa,ht,totv,pzx);
        }
      }
 
 
  ht=ht/totv;
  for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
      for (k=j+1;k<n;k++)
      {
        int sg=0;
        int t;
        aa=0;
        for (t=0;t<n;t++)
        {
          longd tj=V(p[i],p[j],p[k],p[t]);
          if (sg==0) sg=cwz(tj);
          if (cwz(tj)==0&&t!=i&&t!=j&&t!=k&&t<k)
            break;
          if (cwz(tj)*cwz(sg)==-1)
            break;
        }
        if (t>=n)
        {
          longd ds=fabs(V(p[i],p[j],p[k],ht))*3.0/area(p[i],p[j],p[k]);
          if (polymindis<0||polymindis>ds)
            polymindis=ds;
        }
      }
  return polymindis;
}
int main()
{
  freopen("ti.in","r",stdin);
  while (  scanf("%d",&pp)!=EOF)
  {
    int i;
    for (i=0;i<pp;i++)
      p[i].iin();//存放多面体顶点
    longd dis1=minds(p,pp);//多面体重心到外表最近距离
    printf("%.3lf\n",dis1);
  }
  return 0;
}
