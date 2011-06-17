/*
ID: mfs6174
PROG: ustc 0529 C
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
const int maxlongint=2147483647;

struct D
{
  int d;
  vector<int> dao;
};

int i,j,k,m,n,zz,zu;
D shu[10010];
long long he[10010],ss,mm;

void mfs(int x,int f)
{
  int i;
  for (i=0;i<shu[x].dao.size();i++)
    if (shu[x].dao[i]!=f)
    {
      mfs(shu[x].dao[i],x);
      mm=min(mm,abs(ss-he[shu[x].dao[i]]-he[shu[x].dao[i]]));
      he[x]+=he[shu[x].dao[i]];
    }
  he[x]+=shu[x].d;
}

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    memset(he,0,sizeof(he));
    ss=0;
    for (i=1;i<=n;i++)
    {
      cin>>shu[i].d;
      shu[i].dao.clear();
      ss+=shu[i].d;
    }
    for (i=1;i<n;i++)
    {
      cin>>m>>k;
      shu[m].dao.push_back(k);
      shu[k].dao.push_back(m);
    }
    mm=maxlongint;
    mfs(1,0);
    cout<<mm<<endl;
  }
}


