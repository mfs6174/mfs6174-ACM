/*
ID: mfs6174
PROG: GCJ2011r1A
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

int i,j,k,zz,zu;
long long pg,pd,n,tt,p,pp;
double k1,kk,xx,k2;

int gcd(int x,int y)
{
  if (y==0)
    return y;
  while (x%y!=0)
  {
    int t=x;
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
    inf>>n>>pd>>pg;
    if (pd!=0)
      k1=(double)pg/pd;
    if (100-pd!=0)
      k2=(double)(100-pg)/(100-pd);
    if ((k1<1.0)&&(pd!=0))
      kk=k1;
    else
      kk=1;
    if ((k2<kk)&&(100-pd!=0))
      kk=k2;
    if (pd!=0)
      p=100/gcd(100,pd);
    else
      p=0;
    //pp=100/gcd(pg,100);
    if ((p<=n)&&(kk>0))
      ouf<<"Case #"<<zz<<": Possible"<<endl;
    else
      ouf<<"Case #"<<zz<<": Broken"<<endl;
  }
 }
  
      
