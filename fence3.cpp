/*
ID: mfs.dev2
PROG: fence3
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
ifstream inf("fence3.in");
//ofstream ouf("fence.out");
const int maxlongint=2147483647;

const int nn=200,ch=30,dai=8000,bc=2,jiaon=1;
const double pb=0.2,pmax=0.8,pmin=1.0-pmax,byl=0.2;

struct Dian
{
  double x,y,d;
};
int n,i,j,k,t,cc,ttr;
Dian xd[200],yd[200],qun[1000],tt;
double mmr=(double)(maxlongint),mx,my;

double fang(double x)
{
  return x*x;
}

double di(double x,double y,int xx,int yy)
{
  return sqrt(fang(x-xx)+fang(y-yy));
}

double ji(double x,double y)
{
  double rr=0.0;
  int i;
  for (i=1;i<=n;i++)
  {
    if (xd[i].x==yd[i].x)
    {
      if ((y>=xd[i].y)&&(y<=yd[i].y))
        rr+=abs(x-xd[i].x);
      else
        rr+=min(di(x,y,xd[i].x,xd[i].y),di(x,y,yd[i].x,yd[i].y));
    }
    else
    {
      if ((x>=xd[i].x)&&(x<=yd[i].x))
        rr+=abs(y-xd[i].y);
      else
        rr+=min(di(x,y,xd[i].x,xd[i].y),di(x,y,yd[i].x,yd[i].y));
    }
  }
  return rr;
}

void init()
{
  int i;
  for (i=1;i<=nn;i++)
    {
      qun[i].x=(rand()%100/100.0)*(mx);
      qun[i].y=(rand()%100/100.0)*(my);
      qun[i].d=ji(qun[i].x,qun[i].y);
    }
}
      

int ze(int x)
{
  int i,t,tt;
  double mm=2147483647.0;
  for (i=1;i<=x;i++)
  {
    tt=rand()%nn+1;
    if (qun[tt].d<mm)
    {
      mm=qun[tt].d;
      t=tt;
    }
  }
  return tt;
}

int zed(int x)
{
  int i,t,tt;
  double mm=-2147483647.0;
  for (i=1;i<=x;i++)
  {
    tt=rand()%nn+1;
    if (qun[tt].d>mm)
    {
      mm=qun[tt].d;
      t=tt;
    }
  }
  return tt;
}

void by(double &x,double &y)
{
  double t=rand()%((int)(byl*2*100))/100.0-byl,i;
  for (i=1;i<=bc;i++)
  {
    if (rand()%100/100.0<pb)
      x+=t;
  }
}

double cp()
{
  return rand()%((int)((pmax-pmin)*0.5*100))/100.0;
}

void xia()
{
  int x,y,i,c;
  double mm=2147483647,xx,yy,p,tx1,ty1,tx2,ty2;
  // for (i=1;i<=nn;i++)
//     if (qun[i].d<mm)
//     {
//       mm=qun[i].d;
//       x=i;
//       // if (mm<mmr)
// //         mmr=mm;
//     }
//   qun[1]=qun[x];
  for (i=1;i<=jiaon;i++)
  {
    x=ze(15);
    y=ze(15);
    if ((x==1)||(y==1))
      continue;
    tx1=qun[x].x;ty1=qun[x].y;
    tx2=qun[y].x;ty2=qun[y].y;
    // p=cp();
//     xx=tx1*p+tx2*(1-p);
//     p=cp();
//     yy=ty1*p+ty2*(1-p);
//     by(xx,yy);
//     qun[x].x=xx;qun[x].y=yy;
//     qun[x].d=ji(qun[x].x,qun[x].y);
//     p=cp();
//     xx=tx1*p+tx2*(1-p);
//     p=cp();
//     yy=ty1*p+ty2*(1-p);
//     by(xx,yy);
//     qun[y].x=xx;qun[y].y=yy;
//     qun[y].d=ji(qun[y].x,qun[y].y);
    for (c=1;c<=1;c++)
    { 
      p=cp();
      xx=tx1*p+tx2*(1-p);
      p=cp();
      yy=ty1*p+ty2*(1-p);
      by(xx,yy);
      x=zed(3);
      if (x==1)
        continue;
      qun[x].x=xx;
      qun[x].y=yy;
      qun[x].d=ji(xx,yy);
      if (qun[x].d<qun[1].d)
        qun[1]=qun[x];
    }
  }
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>xd[i].x>>xd[i].y>>yd[i].x>>yd[i].y;
    mx=max(xd[i].x,mx);
    my=max(xd[i].y,my);
    mx=max(yd[i].x,mx);
    my=max(yd[i].y,my);
    if (xd[i].x==yd[i].x)
    {
      if (xd[i].y>yd[i].y)
      {
        tt=xd[i];
        xd[i]=yd[i];
        yd[i]=tt;
      }
    }
    else
    {
      if (xd[i].x>yd[i].x)
      {
        tt=xd[i];
        xd[i]=yd[i];
        yd[i]=tt;
      }
    }
  }
  srand(133);
  init();
  for (i=1;i<=dai;i++)
    xia();
  freopen("fence3.out","w",stdout);
  printf("%.1lf %.1lf %.1lf\n",qun[1].x,qun[1].y,ji(qun[1].x,qun[1].y));
}


