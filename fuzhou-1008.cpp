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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,c;
map<string,int> ha;
string ss;
char ts[100];
bool ke[100][100];
int shu[1000][10];
bool ff[100];
int d[10],dui[10];
string cun[10];
bool fl;
void ar(int x,int m,int n)
{
  int i;
  for (i=1;i<=n;i++)
    if (!ff[i])
    {
      d[x]=i;ff[i]=true;
      if (x==m)
      {
        c++;
        memcpy(shu[c],d,sizeof(d));
      }
      else
        ar(x+1,m,n);
      ff[i]=false;
    }
}

bool check(int w)
{
  bool fl=true;
  int i,j,k;
  for (i=1;i<=m;i++)
  {
    j=1;k=1;
    while (j<=n&&k<=n)
    {
      if (ke[shu[i][k]][shu[w][j]])
        j++;
      else
        k++;
    }
    if (j>n)
    {
      fl=false;
      break;
    }
  }
  return fl;
}

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    ha.clear();
    for (i=1;i<=n;i++)
    {
      sf("%s",ts);
      cun[i]=string(ts);
      ha[cun[i]]=i;
    }
    memset(ke,0,sizeof(ke));
    i=1;
    for (map<string,int>::iterator it=ha.begin();it!=ha.end();it++)
    {
      dui[i]=(*it).second;
      (*it).second=i;
      i++;
    }
    for (i=1;i<=n;i++)
    {
      sf("%d",&m);
      for (j=1;j<=m;j++)
      {
        sf("%s",ts);
        ss=string(ts);
        ke[i][ha[ss]]=true;
      }
    }
    m=1;
    for (i=1;i<=n;i++)
      m*=i;
    memset(shu,0,sizeof(shu));
    memset(ff,0,sizeof(ff));
    c=0;
    ar(1,n,n);
    pf("Case %d: ",zz);
    fl=false;
    for (k=1;k<=m;k++)
    {
      if (check(k))
      {
        pf("Yes\n");
        for (i=1;i<n;i++)
          pf("%s ",cun[dui[shu[k][i]]].c_str());
        pf("%s\n",cun[dui[shu[k][n]]].c_str());
        fl=true;
        break;
      }
    }
    if (!fl)
      pf("No\n");
  }
  return 0;
}



