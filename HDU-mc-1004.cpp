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
#include<cmath>
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m;
double v,vv,r;
bool ff[20];
int ping[20];
bool fl=true;

int cha(double x)
{
  if (abs(x-5)<=0.5)
    return 1;
  else
    if (x>=0&&x<=0.8)
      return 0;
}

void check(int x,int y,int z)
{
  if (ff[x]&&ff[y])
  {
    if (ping[x])
    {
      if (ping[y])
        t=0;
      else
        t=1;
    }
    else
    {
      t=1;
    }
    if (ff[z])
    {  
      if (ping[z]!=t)
        fl=false;
    }
    ff[z]=true;
    ping[z]=t;
  }
}
      
void pf(int x)
{
  if (ff[x])
  {
    cout<<x<<' ';
    if (ping[x])
      cout<<'H'<<endl;
    else
      cout<<'L'<<endl;
  }
}

int main()
{
  while (cin>>n)
  {
    fl=true;
    memset(ping,0,sizeof(ping));
    memset(ff,0,sizeof(ff));
    for (i=1;i<=n;i++)
    {
      cin>>t>>v;
      if (t==14)
        if (v!=5.0)
          fl=false;
      if (t==7)
        if (cha(v))
          fl=false;
      ff[t]=true;
      ping[t]=cha(v);
    }
    check(1,2,3);
    check(4,5,6);
    check(12,13,11);
    check(9,10,8);
    if (!fl)
      cout<<"No"<<endl;
    else
    {
      cout<<"Yes"<<endl;
      pf(3);pf(6);pf(8);pf(11);
    }
  }
  return 0;
}
