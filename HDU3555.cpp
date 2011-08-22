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
#include<map>
#include<vector>
#define LL long long
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

long long i,j,k,t,n,m,zz,zu,nn;
long long f[30][10][3];
LL zh[10][15];
string s;
string str(LL x)
{
    ostringstream t;
    t<<x;
    return t.str();
}


int main()
{
  zh[0][4]=1;zh[1][4]=1;
  zh[1][9]=2;
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>nn;
    s=str(nn);
    memset(f,0,sizeof(f));
    n=s.size();
    f[0][0][0]=1;
    for (i=0;i<=n;i++)
      for (j=0;j<2;j++)
      {
        if (f[i][j][0])
        {
          for (k=0;k<s[i]-48;k++)
            f[i+1][zh[j][k]][1]+=f[i][j][0];
          f[i+1][zh[j][k]][0]+=f[i][j][0];
        }
        if (f[i][j][1])
          for (k=0;k<=9;k++)
            f[i+1][zh[j][k]][1]+=f[i][j][1];
      }
    m=0;
    for (i=0;i<2;i++)
      m+=f[n][i][0]+f[n][i][1];
    cout<<nn-m+1<<endl;
  }
  return 0;
}
