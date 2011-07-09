/*
ID: mfs.dev2
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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long  maxlongint=2147483647;

long long i,j,k,n,m,t,tt,s,z;
struct B
{
  int n;
  vector<long long> l,h;
};

B tu[1005],xin[1005];

long long zui[1005],qian[1005],di[1005],mmd[1005],mm=maxlongint*maxlongint;

void spfa(int x)
{
  bool f[1005];
  int dui[1005];
  int i,s,e,d;
  memset(f,0,sizeof(f));
  memset(dui,0,sizeof(dui));
  di[x]=0;
  s=1%n;e=0;
  dui[s]=x;f[x]=true;
  while (s!=e)
  {
    e=(e+1)%n;
    d=dui[e];
    f[d]=false;
    for (i=1;i<=tu[d].n;i++)
      if (di[d]+tu[d].l[i]<di[tu[d].h[i]])
      {
        di[tu[d].h[i]]=di[d]+tu[d].l[i];
        // p[tu[d].h[i]]=d;
        if (!f[tu[d].h[i]])
        {
          if ((di[tu[d].h[i]]<=di[dui[(e+1)%n]]))
          {
            dui[e]=tu[d].h[i];
            if (e==0)
              e=n-1;
            else
              e=(e-1)%n;
          }
          else
          {
            //dui[s]=tu[d].h[i];
            s=(s+1)%n;
            dui[s]=tu[d].h[i];
          }
          f[tu[d].h[i]]=true;
        }
      }
  }
}

void spfa1(int x)
{
  bool f[1005];
  int dui[1005];
  int i,s,e,d;
  memset(f,0,sizeof(f));
  memset(dui,0,sizeof(dui));
  di[x]=0;
  s=1%n;e=0;
  dui[s]=x;f[x]=true;
  while (s!=e)
  {
    e=(e+1)%n;
    d=dui[e];
    f[d]=false;
    for (i=1;i<=xin[d].n;i++)
      if (di[d]+xin[d].l[i]<di[xin[d].h[i]])
      {
        di[xin[d].h[i]]=di[d]+xin[d].l[i];
        // p[xin[d].h[i]]=d;
        if (!f[xin[d].h[i]])
        {
          if ((di[xin[d].h[i]]<=di[dui[(e+1)%n]]))
          {
            dui[e]=xin[d].h[i];
            if (e==0)
              e=n-1;
            else
              e=(e-1)%n;
          }
          else
          {
            //dui[s]=xin[d].h[i];
            s=(s+1)%n;
            dui[s]=xin[d].h[i];
          }
          f[xin[d].h[i]]=true;
        }
      }
  }
}


int main()
{
  cin>>n>>m;
  for (i=1;i<=n;i++)
    mmd[i]=mm;
   for (i=1;i<=n;i++)
  {
    tu[i].l.push_back(0);
    tu[i].h.push_back(0);
    xin[i].l.push_back(0);
    xin[i].h.push_back(0);
  }
  cin>>s>>z;
  for (i=1;i<=m;i++)
  {
    cin>>t>>tt>>j;
    tu[t].n++;
    tu[tt].n++;
    tu[t].h.push_back(tt);
    tu[tt].h.push_back(t);
    tu[t].l.push_back(j);
    tu[tt].l.push_back(j);
  }
  for (i=1;i<=n;i++)
    cin>>zui[i]>>qian[i];
  for (i=1;i<=n;i++)
  {
    memcpy(di,mmd,sizeof(di));
    spfa(i);
    for (j=1;j<=n;j++)
    {
      if (i==j)
        continue;
      if (di[j]<=zui[i])
      {
        xin[i].n++;
        xin[i].h.push_back(j);
        xin[i].l.push_back(qian[i]);
      }
    }
  }
  memcpy(di,mmd,sizeof(di));
  spfa1(s);
  if (di[z]<maxlongint*maxlongint)
    cout<<di[z]<<endl;
  else
    cout<<-1<<endl;
  return 0;
}

