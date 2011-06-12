/*
ID: mfs6174
PROG: CF 73 B
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int tu[50][50],qi[3000][2];
double d[50][50],jian[300],mm;
int i,j,n,m,k,t,rr;
char tc;

double suan(int x,int y,int xx,int yy)
{
  return sqrt((x-0.5-(xx-0.5))*(x-0.5-(xx-0.5))+(y-0.5-(yy-0.5))*(y-0.5-(yy-0.5)));
}

void dij(int x,int y)
{
  int i,j;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      if (tu[i][j]=='S')
        continue;
      d[i][j]=min(d[i][j],suan(x,y,i,j));
      jian[tu[i][j]-32]=d[i][j];
    }
}

int main()
{
  for (i=1;i<=300;i++)
    jian[i]=-1;
  cin>>n>>m>>mm;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      d[i][j]=maxlongint;
      cin>>tc;
      tu[i][j]=tc;
      jian[tc]=0;
      if (tc=='S')
      {
        qi[0][0]++;
        qi[qi[0][0]][0]=i;
        qi[qi[0][0]][1]=j;
        jian[tc]=-1;
      }
    }
  for (i=1;i<=qi[0][0];i++)
    dij(qi[i][0],qi[i][1]);
  cin>>k;
  for (i=1;i<=k;i++)
  {
    cin>>tc;
    if (jian[tc]==-1)
    {
      cout<<-1<<endl;
      exit(0);
    }
    if (jian[tc]>mm)
      rr++;
  }
  cout<<rr<<endl;
}

