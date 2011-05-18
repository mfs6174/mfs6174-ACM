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
#include<set>
#include<vector>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

class TheJackpotDivOne
{
public:
  vector<long long> find(vector<long long> money, long long jackpot)
  {
    long long ss,t,m=jackpot,zz,z=0,s=0;
    int i,n;
    set<long long> shu;
    vector<long long> rr;
    for (i=0;i<money.size();i++)
    {
      ss+=money[i];
      shu.insert(money[i]);
    }
    n=money.size();
    zz=(long long)((double)ss/n);
    if (ss%n)
      zz++;
    while (1)
    {
      t=*(shu.begin());
      if (t==zz)
        break;
      if (m<=zz-t)
      {
        shu.erase(shu.begin());
        shu.insert(t+m);
        break;
      }
      shu.erase(shu.begin());
      shu.insert(zz);
      ss=ss-t+zz;
      zz=(long long)((double)ss/n);
      if (ss%n)
        zz++;
      m=m-(zz-t);
    }
    if (t==zz)
    {
      z=m/n;
      s=m%n;
    }
    t=*(shu.begin());
    shu.erase(shu.begin());
    shu.insert(t+s);
    rr.clear();
    for (set<long long>::iterator i=shu.begin();i!=shu.end();i++)
      rr.push_back(*i+z);
    return rr;
  }
};

