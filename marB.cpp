
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

int n,m,i,j,k,t,zu,zz,rr,mm;
int hua[20],shu[15][15000],tong[15],wei[15],fl[15];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>m;
    for (i=1;i<=m;i++)
      cin>>hua[i];
    memset(shu,0,sizeof(shu));
    mm=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        cin>>t;
        shu[j][t]++;
        if (t>mm)
          mm=t;
      }
    t=n/2+1;
    memset(fl,0,sizeof(fl));
    memset(tong,0,sizeof(tong));
    for (i=0;i<=mm;i++)
      for (j=1;j<=m;j++)
        if (!fl[j])
        {
          tong[j]+=shu[j][i];
          if (tong[j]>=t)
          {
            fl[j]=true;
            wei[j]=i;
          }
        }
    rr=0;
    for (i=0;i<=mm;i++)
      for (j=1;j<=m;j++)
        rr+=abs(i-wei[j])*shu[j][i]*hua[j];
    cout<<rr<<endl;
  }
}

      
          
