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
    long long ss=0,t,m=jackpot,zz,z=0,s=0;
    int i,n;
    multiset<long long> shu;
    vector<long long> rr;
    for (i=0;i<money.size();i++)
    {
      ss+=money[i];
      shu.insert(money[i]);
    }
    n=money.size();
    zz=(long long)((double)ss/n)+1;
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
      m=m-(zz-t);
      zz=(long long)((double)ss/n)+1;
      
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

vector<long long> v,rr;
TheJackpotDivOne test;

int main()
{
  int n,i;
  long long t,jp;
  cin>>n;
  for (i=1;i<=n;i++)
  {
    cin>>t;
    v.push_back(t);
  }
  cin>>jp;
  rr=test.find(v,jp);
  return 0;
}

  
