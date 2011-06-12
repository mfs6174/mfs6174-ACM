/*
ID: mfs.dev2
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
const int maxlongint=2147483647;

int i,j,n,m,t,zz,zu,c,cc,k,ccc;
int shu[200][200];
char tc;
double wp[200],owp[200],oowp[200],wpp[200],tt;
int main()
{
  freopen("ti.out","w",stdout);
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n;
    for (i=1;i<=n;i++)
    {
      c=cc=0;
      for (j=1;j<=n;j++)
      {
        inf>>tc;
        if (tc=='0')
          shu[i][j]=-1;
        else if (tc=='1')
        {
          shu[i][j]=1;
          cc++;
        }
        else
          shu[i][j]=0;
        if (shu[i][j])
          c++;
      }
      wp[i]=(double)cc/c;
    }
    for (i=1;i<=n;i++)
    {
      tt=0;
      ccc=0;
      for (j=1;j<=n;j++)
        if (shu[i][j])
        {
          c=cc=0;
          ccc++;
          for (k=1;k<=n;k++)
          {
            if (k==i)
              continue;
            if (shu[j][k])
              c++;
            if (shu[j][k]==1)
              cc++;
          }
          tt+=(double)cc/c;
        }
      tt=tt/ccc;
      owp[i]=tt;
    }
    for (i=1;i<=n;i++)
    {
      tt=0;
      ccc=0;
      for (j=1;j<=n;j++)
        if (shu[i][j])
        {
          tt+=owp[j];
          ccc++;
        }
      oowp[i]=tt/ccc;
    }
    printf("Case #%d:\n",zz);
    for (i=1;i<=n;i++)
      printf("%.12lf\n",0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
  }
}

    
