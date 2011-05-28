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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long tt,mm,n,l,zuo,you,a,b;
long long shu[50000],yue[5000];
int i,j,k,t,zz,zu;
bool ff;

long long gcd(long long x,long long y)
{
  long long t;
  while (x%y!=0)
  {
    t=x;
    x=y;
    y=t%y;
  }
  return y;
}

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>a>>b;
    l=b-a;
    for (i=1;i<=n;i++)
      inf>>shu[i];
    sort(&(shu[1]),&(shu[n+1]));
    yue[n]=shu[n];
    for (i=n-1;i>=1;i--)
      yue[i]=gcd(yue[i+1],shu[i]);
    
    tt=shu[1];
    ff=false;
    for (i=1;i<n;i++)
    {
      tt=tt*shu[i]/gcd(tt,shu[i]);
      if (tt>yue[i+1])
        continue;
      zuo=tt;
      you=yue[i+1];
      if (you%zuo==0)
        if ((b/zuo)>(a/zuo)&&(zuo>=a))
        {
          ff=true;
          ouf<<"Case #"<<zz<<": "<<(zuo*((a+zuo-1)/zuo))<<endl;
          break;
        }
    }
    if ((b/tt)>(a/tt)&&(tt>=a)&&(!ff))
   
      {
          ff=true;
          ouf<<"Case #"<<zz<<": "<<(tt*((a+tt-1)/tt))<<endl;
        }

     if (!ff)
      ouf<<"Case #"<<zz<<": NO"<<endl;
  }
}

    
