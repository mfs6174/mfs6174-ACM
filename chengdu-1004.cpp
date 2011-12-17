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

int i,j,k,t,n,m,zz,zu,cc;
int d[200][200];
bool tu[200][200],fl;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d",&n);
    printf("Case %d: ",zz);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&d[i][j]);
    fl=true;cc=0;
    memset(tu,0,sizeof(tu));
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
          if (i==k||j==k)
            continue;
          if (d[i][k]+d[k][j]<d[i][j])
          {
            fl=false;
            break;
          }
          if (d[i][k]+d[k][j]==d[i][j])
            tu[i][j]=true;
        }
    if (!fl)
      cout<<"impossible"<<endl;
    else
    {
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          if ((!tu[i][j])&&(i!=j))
            cc++;
      cout<<cc<<endl;
    }
  }
  return 0;
}

      
            
      

