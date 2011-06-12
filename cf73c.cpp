/*
ID: mfs.dev2
PROG: CF 73 C
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long a,b,d,m,bei,i,j,k,c,t;
long long shu[1000000];

long long gcd(long long x,long long y)
{
  long long t;
  if (x<y)
  {
    t=x;
    x=y;
    y=t;
  }
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
  cin>>a>>b;
  bei=a*b/gcd(a,b);
  for (i=1;i<=b;i++)
  {
    if (a*i>bei)
      break;
    c++;
    shu[c]=a*i;
  }
  for (i=1;i<=a;i++)
  {
    if (b*i>=bei)
      break;
    c++;
    shu[c]=b*i;
  }
  sort(&(shu[1]),&(shu[c+1]));
  for (i=1;i<c;i++)
  {
    if (shu[i]%a==0)
      d+=shu[i]-t;
    else
      m+=shu[i]-t;
    t=shu[i];
  }
  if (a>b)
    d+=shu[c]-shu[c-1];
  else
    m+=shu[c]-shu[c-1];
  if (d==m)
    cout<<"Equal"<<endl;
  else if (d>m)
    cout<<"Dasha"<<endl;
  else
    cout<<"Masha"<<endl;
}

    

