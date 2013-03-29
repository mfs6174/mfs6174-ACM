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
const double eps = 1e-10;
const double pi=3.14159265359;
inline double max (double a, double b) { if (a > b) return a; else return b; }
inline double min (double a, double b) { if (a < b) return a; else return b; } 
inline int fi (double a) 
{
    if (a > eps) return 1;
    else if (a >= -eps) return 0;
    else return -1;
}
class mvec
{
public:
    double x, y;
    mvec (void) {}
    mvec (double x0, double y0) : x(x0), y(y0) {}
    double operator * (const mvec& a) const { return x * a.y - y * a.x; }
    double operator % (const mvec& a) const { return x * a.x + y * a.y; }
    mvec verti (void) const { return mvec(-y, x); }
    double length (void) const { return sqrt(x * x + y * y); }
    mvec adjust (double len)
    {
        double ol = len / length();
        return mvec(x * ol, y * ol);
    }
    mvec oppose (void) { return mvec(-x, -y); }
};
class point
{
public:
    double x, y;
    point (void) {}
    point (double x0, double y0) : x(x0), y(y0) {}
    mvec operator - (const point& a) const { return mvec(x - a.x, y - a.y); }
    point operator + (const mvec& a) const { return point(x + a.x, y + a.y); }
};
class segment
{
public:
    point a, b;
    segment (void) {}
    segment (point a0, point b0) : a(a0), b(b0) {}
    point intersect (const segment& s) const
    {
        mvec v1 = s.a - a, v2 = s.b - a, v3 = s.b - b, v4 = s.a - b;
        double s1 = v1 * v2, s2 = v3 * v4;
        double se = s1 + s2;
        s1 /= se, s2 /= se;
        return point(a.x * s2 + b.x * s1, a.y * s2 + b.y * s1);
    }
    point pverti (const point& p) const
    {
        mvec t = (b - a).verti();
        segment uv(p, p + t);
        return intersect(uv);
    }
    bool on_segment (const point& p) const
    {
        if (fi(min(a.x, b.x) - p.x) <= 0 && fi(p.x - max(a.x, b.x)) <= 0 &&
            fi(min(a.y, b.y) - p.y) <= 0 && fi(p.y - max(a.y, b.y)) <= 0) return true;
        else return false;
    }
};
double radius;
point polygon[200];

double kuras_area (point a, point b,point ori)
{
    int sgn = fi((b - ori) * (a - ori));
    double da = (a - ori).length(), db = (b - ori).length();
    int ra = fi(da - radius), rb = fi(db - radius);
    double angle = acos(((b - ori) % (a - ori)) / (da * db));
    segment t(a, b); point h, u; mvec seg;
    double ans, dlt, mov, tangle;
    
    if (fi(da) == 0 || fi(db) == 0) return 0;
    else if (sgn == 0) return 0;
    else if (ra <= 0 && rb <= 0) return fabs((b - ori) * (a - ori)) / 2 * sgn;
    else if (ra >= 0 && rb >= 0)
    {
        h = t.pverti(ori);
        dlt = (h - ori).length();
        if (!t.on_segment(h) || fi(dlt - radius) >= 0)
            return radius * radius * (angle / 2) * sgn;
        else
        {
            ans = radius * radius * (angle / 2);
            tangle = acos(dlt / radius);
            ans -= radius * radius * tangle;
            ans += radius * sin(tangle) * dlt;
            return ans * sgn;
        }
    }
    else
    {
        h = t.pverti(ori);
        dlt = (h - ori).length();
        seg = b - a;
        mov = sqrt(radius * radius - dlt * dlt);
        seg = seg.adjust(mov);
        if (t.on_segment(h + seg)) u = h + seg;
        else u = h + seg.oppose();
        if (ra == 1) swap(a, b);
        ans = fabs((a - ori) * (u - ori)) / 2;
        tangle = acos(((u - ori) % (b - ori)) / ((u - ori).length() * (b - ori).length()));
        ans += radius * radius * (tangle / 2);
        return ans * sgn;
    }
}

inline point calpnt(point s,double vv,double xi,double ti,double gg)
{
  double vx=vv*cos(xi/180*pi),vy=vv*sin(xi/180*pi);
  double xx=s.x+ti*vx,yy=s.y+vy*ti-0.5*gg*ti*ti;
  return point(xx,yy);
}

int main()
{
  double area, x, y, x0,y0,vv,xi,time,gra;
  freopen("ti.in","r",stdin);
  while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x0,&y0,&vv,&xi,&time,&gra,&radius)!=EOF)
  {
    if (x0==0&&y0==0&&vv==0&&xi==0&&time==0&&gra==0&&radius==0)
      break;
    sf("%d",&n);
    for (int i = 0; i < n; i++)
    {
      scanf("%lf %lf", &x, &y);
      polygon[i] = point(x, y);
    }
    area = 0;
    point ooo=calpnt(point(x0,y0),vv,xi,time,gra);
    for (int i = 0; i < n; i++)
      area += kuras_area(polygon[i], polygon[(i + 1) % n],ooo);
    printf("%.2f\n", fabs(area));
  }
  return 0;  
}
