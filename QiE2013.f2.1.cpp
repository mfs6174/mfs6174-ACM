/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;


llg i,j,k,t,n,m;
llg zz,zu;
llg mod=1000000007;
llg cheng[200];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    cheng[1]=0;
    cheng[2]=1;
    for (i=3;i<=n;i++)
      cheng[i]=(i-1)*(cheng[i-2]+cheng[i-1])%mod;
    cout<<cheng[n]<<endl;
  }
  return 0;
}
    
