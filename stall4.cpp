/*
ID: mfs.dev2
PROG: stall4
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;
ifstream inf("stall4.in");
ofstream ouf("stall4.out");
const int maxlongint=2147483647;

const int maxn=203;

struct jiedian
{
  int n,dao[maxn];
};
		
int n,m,zuo[maxn],i,j,duiz[maxn],duiy[maxn],nn,t,rr=0;
jiedian dian[maxn];
bool yong[maxn];

bool xiong(int x)
{
  int i,tt;
  for (i=1;i<=dian[x].n;i++)
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(duiy[tt]))
      {
        duiz[x]=tt;
        duiy[tt]=x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  inf>>n>>m;
  for (i=1;i<=n;i++)
  {
    inf>>dian[i].n;
    for (j=1;j<=dian[i].n;j++)
      inf>>dian[i].dao[j];
  }
  for (i=1;i<=nn;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t))
          rr++;
    }
  }
  ouf<<rr<<endl;
}
