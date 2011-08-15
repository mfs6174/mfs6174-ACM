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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int at,df,rs,d,c;
  string na;
  deque<int> r;
};

struct R
{
  int p,h;
  int at,df,rs;
  string na;
  bool fl;
};

D wp[110],ap[110],dj[110];
map<string,int> ww;
nt i,j,k,t,n,m,tt,cw,ca,cd,mm,tm;
R ren[1100];
int zhi[1100];

inline bool cmp1(const R &a,const R &b)
{
  return a.at>b.at;
}
inline bool cmp3(const R &a,const R &b)
{
  return a.df>b.df;
}
inline bool cmp3(const R &a,const R &b)
{
  return a.df>b.df;
}

string s,ss;

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>s>>ss;
    if (ss=="weapon")
    {
      cw++;
      t=cw;
      inf>>wp[cw].at>>wp[cw].df>>wp[cw].rs>>wp[cw].d;
    }
    else
      if (ss=="armor")
      {
        ca++;
        t=100+ca;
        inf>>ap[ca].at>>ap[ca].df>>ap[ca].rs>>ap[ca].d;
      }
      else
      {
        cd++;
        t=200+cd;
        inf>>dj[cd].at>>dj[cd].df>>dj[cd].rs>>dj[cd].d;
      }
    ww[s]=t;
  }
  inf>>m;
  for (i=1;i<=m;i++)
  {
    inf>>ren[i].na;
    inf>>s>>t>>ss;
    ren[i].p=ww[ss];
    ren[i].fl=false;
    ren[i].h=i;
    zhi[i]=t;
    if (s=="gladiator")
      ren[i].at=t;
    else
      if (s=="sentry")
        ren[i].df=t;
      else
        ren[i].rs=t;
  }
  sort(&ren[1],&ren[m+1],cmp1);
  for (i=1;i<=cw;i++)
    if (wp[i].d>mm)
    {
      mm=wp[i].d;
      tt=i;
    };
  for (i=1;i<=m;i++)
  {
    if (ren[i].at==0)
      break;
    if (ren[i].fl)
      continue;
    cm++;
    wp[tt].at+=ren[i].at;
    wp[tt].r.push_back(ren[i].h);
    if (wp[tt].c<wp[tt].d)
      wp[tt].c++;
    else
    {
      t=wp[tt].r.front();
      wp[tt].at-=zhi[t];
      wp[tt].r.pop_front();
      if (ren[i].p<101)
      {
        wp[ren[i].p].at-=ren[i].at;
        wp[ren[i].p].at-=zhi[t];
        wp[ren[i].p].r.erase(ren[i].h);
        wp[ren[i].p].push_back(t);
      }
      else
        if (ren[i].p<201)
        {
          wp[ren[i].p].r.erase(ren[i].h);
          wp[ren[i].p].push_back(t);
          ren[i].fl=true;
        }
      
