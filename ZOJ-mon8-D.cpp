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

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

string shu[60];
int i,j,k,t,n,m,mm,rr;
int f[60];
char ts[6000];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    rr=0;
    getchar();
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=m;j++)
      {
        gets(ts);
        shu[j]=ts;
      }
      f[1]=1;mm=1;
      for (j=2;j<=m;j++)
      {
        f[j]=1;
        for (k=1;k<j;k++)
          if (shu[k]<=shu[j])
          {
            f[j]=max(f[j],f[k]+1);
            mm=max(mm,f[j]);
          }
      }
      rr+=m-mm;
    }
    printf("%d\n",rr);
  }
  return 0;
}
