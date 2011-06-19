/*
ID: mfs.dev2
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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  long long  x,y;
};

long long i,j,k,n,m,a,b,w,h,s,t,p,q,mm,zongc,zongk;
D jia[20],jian[20];

long long suan(long long x,long long y,long long  p,long long  q)
{
  if (x<p||y<q)
    return 0;
  return (x-p+1)*(y-q+1);
}

int main()
{
  inf>>w>>h>>a>>b>>s>>t>>p>>q;
  jia[1].x=b+a;jia[1].y=b+2*a;
  jia[2].x=b-a;jia[2].y=5*a+b*2;
  jia[3].x=3*a+2*b;jia[3].y=a;
  jia[4].x=a,jia[4].y=5*a+2*b;
  jia[5].x=3*a+2*b;jia[5].y=a;
  jia[6].x=a+b;jia[6].y=2*a+b;
  jia[7].x=3*a+2*b;jia[7].y=a;
  jia[8].x=a+b;jia[8].y=3*a+b;
  jia[9].x=3*a+2*b;jia[9].y=b;
  jia[10].x=b;jia[10].y=b;
  jia[11].x=b;jia[11].x=b;

  jian[1].x=b-a;jian[1].y=2*a+b;
  jian[2].x=a+b;jian[2].y=a;
  jian[3].x=b-a;jian[3].y=a;
  jian[4].x=a+b;jian[4].y=a;
  jian[5].x=b-a;jian[5].y=2*a+b;
  jian[6].x=b-a;jian[6].y=a;
  jian[7].x=a;jian[7].y=a;
  jian[8].x=a;jian[8].y=a;
  jian[9].x=a+b;jian[9].y=a;
  jian[10].x=a+b;jian[10].y=b;
  jian[11].x=a;jian[11].y=2*a+b;
  jian[12]=jian[11];

  jia[12].x=t+q;jia[12].y=s;
  jia[13].x=t;jia[13].y=w-s;
  jia[14].x=h-t;jia[14].y=w-s-p;
  jia[15].x=h-t-q;jia[15].y=s+p;
  zongc=3*a+2*b;
  zongk=10*a+3*b;
  for (i=12;i<=15;i++)
    mm+=suan(jia[i].x,jia[i].y,zongc,zongk);
  for (i=1;i<=11;i++)
    mm+=suan(jia[i].x,jia[i].y,p,q);
  for (i=1;i<=12;i++)
    mm-=suan(jian[i].x,jian[i].y,p,q);
  for (i=1;i<=4;i++)
    mm+=suan(jian[7].x,jian[7].y,p,q);
  cout<<mm<<endl;
  return 0;
}
