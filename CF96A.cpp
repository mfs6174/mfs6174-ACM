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
string ss;
bool fl=false;
int main()
{
  cin>>ss;
  n=ss.size();
  for (i=0;i<n;i++)
    if (ss[i]=='H'||ss[i]=='Q'||ss[i]=='9')
      fl=true;
  if (fl)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

