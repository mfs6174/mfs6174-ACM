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

int i,j,k,t,n,m,zu,zz,mm,sq,tt;
int n1,n2;
int s[11000],ss[11000];

inline bool cmp(const int a,const int b)
{
  return a>b;
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d%d%d",&n,&m,&n1,&n2);
    for (i=1;i<=n1;i++)
      scanf("%d",&s[i]);
    for (i=1;i<=n2;i++)
      scanf("%d",&ss[i]);
    sort(&s[1],&s[n1+1],cmp);
    sort(&ss[1],&ss[n2+1],cmp);
    for (i=1;i<=n1;i++)
      s[i]+=s[i-1];
    for (i=1;i<=n2;i++)
      ss[i]+=ss[i-1];
    sq=n*m;
    mm=0;
    if (min(m,n)==2&&max(n,m)%3==2)
    {
      sq-=4;
      for (i=0;i<=n2;i++)
      {
        t=sq-i*3;
        if (t<0)
          break;
        tt=min(t/2+2,n1);
        if (ss[i]+s[tt]>mm)
          mm=ss[i]+s[tt];
      }
    }
    else
    {
      for (i=0;i<=n1;i++)
      {
        t=sq-i*2;
        if (t<0)
          break;
        tt=min(t/3,n2);
        if (s[i]+ss[tt]>mm)
          mm=s[i]+ss[tt];
      }
    }
    printf("Case #%d: %d\n",zz,mm);
  }
  return 0;
}
  

