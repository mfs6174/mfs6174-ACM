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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m;
char s[500];
char key[500];
string ss[6],sa;
char tc;

int main()
{
  ss[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
  ss[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  ss[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
  ss[3]="our language is impossible to understand";
  ss[4]="there are twenty six factorial possibilities";
  ss[5]="so it is okay if you want to just give up";
  freopen("ti.in","r",stdin);
  key['q']='z';
  key['z']='q';
  for (i=0;i<=2;i++)
    for (j=0;j<ss[i].size();j++)
      if (ss[i][j]!=' ')
        key[ss[i][j]]=ss[i+3][j];
  sf("%d\n",&n);
  for (k=1;k<=n;k++)
  {
    gets(s);
    sa=string(s);
    for (i=0;i<sa.size();i++)
      if (sa[i]!=' ')
        sa[i]=key[sa[i]];
    ouf<<"Case #"<<k<<": "<<sa<<endl;
  }
  return 0;
}


