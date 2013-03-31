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

llg i,j,k,t,n,m;
struct D
{
  llg p,d;
  bool operator <(const D &x) const
  {
    return d>x.d;
  }
};

D jian[110000];
llg zi[110000];
class cmp   
{  
    public:  
    bool operator()( const D & n1, const D & n2) const  
    {  
        return n1.p>n2.p;  
    }  
};
priority_queue< D,vector<D>,cmp > Q;  
int main()
{
  freopen("ti.in","r",stdin);

  while (sf("%I64d%I64d",&n,&m)!=EOF)
  {
    for (i=1;i<=n;i++)
      sf("%I64d",&zi[i]);
    for (i=1;i<=m;i++)
      sf("%I64d",&jian[i].d);
    for (i=1;i<=m;i++)
      sf("%I64d",&jian[i].p);
    sort(&zi[1],&zi[n+1]);
    sort(&jian[1],&jian[m+1]);
    Q=priority_queue< D,vector<D>,cmp >();
    j=1;
    llg mm=0;
    for (i=n;i>=1;i--)
    {
      for (;j<=m;j++)
        if (jian[j].d>=zi[i])
        {
          Q.push(jian[j]);
        }
        else
          break;
      if (Q.empty())
      {
        mm=-1;
        break;
      }
      D dang=Q.top();
      Q.pop();
      mm+=dang.p;
    }
    if (mm==-1)
      pf("No\n");
    else
      pf("%I64d\n",mm);
  }
  return 0;
}
      
      
