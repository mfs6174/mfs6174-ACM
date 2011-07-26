/*
ID: mfs6174
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
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

class YetAnotherIncredibleMachine
{
public:
  long long countWays(vector <int> p, vector <int> l, vector <int> b)
  {
    int n=p.size(),m=b.size();
    int i,j;
    long long rr=1,t=0;
    sort(b.begin(),b.end());
    for (i=0;i<n;i++)
    {
      t=0;
      int y=p[i]+l[i];
      if (b[0]<=y)
      {
        if (b[0]-p[i]>0)
          t+=b[0]-p[i];
      }
      else
      {
        t+=y-p[i]+1;
      }
      for (j=1;j<m;j++)
      {

          }
      }
      if (y>=b[m-1]+1)
      {
        tt=max(b[m-1]+l[i]+1,p[i]);
        if (y-tt+1>0)
          t+=y-tt+1;
      }
      t=t%1000000009;
      rr=(rr*t)%1000000009;
    }
    return rr;
  }
};
c
  
