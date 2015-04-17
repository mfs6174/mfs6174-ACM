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
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

int dp[1100][1100];

const int mod=100007;
int main()
{
  string ss;
  int zu;
  cin>>zu;
  for (int zz=1;zz<=zu;zz++)
  {
    cin>>ss;
    memset(dp,0,sizeof(dp));
    for (int i=0;i<ss.size();i++)
    {
      dp[i][i+1]=1;
    }
    for (int j=2;j<=ss.size();j++)
    {
      for (int i=0;i<ss.size();i++)
      {
        if (i+j>ss.size())
          break;
        if (ss[i]==ss[i+j-1])
          dp[i][i+j]=(dp[i+1][i+j-1]%mod+1)%mod;
        dp[i][i+j]=(dp[i][i+j]+dp[i][i+j-1]%mod+dp[i+1][i+j]%mod-dp[i+1][i+j-1]%mod)%mod;
      }
    }
    printf("Case #%d: %d\n",zz,dp[0][ss.size()]%mod);
  }
  return 0;
}
