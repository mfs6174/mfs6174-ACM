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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long i,j,n,m,mm,l;
string ss,st;


long long  val(const string &x)
{
    istringstream t(x);
    long long  r;
    t>>r;
    return r;
}

string str(long long  x)
{
    ostringstream t;
    t<<x;
    return t.str();
}

bool check(long long x)
{
  int n=0,m=0,i;
  ss=str(x);
  for (i=0;i<ss.size();i++)
    if (ss[i]=='4')
      n++;
    else
      m++;
  if (n==m)
    return true;
  else
    return false;
}


void dfs(int x,long long d)
{
  if (x>m)
  {
    if (check(d))
      if (d>=n&&d<mm)
        mm=d;
    return;
  }
  dfs(x+1,d*10+4);
  dfs(x+1,d*10+7);
}

int main()
{
  cin>>n;
  st=str(n);
  m=st.size();
  long long tm;
  if (st[0]>'7'||(m%2!=0))
  {
    l=m+1;
    if (l%2!=0)
      l++;
    mm=4;
    for (i=2;i<=l/2;i++)
      mm=mm*10+4;
    for (i=l/2+1;i<=l;i++)
      mm=mm*10+7;
  }
  else
  {
    mm=7;
    for (i=1;i<=10;i++)
      mm=mm*10+7;
    tm=mm;
    dfs(2,4);
    dfs(2,7);
  }
  if (mm==tm)
  {
    l=m+1;
    if (l%2!=0)
      l++;
    mm=4;
    for (i=2;i<=l/2;i++)
      mm=mm*10+4;
    for (i=l/2+1;i<=l;i++)
      mm=mm*10+7;
  }
  cout<<mm<<endl;
  return 0;
}

  
