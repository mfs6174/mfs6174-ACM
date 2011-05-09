/*
ID: mfs6174
PROG: XD1012
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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,a,b;
int f[100010];

int main()
{
  while (inf>>a>>b)
  {
    i=a-1;
    memset(f,0,sizeof(f));
    while (i*2>=a)
    {
      if (i<0)
        break;
      f[i]=a-i;
      i--;
    }
    f[a]=0;
    f[2*a]=1;
    while (1)
    {
      bool ff=false;
      for (i=a+1;i<=b;i++)
      {
        if (!f[i])
          f[i]=maxlongint;
        if (f[i-1]+1<f[i])
        {
          f[i]=f[i-1]+1;
          ff=true;
        }
        if ((!(b&1))&&(f[i/2]!=0)&&(f[i/2]+1<f[i]))
        {
          f[i]=f[i/2]+1;
          ff=true;
        }
      }
      for (i=b-1;i>a;i--)
        if (f[i+1]+1<f[i])
        {
          f[i]=f[i+1]+1;
          ff=true;
        }
      if (!ff)
        break;
    }
    cout<<f[b]<<endl;
  }
}
