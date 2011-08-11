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

int i,j,t,n,m,zz,zu;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d",&n);
    printf("Case #%d:\n",zz);
    for (i=1;i<=n;i++)
    {
      for (j=1;j<n;j++)
        printf("%d ",((i-1)*(n-1)+j));
      printf("%d\n",(n*(n-1)+i));
    }
  }
  return 0;
}
    
      
    
