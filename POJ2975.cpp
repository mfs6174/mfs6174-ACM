2/*
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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

int i,j,k,n;
unsigned shu[1100],t;
int wei[40];
long long  f[40][2],mm;
int ww[1100][35];
int main()
{
  while (cin>>n&&n)
  {
    mm=0;
    memset(wei,0,sizeof(wei));
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      cin>>shu[i];
      t=shu[i];
      for (j=1;j<=32;j++)
      {
        k=33-j;
        if (t&1)
        {
          wei[k]++;
          ww[i][k]=1;
        }
        else
          ww[i][k]=0;
        t=t>>1;
      }
    }
    mm=0;
    for (j=1;j<=n;j++)
    {
      memset(f,0,sizeof(f));
      f[1][0]=1;
      bool fl=false;
      for (i=2;i<=32;i++)
      {
        if (wei[i]&1)
        {
          fl=true;
          if (ww[j][i])
            f[i][1]=f[i-1][1]+f[i-1][0];
          else
            f[i][1]=f[i-1][1];
        }
        else
        {
          f[i][0]=f[i-1][0];
          f[i][1]=f[i-1][1];
        }
      }
      if (fl)
        mm+=f[32][0]+f[32][1];
      else
        mm=0;
    }
    cout<<mm<<endl;
  }
  return 0;
}


