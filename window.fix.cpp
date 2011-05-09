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
#include<list>
#include<iomanip>

using namespace std;
ifstream inf("window.in");
ofstream ouf("window.out");
const int maxlongint=2147483647;

struct W
{
  int x,y,xx,yy,h;
  W(int x1,int y1,int x2,int y2,int hh):x(x1),y(y1),xx(x2),yy(y2),h(hh){};
  bool operator ==(int x) const
  {
    return h==x;
  }
  
};

int i,j,k,n,m,t,tou,hou,mm,dang,c,tt[5];
list<W> w; 
int wei[150];
string ss;
//bool ff;


int hao(char x)
{
  if ((x>='0')&&(x<='9'))
    return x-47;
  if ((x>='a')&&(x<='z'))
    return x-96+10;
  return x-64+26+10;
}


void xin(int h,int x,int y,int xx,int yy)
{
  W t(x,y,xx,yy,h);
  w.push_front(t);
}

void ding(int x)
{
  list<W>::iterator it;
  it=find(w.begin(),w.end(),x);
  W t=*it;
  w.erase(it);
  w.push_front(t);
}

void shan(int x)
{
  list<W>::iterator it;
  it=find(w.begin(),w.end(),x);
  w.erase(it);
}

void di(int x)
{
  list<W>::iterator it;
  it=find(w.begin(),w.end(),x);
  W t=*it;
  w.erase(it);
  w.push_back(t);
}

void suan(list<W>::iterator d,int x,int y,int xx,int yy,bool ff)
{
  if ((x>=xx)||(y>=yy))
    return;
  if (ff)
  {
    mm+=abs(x-xx)*abs(y-yy);
    return;
  }
  int fx=(*d).x,fy=(*d).y,fxx=(*d).xx,fyy=(*d).yy;
  list<W>::iterator t=d;
  if (d==w.begin())
    ff=true;
  else
    t=--d;
  suan(t,x,y,min(fx,xx),min(fyy,yy),ff);
  suan(t,max(fxx,x),max(fy,y),xx,yy,ff);
  suan(t,max(fx,x),y,xx,min(fy,yy),ff);
  suan(t,x,max(fyy,y),min(fxx,xx),yy,ff);// not quanju ff,mei ci bu tong
}

void cha(int x)
{
  list<W>::iterator it,t;
  it=find(w.begin(),w.end(),x);
  mm=0;
  t=it;
  //ff=false;
  if (it==w.begin())//te shu chu li
    mm=abs((*t).x-(*t).xx)*abs((*t).y-(*t).yy);
  else
    suan(--it,(*t).x,(*t).y,(*t).xx,(*t).yy,false);
  ouf<<fixed<<setprecision(3)<<(double)(mm)*100/(abs((*t).x-(*t).xx)*abs((*t).y-(*t).yy))<<endl;//qu 100%,xian double hou *100,xiao xin yi chu
}

int val(const string &x)
{
    istringstream t(x);
    int r;
    t>>r;
    return r;
}

int main()
{
  while (inf>>ss)
  {
    if (ss[0]=='t')
    {
      ding(hao(ss[2]));
      continue;
    }
    if (ss[0]=='b')
    {
      di(hao(ss[2]));
      continue;
    }
    if (ss[0]=='d')
    {
      shan(hao(ss[2]));
      continue;
    }
    if (ss[0]=='s')
    {
      cha(hao(ss[2]));
      continue;
    }
    int t=hao(ss[2]);
    c=0;
    for (i=3;i<ss.size()-1;i++)
    {
      if (ss[i]==',')
      {
        c++;
        tt[c]=0;
        continue;
      }
      tt[c]*=10;
      tt[c]+=ss[i]-48;
    }
    xin(t,min(tt[1],tt[3]),min(tt[4],tt[2]),max(tt[3],tt[1]),max(tt[2],tt[4]));
  }
}

  
