
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

long long f[30][30],rr;
int i,j,k,t,n,zz,zu;

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      f[i][0]=0;
      f[i][1]=1;
      f[i][i]=1;
      for (j=1;j<i;j++)
        f[i][j]=f[i-1][j]*j+f[i-1][j-1];
    }
    rr=0;
    for (i=1;i<=n;i++)
      rr+=f[n][i];
    cout<<rr<<endl;
  }
}
