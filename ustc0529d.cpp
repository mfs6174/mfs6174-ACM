/*
ID: mfs6174
PROG: ustc 0529 D
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
const long long  su=100007; //坑爹啊,100007**2 超maxlongint了

int i,j,t,k,n,m,cc,ss;
long long  shu[10010],he[10010],mi[10010],wei[10010];
long long  mm;

int main()
{
  mi[0]=1;
  for (i=1;i<=10001;i++)
    mi[i]=mi[i-1]*2%su;
  while (cin>>n)
  {
    mm=cc=0;
    for (i=1;i<=n;i++)
      cin>>shu[i];
    sort(&(shu[1]),&(shu[n+1]));
    t=-1;
    he[0]=0;
    for (i=1;i<=n;i++)
      if (shu[i]!=t)
      {
        he[i]=he[i-1]+1;
        t=shu[i];
        cc++;
        wei[cc]=i-1;
      }
      else
        he[i]=he[i-1];
    ss=he[n];
    for (i=2;i<=cc;i++)
      mm=(mm+mi[he[wei[i]]-1]*((mi[ss-he[wei[i]]]-1)%su)%su)%su;
    // if (ss==1)
    // mm=1;
    cout<<mm%su<<endl;
  }
}

