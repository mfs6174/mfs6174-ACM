#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAXN 1100
 
struct pointset{
  double x, y;
};
const double precison=1.0e-8;
pointset maxcic, point[MAXN];
double radius;
int curset[MAXN], posset[3];
int set_cnt, pos_cnt;
 
inline double dis_2(pointset &from, pointset& to){
  return ((from.x-to.x)*(from.x-to.x)+(from.y-to.y)*(from.y-to.y));
}
 
int in_cic(int pt){
  if(sqrt(dis_2(maxcic, point[pt]))<radius+precison) return 1;
  return 0;
}
 
int cal_mincic(){
  if(pos_cnt==1 || pos_cnt==0)
    return 0;
  else if(pos_cnt==3){
    double A1, B1, C1, A2, B2, C2;
    int t0=posset[0], t1=posset[1], t2=posset[2];
    A1=2*(point[t1].x-point[t0].x);
    B1=2*(point[t1].y-point[t0].y);
    C1=point[t1].x*point[t1].x-point[t0].x*point[t0].x+
      point[t1].y*point[t1].y-point[t0].y*point[t0].y;
    A2=2*(point[t2].x-point[t0].x);
    B2=2*(point[t2].y-point[t0].y);
    C2=point[t2].x*point[t2].x-point[t0].x*point[t0].x+
      point[t2].y*point[t2].y-point[t0].y*point[t0].y;
    maxcic.y=(C1*A2-C2*A1)/(A2*B1-A1*B2);
    maxcic.x=(C1*B2-C2*B1)/(A1*B2-A2*B1);
    radius=sqrt(dis_2(maxcic, point[t0]));
  }
  else if(pos_cnt==2){
    maxcic.x=(point[posset[0]].x+point[posset[1]].x)/2;
    maxcic.y=(point[posset[0]].y+point[posset[1]].y)/2;
    radius=sqrt(dis_2(point[posset[0]], point[posset[1]]))/2;
  }
  return 1;
}
 
int mindisk(){
  if(set_cnt==0 || pos_cnt==3){
    return cal_mincic();
  }
  int tt=curset[--set_cnt];
  int res=mindisk();
  set_cnt++;
  if(!res || !in_cic(tt)){
    set_cnt--;
    posset[pos_cnt++]=curset[set_cnt];
    res=mindisk();
    pos_cnt--;
    curset[set_cnt++]=curset[0];
    curset[0]=tt;
  }
  return res;
}

int xx,yy,n;

int main()
{
  freopen("ti.in","r",stdin);
  int n, i;
  while(scanf("%d%d%d", &xx,&yy,&n)!=EOF)
  {
    for(i=0; i<n; i++)
      scanf("%lf %lf", &point[i].x, &point[i].y);
    if(n==1){
      maxcic.x=point[0].x;
      maxcic.y=point[0].y;
      radius=0;
      printf("(%.1lf,%.1lf).\n%.1lf\n", maxcic.x, maxcic.y, radius);
      continue;
    }
    set_cnt=n; pos_cnt=0;
    for(i=0 ;i<n ;i++)  curset[i]=i;
    mindisk();
    printf("(%.1lf,%.1lf).\n%.1lf\n", maxcic.x, maxcic.y, radius);
  }
  return 0;
}
