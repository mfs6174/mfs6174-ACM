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

int i,j,k,t,n,m,zz,zu,a,b;
double p[110000],pp[110000],f[110000],mm,ppp[110000],pppp[110000];

int main()
{
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&a,&b);
    for (i=1;i<=a;i++)
      sf("%lf",&p[i]);
    pp[0]=1;
    for (i=1;i<=a;i++)
      pp[i]=pp[i-1]*p[i];
    ppp[0]=1-p[1];
    for (i=1;i<a;i++)
      ppp[i]=ppp[i-1]+pp[i]*(1-p[i+1]);
    pppp[a]=pp[a];
    for (i=a-1;i>=0;i--)
      pppp[i]=pppp[i+1]+pp[i]*(1-p[i+1]);
    f[0]=(b-a+1)*pp[a]+(b-a+1+b+1)*(1-pp[a]);
    f[a+1]=1+b+1;
    mm=min(f[0],1e15);
    mm=min(mm,f[a+1]);
    for (i=1;i<a;i++)
    {
      f[i]=(i*2+b-a+1+b+1)*ppp[a-i-1]+(i*2+b-a+1)*pppp[a-i];
      mm=min(mm,f[i]);
    }
    f[a]=a+b+1;
    mm=min(mm,f[a]);
    printf("Case #%d: %.6lf\n",zz,mm);
  }
  return 0;
}
