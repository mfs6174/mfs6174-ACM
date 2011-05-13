/*
ID: mfs.dev2
PROG: schlnet
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
ifstream inf("schlnet.in");
ofstream ouf("schlnet.out");
const int maxlongint=2147483647;
const int N=100;
struct Dian
{
  int nz,nf,t,s;
  vector<int> z,f;
};

int i,j,k,t,n,m,c,cc,ct,mm;
int ru[N+10],chu[N+10],tl[N+10];
bool ff[N+10],f;
Dian tu[N+10];

void dfst(int x)
{
  int i;
  if (ff[x])
    return;
  ff[x]=true;
  for (i=1;i<=tu[x].nf;i++)
    dfst(tu[x].f[i-1]);
  ct++;
  tu[x].t=ct;
  tl[ct]=x;
}

void dfsf(int x)
{
  int i;
  if (ff[x])
    return;
  if (f)
  {
    c++;
    f=false;
  }
  ff[x]=true;
  tu[x].s=c;
  for (i=1;i<=tu[x].nz;i++)
    dfsf(tu[x].z[i-1]);
}

  
int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>t;
    while (t)
    {
      tu[i].nz++;
      tu[i].z.push_back(t);
      tu[t].nf++;
      tu[t].f.push_back(i);
      inf>>t;
    }
  }
  for (i=1;i<=n;i++)
    dfst(i);
  memset(ff,0,sizeof(ff));
  for (i=ct;i>=1;i--)
  {
    f=true;
    dfsf(tl[i]);
  }
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=tu[i].nz;j++)
      if (tu[tu[i].z[j-1]].s!=tu[i].s)
        chu[tu[i].s]++;
    for (j=1;j<=tu[i].nf;j++)
      if (tu[tu[i].f[j-1]].s!=tu[i].s)
        ru[tu[i].s]++;
  }
  for (i=1;i<=c;i++)
  {
    if (!ru[i])
      mm++;
    if (!chu[i])
      cc++;
  }
  ouf<<mm<<endl;
  if (c==1)
    mm=cc=0;
  ouf<<max(mm,cc)<<endl;
}

