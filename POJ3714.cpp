/*
ID: mfs6174
PROG: POJ3714 平面最近点对（两个集合之间的） 扫描法＋multiset nlogn
LANG: C++
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
struct point{double x,y;int id;point(double dx=0,double dy=0,int did=0):x(dx),y(dy),id(did){}//ID部分可去掉
friend bool operator<(const point&a,const point&b){return a.y<b.y;}
}p[200001];
bool cmp(const point&a,const point&b){return a.x<b.x;}
int main()
{
  freopen("ti.in","r",stdin);
  int t;
  scanf("%d",&t);
  for(int n,i;t--&&scanf("%d",&n);)
  {
    for(i=0;i<n&&scanf("%lf%lf",&p[i].x,&p[i].y);++i)
      p[i].id=0;
    for(i=n;i<2*n&&scanf("%lf%lf",&p[i].x,&p[i].y);++i)
      p[i].id=1;
    sort(p,p+2*n,cmp);
    multiset<point> s;
    s.insert(p[0]);
    double d=1e30; int left=0;
    for(i=1;i<2*n;++i)
    {
      while(left<i&&p[i].x-p[left].x>d)s.erase(p[left++]);
      for(multiset<point>::iterator it=s.lower_bound(point(p[i].x,p[i].y-d,0));
          it!=s.end()&&p[i].y+d>=it->y;++it)
        if(it->id^p[i].id==1) //去掉这里就不分集合了，全部点
          d=min(d,sqrt((p[i].x-it->x)*(p[i].x-it->x)+(p[i].y-it->y)*(p[i].y-it->y)));
      s.insert(p[i]);
    }
    printf("%.3lf\n",d);
  }
}
