/*
ID: mfs6174
PROG: GCJ2011B
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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,l,zz,zu;
char he[300][300],cc,c;
bool sha[300][300],ff[300];
vector<char> ll;
string tt;

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n;
    memset(he,0,sizeof(he));
    memset(sha,0,sizeof(sha));
    memset(ff,0,sizeof(ff));
    for (i=1;i<=n;i++)
    {
      inf>>tt;
      he[tt[0]][tt[1]]=he[tt[1]][tt[0]]=tt[2];
    }
    inf>>m;
    for (i=1;i<=m;i++)
    {
      inf>>tt;
      sha[tt[0]][tt[1]]=sha[tt[1]][tt[0]]=true;
      ff[tt[0]]=ff[tt[1]]=true;
    }
    inf>>l>>tt;
    ll.clear();
    ll.push_back(tt[0]);
    for (i=2;i<=l;i++)
    {
      c=tt[i-1];
      cc=*(ll.end()-1);
      if (he[c][cc])
      {
        c=he[c][cc];
        ll.pop_back();
      }
      ll.push_back(c);
      if (ff[c])
        for (vector<char>::iterator it=ll.begin();it!=ll.end();it++)
          if (sha[*it][c])
          {
            ll.clear();
            break;
          }
        
    }
    ouf<<"Case #"<<zz<<": [";
    for (vector<char>::iterator it=ll.begin();it!=ll.end();it++)      
    {
      if (it!=ll.begin())
        ouf<<", ";
      ouf<<(*it);
    }
    ouf<<']'<<endl;
  }
}
