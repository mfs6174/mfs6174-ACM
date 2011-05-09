
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int shu[200000],f[200000];
int dui[300];
int i,j,k,t,n,mm,l;
char tc;

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>tc>>t;
    dui[tc]=t;
  }
  while (inf>>tc)
  {
    l++;
    shu[l]=dui[tc];
  }
  f[1]=max(0,shu[1]);
  for (i=2;i<=l;i++)
  {
    f[i]=max(f[i-1]+shu[i],shu[i]);
    if (f[i]>mm)
    {
      mm=f[i];
      t=i;
    }
  }
  cout<<mm<<endl<<t<<endl;
}

  
  
  
