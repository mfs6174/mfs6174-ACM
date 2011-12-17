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

int i,j,k,t,n,m,zz,zu;
string s,ss;

int main()
{
  freopen("ti.in","r",stdin);
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>ss;
    t=ss.find("://");
    s=ss.substr(t+3,ss.size()-t-2);
    t=s.find(":");
    if (t!=string::npos)
      s=s.substr(0,t);
     else
      {
        t=s.find("/");
        if (t==string::npos)
          t=s.size();
        s=s.substr(0,t);
      }
    cout<<"Case #"<<zz<<": ";
    cout<<s<<endl;
  }
}

