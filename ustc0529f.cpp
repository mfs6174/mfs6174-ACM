/*
ID: mfs6174
PROG: ustc 0529 F
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
const int maxlongint=2147483647;

int i,j,n,k,t,s,e,zz;
long long tu[300][300],zhen[300][300],gao[300];
long long m;

int main()
{
  while (cin>>n>>zz)
  {
    for (i=1;i<=n;i++)
      cin>>gao[i];
    for (i=1;i<=n;i++)
      for (j=i;j<=n;j++)
        zhen[i][j]=zhen[j][i]=tu[i][j]=tu[j][i]=abs(gao[i]-gao[j])*abs(i-j);
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          zhen[i][j]=min(zhen[i][j],zhen[i][k]+zhen[k][j]);
    for (i=1;i<=zz;i++)
    {
      cin>>s>>e>>m;
      if (zhen[s][e]<=m)
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }
  }
}

        
  
