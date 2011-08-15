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

int i,j,n,m,t;
double k;
map<string,int> shu;
string ss;

int main()
{
  cin>>n>>m>>k;
  for (i=1;i<=n;i++)
  {
    cin>>ss;
    cin>>t;
    t=(int)(t*k);
    if (t>=100)
      shu[ss]=t;
  }
  for (i=1;i<=m;i++)
  {
    cin>>ss;
    map<string,int>::iterator w=shu.find(ss);
    if (w==shu.end())
      shu[ss]=0;
  }
  cout<<shu.size()<<endl;
  for (map<string,int>::iterator i=shu.begin();i!=shu.end();i++)
    cout<<(*i).first<<' '<<(*i).second<<endl;
  return 0;
}

