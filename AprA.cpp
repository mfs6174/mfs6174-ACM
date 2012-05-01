
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

double f[100050][5],fen[5];
int i,j,k,t,n,a,b,m;

int main()
{
  while (cin>>n>>m>>a>>b)
  {
    for (i=0;i<=4;i++)
      fen[i]=1.0/(n-i);
    if (a==b)
    {
      f[0][0]=f[0][1]=1;
      f[0][2]=0;
      for (i=1;i<=m;i++)
      {
        f[i][2]=f[i-1][0]*fen[0]*2.0+f[i-1][2]*fen[0]/fen[2]*fen[1]*2.0+f[i-1][2]*fen[0]/fen[2];//*2.0;
        f[i][0]=f[i][1]=1.0-f[i][2];
      }
      printf("%.6lf\n",f[m][1]);
    }
    else
    {
      f[0][0]=1.0;
      f[0][1]=0;
      f[0][2]=0;
      for (i=1;i<=m;i++)
      {
        f[i][0]=(f[i-1][1]+f[i-1][2])*fen[0]*fen[1]*2.0+f[i-1][0]*fen[0]/fen[2];//*2.0;
        f[i][1]=(f[i-1][0]+f[i-1][2])*fen[0]*fen[1]*2.0+f[i-1][1]*fen[0]/fen[2];//*2.0;
        f[i][2]=(f[i-1][0]+f[i-1][1])*fen[0]*fen[1]/fen[2]*2.0+f[i-1][2]*fen[0]*fen[1]/fen[3]*2.0+f[i-1][2]*fen[0]/fen[2];//*2.0;
        if (i==1)
          f[i][0]=1.0-f[i][1]-f[i][2];
      }
      printf("%.6lf\n",f[m][1]);
    }
  }
}
