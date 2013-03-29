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

int f[2][92][92][92][2];

int i,j,k,t,n,m,zu,zz,a,b;

string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
}

int  dp(int shu)
{
  string ss=str(shu);
  int mm=ss.size()*9+1;
  memset(f,0,sizeof(f));
  for(int mo=1;mo<mm;mo++)
    f[0][0][0][mo][0]=1;
  int p=0;
  for(int mo=1;mo<mm;mo++)
    for(int w=0;w<ss.size();w++)
    {
      for(int s=0;s<mm;s++)
        for(int r=0;r<mm;r++)
          for(int i=0;i<10&&s+i<mm;i++)
            if (i<ss[w]-48)
              f[1-p][s+i][(r*10+i)%mo][mo][1]+=f[p][s][r][mo][1]+f[p][s][r][mo][0];
            else
            {
              if (i==ss[w]-48)
              {
                f[1-p][s+i][(r*10+i)%mo][mo][1]+=f[p][s][r][mo][1];
                f[1-p][s+i][(r*10+i)%mo][mo][0]+=f[p][s][r][mo][0];
              }
              else
              {
                f[1-p][s+i][(r*10+i)%mo][mo][1]+=f[p][s][r][mo][1];
              }
            }
      p=1-p;
    }
  int sum=0;
  for (int i=0;i<mm;i++)
    sum+=f[p][i][0][i][0]+f[p][i][0][i][1];
  return sum;
}

int main()
{
  //freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&a,&b);
    pf("Case %d: %d\n",zz,dp(b)-dp(a-1));
  }
  return 0;
}
