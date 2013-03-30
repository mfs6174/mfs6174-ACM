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

int i,j,k,t,n,m,zu,zz,s,d,o;
int f[200][200];
int shi[200],kong[200];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>k>>d>>s;
    for (i=0;i<=k;i++)
      for (j=0;j<=n;j++)
        f[i][j]=maxlongint;
    f[0][n]=0;
    for (i=1;i<=k;i++)
      cin>>shi[i]>>kong[i];
    for (i=1;i<=k;i++)
    {
      for (j=0;j<=n;j++)
        if (f[i-1][j]!=maxlongint)
        {
          for (o=0;o<=kong[i];o++)
            if (o<=j)
            {
              int dd=0;
              if (o)
                dd=d;
              f[i][j-o]=min(f[i][j-o],f[i-1][j]+dd+(j)*(shi[i]-shi[i-1]));
            }
        }
    }
    if (f[k][0]!=maxlongint)
      cout<<f[k][0]<<endl;
    else
      cout<<"impossible"<<endl;
  }
  return 0;
}
