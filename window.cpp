/*
ID: mfs.dev2
PROG: window
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

using namespace std;
ifstream inf("window.in");
ofstream ouf("window.out");
const int maxlongint=2147483647;

struct W
{
  int x,y,xx,yy,h,n,p;
};

int i,j,k,n,m,t,c,tou,hou,mm,dang;
W w[2000];
int wei[150];

int hao(char x)
{
  if ((x>='0')&&(x<='9'))
    return x-47;
  if ((x>='a')&&(x<='z'))
    return x-64+10;
  return x-97+26+10;
}


void xin(int h,int x,int y,int xx,int yy)
{
  c++;
  w[c].h=h;
  w[c].x=x;
  w[c].y=y;
  w[c].xx=xx;
  w[c].yy=yy;
  wei[h]=c;
  w[c].n=tou;
  w[c].p=0;
  w[tou].p=c;
  tou=c;
  if (c==1)
    hou=c;
}

void ding(int x)
{
  int t=wei[x];
  if (t==tou)
    return;
  w[w[t].p].n=w[t].n;
  w[w[t].n].p=w[t].p;
  if (t==hou)
    hou=w[t].p;
  w[t].n=tou;
  w[tou].p=t;
  tou=t;
}

void shan(int x)
{
  int t=wei[x];
  wei[x]=0;
  w[w[t].p].n=w[t].n;
  w[w[t].n].p=w[t].p;
  if (t==tou)
    tou=w[t].n;
  if (t==hou)
    hou=w[t].p;
}

void di(int x)
{
  t=wei[x];
  if (t==hou)
    return;
  w[w[t].p].n=w[t].n;
  w[w[t].n].p=w[t].p;
  if (t==tou)
    tou=w[t].n;
  w[hou].n=t;
  w[t].p=hou;
  hou=t;
}

void suan(int z,int x,int y,int xx,int yy)
{
  if (w[z].h==dang)
  {
    mm+=abs(x-xx)*abs(y-yy);
    return;
  }
  
int main()
{
  
