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
#include<set>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,t,n,m,k,zz,zu;
multiset<int> shu;
int shi[110000];

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    shu.clear();
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%d",&shi[i]);
    if (n<m)
    {
      cout<<0<<endl;
      continue;
    }
    for (i=1;i<=m;i++)
      shu.insert(shi[i]);
    for (i=m+1;i<=n;i++)
    {
      t=*(shu.begin());
      shu.erase(shu.begin());
      shu.insert(t+shi[i]);
    }
    t=*(shu.begin());
    cout<<t<<endl;
  }
  return 0;
}

