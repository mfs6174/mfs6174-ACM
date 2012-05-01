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
ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,l,mm,tt;
string s,ss;
bool ff[2100000];
int shu[1000000];

string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
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
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(ff,0,sizeof(ff));
    inf>>n>>m;
    mm=0;
    s=str(n);
    ss=str(m);
    l=s.size();
    for (i=n;i<m;i++)
    {
      s=str(i);
      tt=0;
      for (j=1;j<l;j++)
      {
        ss=s.substr(j)+s.substr(0,j);
        t=val(ss);
        if (t>i && t<=m)
        {
          if (!ff[t])
          {
            mm++;
            ff[t]=true;
            tt++;
            shu[tt]=t;
          }
          else
            t=t;
        }
      }
      for (j=1;j<=tt;j++)
        ff[shu[j]]=false;
    }
    ouf<<"Case #"<<zz<<": "<<mm<<endl;
  }
  return 0;
}
    
