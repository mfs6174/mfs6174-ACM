/*
ID: mfs6174
PROG: GCJ2011A
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

struct D
{
  int x,h;
};
int f[500],cheng[500],lan[500],shang[500];
D an[500];
int i,j,k,t,zz,zu,c,cc,n;
char tc;

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n;
    c=1;
    cc=1;
    cheng[1]=0;lan[1]=0;
    f[0]=0;
    an[0].x=1;
    for (i=1;i<=n;i++)
    {
      inf>>tc>>an[i].x;
      if (tc=='O')
      {
        c++;
        cheng[c]=i;
        shang[i]=cheng[c-1];
        an[i].h=0;
      }
      else
      {
        cc++;
        lan[cc]=i;
        shang[i]=lan[cc-1];
        an[i].h=1;
      }
    }
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      f[i]=max(f[i-1]+1,abs(an[i].x-an[shang[i]].x)+f[shang[i]]+1);
    ouf<<"Case #"<<zz<<": "<<f[n]<<endl;
  }
}

        
  
