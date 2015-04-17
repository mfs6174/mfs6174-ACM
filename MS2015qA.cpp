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

int main(int argc, char *argv[])
{
  int zu,zz;
  cin>>zu;
  string mlist[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
  for (zz=1;zz<=zu;zz++)
  {
    string mon;
    int mm1,mm2;
    int dd1,dd2,yy1,yy2;
    cin>>mon;
    cin>>dd1;
    char tc;
    cin>>tc;
    cin>>yy1;
    for (int tm=0;tm<12;tm++)
      if (mon==mlist[tm])
      {
        mm1=tm+1;
        break;
      }
    cin>>mon;
    cin>>dd2;
    cin>>tc;
    cin>>yy2;
    for (int tm=0;tm<12;tm++)
      if (mon==mlist[tm])
      {
        mm2=tm+1;
        break;
      }
    int st,ed;
    if (mm1<=2)
      st=yy1;
    else
      st=yy1+1;
    if (mm2>2 || (mm2==2 && dd2>28))
      ed=yy2+1;
    else
      ed=yy2;
    int ly;
    ed--;
    st--;
    int ly1=st/4-st/100+st/400;
    int ly2=ed/4-ed/100+ed/400;
    ly=ly2-ly1;
    pf("Case #%d: %d\n",zz,ly);
  }
  return 0;
}
    
