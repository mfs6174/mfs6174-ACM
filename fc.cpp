/*
ID: mfs.dev2
PROG: fc
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
ifstream inf("fc.in");
//ofstream ouf("fc.out");
const int maxlongint=2147483647;
const double ling=1e-7;
const double pai=acos(-1.0);

double X0,Y0;

double fang(double x)
{
  return x*x;
}

double li(double x1,double y1,double x2,double y2)
{
  return sqrt(fang(x1-x2)+fang(y1-y2));
}

double chaji(double x1,double y1,double x2,double y2)
{
  return x1*y2-x2*y1;
}

struct DIAN
{
  double x,y;
  bool operator <(const DIAN &d) const
  {
    return chaji(x-X0,y-Y0,d.x-X0,d.y-Y0)>0;
  }
};

DIAN dian[10100],td;
int n,i,j,k,t,cc;
int rr[10100];
double tt=maxlongint,tx=maxlongint,mm;

int cha(DIAN a,DIAN b,DIAN c)
{
  double x1,x2,y1,y2,t;
  x1=b.x-a.x;
  y1=b.y-a.y;
  x2=c.x-b.x;
  y2=c.y-b.y;
  t=x1*y2-x2*y1;
  return (abs(t)<=ling)?0:(t<0.0?-1:1);
}

int melkman()
{
  int bot=n-1,top=n,i,j,cnt;
  int t;
  int dui[300000];
  dui[top++]=0;
  dui[top++]=1;
  for(i=2;i<n;i++)
  {
    if(cha(dian[dui[top-2]],dian[dui[top-1]],dian[i])!=0)
    {
      break;
    }
    dui[top-1]=i;
  }
  dui[bot--]=i;
  dui[top++]=i;
  if(cha(dian[dui[n]],dian[dui[n+1]],dian[dui[n+2]])<0)
  {
    t=dui[n];
    dui[n]=dui[n+1];
    dui[n+1]=t;
  }
  for(i++;i<n;i++)
  {
    if(cha(dian[dui[bot+1]],dian[dui[bot+2]],dian[i])>0&&cha(dian[dui[top-2]],dian[dui[top-1]],dian[i])>0)
    {
      continue;
    }
    while(cha(dian[dui[bot+1]],dian[dui[bot+2]],dian[i])<=0)
    {
      bot++;
    }
    dui[bot--]=i;
    while(cha(dian[dui[top-2]],dian[dui[top-1]],dian[i])<=0)
    {
      top--;
    }
    dui[top++]=i;
  
  }
  cnt=0;
  for(i=bot+1;i<top;i++)
  {
    rr[cnt++]=dui[i];
  }
  return cnt;
}

int main()
{
  inf>>n;
  for (i=0;i<n;i++)
  {
    inf>>dian[i].x>>dian[i].y;
    if (dian[i].y<tt)
    {
      t=i;
      tt=dian[i].y;
      tx=dian[i].x;
    }
    else if (dian[i].y==tt)
    {
      if (dian[i].x<tx)
      {
        t=i;
        tx=dian[i].x;
      }
    }
  }
  X0=dian[t].x;
  Y0=dian[t].y;
  td=dian[0];
  dian[0]=dian[t];
  dian[t]=td;
  sort(&(dian[1]),&(dian[n]));
  cc=melkman();
  for (i=1;i<cc;i++)
    mm+=li(dian[rr[i]].x,dian[rr[i]].y,dian[rr[i-1]].x,dian[rr[i-1]].y);
  freopen("fc.out","w",stdout);
  printf("%.2lf\n",mm);
}

