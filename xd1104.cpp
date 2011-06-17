#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
const int maxlongint=2147483647;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");

int i,j,k,t,n,m,zz,zu;
string s,ss;

int main()
{
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
     cout<<s<<endl;
  }
}

