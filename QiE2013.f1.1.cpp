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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,x;
int zu,zz;
double rr;
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>x;
    cin>>n;
    for (i=1;i<=n;i++)
    {
      cin>>m>>t;
      if (m==1)
      {
        rr=60*t-x*t;
        pf("%.2lf\n",rr);
        continue;
      }
      if (m==2)
      {
        rr=60*t/(1-x/60.0);
        pf("%.2lf\n",rr);
        continue;
      }
      if (m==3)
      {
        rr=43200*t/(x/60.0);
        pf("%.2lf\n",rr);
      }
    }
  }
  return 0;
}
      
