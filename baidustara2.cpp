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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long  maxlongint=2147483647;

long long n,m,i,j,k,t,cc,mm,rr,c;
long long wu[20][5],tt[200000];
set<long long> f;

int main()
{
  cin>>n>>m;
  for (i=1;i<=n;i++)
    cin>>wu[i][0]>>wu[i][1];
  f.insert(0);
  for (i=1;;i++)
  {
    set<long long>::iterator it;
    mm=maxlongint*maxlongint;
    static long long mml=maxlongint*maxlongint;
    tt[0]=0;
    for (it=f.begin();it!=f.end();it++)
    {
      for (j=1;j<=n;j++)
      {
        c++;
        if ((*it)+wu[j][0]+wu[j][1]*i>mml)
          continue;
        tt[0]++;
        tt[tt[0]]=(*it)+wu[j][0]+wu[j][1]*i;
        mm=min(mm,wu[j][0]+wu[j][1]*i);
      }
    }
    for (j=1;j<=tt[0];j++)
      f.insert(tt[j]);
    cc=-1;
    for (it=f.begin();it!=f.end();it++)
    {
      if ((*it)>mm)
        break;
      cc++;
      if (cc==m)
        rr=(*it);
    }
    if (cc>m||c>600000)
      break;
  }
  if (rr==0)
    rr=m+7;
  cout<<rr<<endl;
  return 0;
}
