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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,t,n,m;
int a[300];
int zu,zz;
vector<int> ddd;
int main()
{
  a[9]=a[0]=a[4]=a[5]=4;
  a[10]=a[6]=a[1]=a[2]=3;
  a[3]=a[7]=a[8]=5;
  a[11]=a[12]=6;
  a[13]=a[14]=a[18]=a[19]=8;
  a[15]=a[16]=7;
  a[17]=9;
  a[20]=a[30]=a[80]=a[90]=6;
  a[40]=a[50]=a[60]=5; a[70]=7;
  for(int o=20;o<=90;o+=10)
	for(int i=1;i<=9;i++)
      a[o+i]=a[o]+a[i];
  for (i=0;i<=99;i++)
    a[100+i]=a[i]+6;
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>m;
    ddd.clear();
    for (i=0;i<=199;i++)
      if (a[i]==n)
        ddd.push_back(i);
    sort(ddd.begin(),ddd.end());
    k=ddd.size();
    if (m>k)
    {
      pf("Case #%d: -1\n",zz);
    }
    else
    {
      if (ddd[m-1]>99)
        t=ddd[m-1]-100;
      else
        t=ddd[m-1];
      pf("Case #%d: %d",zz,t);
      if (ddd[m-1]>99)
        for (i=1;i<=100;i++)
          pf("0");
      pf("\n");
    }
  }
  return 0;
}

