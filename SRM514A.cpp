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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

class agicalGirlLevelOneDivTwo
{
public:
  double theMinDistance(int d, int x, int y)
  {
    double rr;
    int t,tt;
    if (x>0)
      t=x-d;
    else
      t=-x-d;
    if (t<0) t=0;
    if (y>0)
      tt=y-d;
    else
      tt=-y-d;
    if (tt<0)tt=0;
    rr=sqrt(t*t+tt*tt);
    return rr;
  }
};

