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

llg i,j,k,t,n,m,aa,bb,cc;

llg val(const string &x)
{
    istringstream t(x);
    llg r;
    t>>r;
    return r;
}

string str(llg x)
{
    ostringstream t;
    t<<x;
    return t.str();
}

string sa,sb;

llg pw(llg n)
{
  if (n<1||n>18)
    return 1;
  llg t=1;
  for (llg i=1;i<=n;i++)
    t*=10;
  return t;
}

int main()
{
  //  freopen("ti.in","r",stdin);
  cin>>aa>>bb;
  if (aa>bb)
  {
    t=aa;
    aa=bb;
    bb=t;
  }
  sa=str(aa);
  sb=str(bb);
  cc=0;
  llg la,lb;
  la=sa.size();lb=sb.size();
  if (lb<4)
  {
    for (i=aa;i<=bb;i++)
    {
      string ss=str(i);
      if (ss[0]==ss[ss.size()-1])
        cc++;
    }
    cout<<cc<<endl;
    return 0;
  }
  if (la==lb)
  {
    llg j=1;
    while ((j<=la)&&sa[j-1]==sb[j-1])
      j++;
    if (la-j<2)
    {
      for (i=aa;i<=bb;i++)
      {
        string ss=str(i);
        if (ss[0]==ss[ss.size()-1])
          cc++;
      }
    }
    else
    {
      for (i=j+1;i<=la-1;i++)
        cc+=pw(la-1-i)*(9-(sa[i-1]-48));
      if (sa[la-1]<=sa[0])
        cc++;
      for (i=j+1;i<=lb-1;i++)
        cc+=pw(lb-1-i)*(sb[i-1]-48);
      if (sb[lb-1]>=sb[0])
        cc++;
    }
    cout<<cc<<endl;
    return 0;
  }
  for (i=la+1;i<=lb-1;i++)
    cc+=(9*pw(i-2));
  for (i=sa[0]-48+1;i<=9;i++)
    cc+=pw(la-2);
  for (i=1;i<=sb[0]-1-48;i++)
    cc+=pw(lb-2);
  for (i=2;i<=la-1;i++)
    cc+=pw(la-1-i)*(9-(sa[i-1]-48));
  if (sa[la-1]<=sa[0])
    cc++;
  for (i=2;i<=lb-1;i++)
    cc+=pw(lb-1-i)*(sb[i-1]-48);
  if (sb[lb-1]>=sb[0])
    cc++;
  cout<<cc<<endl;
  return 0;
}
    
    
  


