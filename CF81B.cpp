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
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,n,m,t,a;
int xie[10],shu[10];
double mm,tt;

void suan(int x,int ty,int s,double g)
{
  if (x>n)
  {
    if (ty>n/2)
      tt+=g;
    else
      tt+=g*a/(a+s);
    return;
  }
  suan(x+1,ty+1,s,g*(shu[x]/100.0));
  suan(x+1,ty,s+xie[x],g*((100-shu[x])/100.0));
}
  
void dfs(int x)
{
  if (x>k)
  {
    tt=0;
    suan(1,0,0,1);
    mm=max(mm,tt);
    return;
  }
  int i;
  for (i=1;i<=n;i++)
    if (shu[i]<100)
    {
      shu[i]+=10;
      dfs(x+1);
      shu[i]-=10;
    }
  dfs(x+1);
}

  
int main()
{
  cin>>n>>k>>a;
  for (i=1;i<=n;i++)
    cin>>xie[i]>>shu[i];
  dfs(1);
  printf("%.10lf\n",mm);
  return 0;
}

