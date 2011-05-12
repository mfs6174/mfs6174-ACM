/*
ID: mfs.dev2
PROG: buylow
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
ifstream inf("buylow.in");
ofstream ouf("buylow.out");
const int maxlongint=2147483647;

int i,j,n,rr=1;
int shu[5100],f[5100];
int zhong[5100],mm=1;
bool ff;

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>shu[i];
    f[i]=1;
  }
  zhong[1]=1;
  for (i=2;i<=n;i++)
  {
    ff=false;
    for (j=i-1;j>=1;j--)
    {
      if (shu[j]==shu[i])
      {
        ff=true;
        break;
      }
      if (shu[j]>shu[i])
      {
        if (f[j]+1>f[i])
        {
          zhong[i]=zhong[j];
          f[i]=f[j]+1;
        }
        else
        {
          if (f[j]+1==f[i])
            zhong[i]+=zhong[j];
        }
      }
    }
    if ((f[i]==1)&&(!ff))
      zhong[i]=1;
    if (f[i]>mm)
    {
      mm=f[i];
      rr=zhong[i];
    }
    else
    {
      if (f[i]==mm)
        rr+=zhong[i];
    }
  }
  ouf<<mm<<' '<<rr<<endl;
  return 0;
}

  
