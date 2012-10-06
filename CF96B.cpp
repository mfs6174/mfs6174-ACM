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

int i,j,k,t,n,m;
int mod=1000003;
int dui[300];
string ss;

int main()
{
  dui['>']=8;
  dui['<']=9;
  dui['+']=10;
  dui['-']=11;
  dui['.']=12;
  dui[',']=13;
  dui['[']=14;
  dui[']']=15;
  cin>>ss;
  n=ss.size();
  m=0;
  for (i=0;i<n;i++)
  {
    m=m<<4;
    m=m%mod;
    m+=dui[ss[i]];
    m=m%mod;
  }
  m=m%mod;
  cout<<m<<endl;
  return 0;
}
