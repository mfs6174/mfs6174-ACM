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
ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,s,e;
int shu[120][4],ss[120];

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>s>>e;
    for (i=1;i<=n;i++)
    {
      inf>>ss[i];
      if (ss[i]%3==0)
        shu[i][1]=shu[i][2]=shu[i][3]=ss[i]/3;
      if (ss[i]%3==1)
      {
        shu[i][1]=shu[i][2]=shu[i][3]=(ss[i]-1)/3;
        shu[i][3]++;
      }
      if (ss[i]%3==2)
      {
        shu[i][1]=shu[i][2]=shu[i][3]=(ss[i]+1)/3;
        shu[i][1]--;
      }
    }
    m=0;
    for (i=1;i<=n;i++)
    {
      if (shu[i][3]>=e)
      {
        m++;
        continue;
      }
      if (s>0 && shu[i][2]==shu[i][3] && shu[i][3]+1<=10 && shu[i][3]+1>=e && shu[i][2]==shu[i][1]+1)
      {
        s--;
        m++;
        continue;
      }
      if (s>0 && shu[i][1]==shu[i][2] && shu[i][2]==shu[i][3] && shu[i][3]+1<=10 && shu[i][1]-1>=0 &&shu[i][3]+1>=e)
      {
        s--;
        m++;
      }
    }
    ouf<<"Case #"<<zz<<": "<<m<<endl;
  }
  return 0;
}

    
