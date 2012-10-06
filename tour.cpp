/*
ID: mfs.dev2
PROG: tour
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
ifstream inf("tour.in");
ofstream ouf("tour.out");
const int maxlongint=2147483647;

struct Dian
{
  int n;
  int lai[110];
};

int tt,i,j,k,n,m,t,mm;
Dian dian[110];
int f[105][105];
bool tu[105][105];
map<string,int> ming;
string st,ss;

int main()
{
  inf>>n>>m;
  for (i=1;i<=n;i++)
  {
    inf>>st;
    ming[st]=i;
  }
  for (i=1;i<=m;i++)
  {
    inf>>ss>>st;
    t=max(ming[ss],ming[st]);
    tt=min(ming[ss],ming[st]);
    tu[tt][t]=tu[t][tt]=true;
    dian[t].n++;
    dian[t].lai[dian[t].n]=tt;
  }
  f[1][1]=1;
  mm=1;
  for (i=1;i<n;i++)
  {
    for (j=i+1;j<=n;j++)
      for (k=1;k<=dian[j].n;k++)
        if (((dian[j].lai[k]!=i)||(dian[j].lai[k]==1))&&(f[i][dian[j].lai[k]]))
          f[i][j]=max(f[i][j],f[i][dian[j].lai[k]]+1);
    for (j=1;j<=n;j++)
      f[j][i]=f[i][j];
    if (tu[i][n]&&f[i][n])
      mm=max(mm,f[i][n]);
  }
  ouf<<mm<<endl;
}
