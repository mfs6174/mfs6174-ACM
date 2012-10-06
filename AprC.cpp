
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

int mi[40],mii;
int i,j,k,t,zz,zu;
unsigned  n,mm,tt;

int main()
{
  mi[0]=2;
  for (i=1;i<=35;i++)
    mi[i]=mi[i-1]*mi[i-1]%9973;
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%ud",&n);
    i=0;
    mm=1;
    tt=n;
    n--;
    while (n)
    {
      if (n&1)
        mm=(mm*((mi[i])%9973))%9973;
      i++;
      n=n>>1;
    }
    mm=mm*((tt-2)%9973)%9973;
    mm=(mm+1)%9973;
    t=mm;
    printf("%d\n",t);
  }
}

