#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
const int maxlongint=2147483647;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");

int i,j,k,t,n,m,zz,zu,a,b;
vector<int> ss;

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>m;
    ss.clear();
    for (i=1;i<=n;i++)
      ss.push_back(i);
    for (i=1;i<=m;i++)
    {
      cin>>a>>b;
      reverse(ss.begin()+a-1,ss.begin()+b);
    }
    for (i=0;i<n-1;i++)
      cout<<ss[i]<<' ';
    cout<<ss[n-1]<<endl;
  }
}

  
