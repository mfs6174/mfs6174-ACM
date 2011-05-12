/*
ID: mfs.dev2
PROG: cowcycle
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
ifstream inf("cowcycle.in");
ofstream ouf("cowcycle.out");
const int  maxlongint=2147483647;

int i,j,t,k,r,rr,a,aa,q,h,s,tt;
int qian[60],hou[60],rq[60],rh[60];
double mm=maxlongint;

void suan()
{
  int i,j,n;
  double jie[1000],ping=0.0,fang=0.0;
  for (i=1;i<=q;i++)
    for (j=1;j<=h;j++)
      jie[++n]=(double)(qian[i])/hou[j];
  sort(jie+1,jie+n+1);
  for (i=1;i<n;i++)
  {
    jie[i]=abs(jie[i]-jie[i+1]);
    ping+=jie[i];
  }
  ping/=n-1;
  for (i=1;i<n;i++)
    fang+=(jie[i]-ping)*(jie[i]-ping);
  fang/=n-1;
  if (fang<mm)
  {
    mm=fang;
    memcpy(rq+1,qian+1,sizeof(int)*q);
    memcpy(rh+1,hou+1,sizeof(int)*h);
  }
}

void zuhe2(int x,int n)
{
  int i,t=rr-h+n+1;
  hou[n]=x;
  if (n==h-1)
  {
    for (i=((x+1>tt)?(x+1):(tt));i<=rr;i++)
    {
      hou[h]=i;
      suan();
    }
    return;
  }
  for (i=x+1;i<=t;i++)
    zuhe2(i,n+1);
}
      
void zuhe1(int x,int n)
{
  int i,t=r-q+n+1;
  qian[n]=x;
  if (n==q)
  {
    for (i=aa;i<=rr-h+1;i++)
    {
      tt=ceil(3.0*s*i/x);
      if (tt>rr)
        break;
      zuhe2(i,1);
    }
    return;
  }
  for (i=x+1;i<=t;i++)
    zuhe1(i,n+1);
}

int main()
{
  inf>>q>>h>>a>>r>>aa>>rr;
  for (i=a;i<=r-q+1;i++)
  {
    s=i;
    zuhe1(i,1);
  }
  for (i=1;i<q;i++)
    ouf<<rq[i]<<' ';
  ouf<<rq[q]<<endl;
  for (i=1;i<h;i++)
    ouf<<rh[i]<<' ';
  ouf<<rh[h]<<endl;
  return 0;
}

  
