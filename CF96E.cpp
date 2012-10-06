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

int i,j,k,t,n,m,mm,o,p;
int f[120][3][60][3];
int zhi[120];
string ss;

inline int st(int x,int o)
{
  if (o&1)
    return 1-x;
  else
    return x;
}

int main()
{
  cin>>ss;
  n=ss.size();
  for (i=0;i<n;i++)
    if (ss[i]=='F')
      zhi[i+1]=1;
  cin>>m;
  memset(f,-1,sizeof(f));
  f[1][0][0][0]=0;
  f[1][0][0][1]=0;
  for (i=1;i<=n;i++)
    for (o=0;o<=1;o++)
      for (j=0;j<=m;j++)
        for (p=0;p<=1;p++)
        {
          if (f[i][o][j][p]<0)
            continue;
          for (k=0;k<=m;k++)
          {
            if (j+k>m)
              break;
            int s=st(zhi[i],k),nw;
            if (s)
            {
              if (o^p)
                nw=f[i][o][j][p]-1;
              else
                nw=f[i][o][j][p]+1;
              if (nw>=0)
                f[i+1][o][j+k][p]=max(f[i+1][o][j+k][p],nw);
              else
                f[i+1][o][j+k][1-p]=max(f[i+1][o][j+k][1-p],-nw);
            }
            else
            {
              f[i+1][1-o][j+k][p]=max(f[i+1][1-o][j+k][p],f[i][o][j][p]);
            }
          }
        }
  for (o=0;o<=1;o++)
    for (p=0;p<=1;p++)
      mm=max(mm,f[n+1][o][m][p]);
  cout<<mm<<endl;
  return 0;
}

