/*
ID: mfs.dev2
PROG: job
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
ifstream inf("job.in");
ofstream ouf("job.out");
const int maxlongint=2147483647;

class ji
{
public:
  int shi,hao;
  bool operator <(const ji &x) const
  {
    return shi<x.shi;
  }
};
int n,sheng,a,b,i,j,ss,mm;
int jia[35],jib[35],huo[1020],huob[1020];
multiset<ji> xian;
ji tt,t,ttt;

void pai(int a[],int n)
{
  int i,j,t;
  for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
      if (a[j]<a[i])
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
}

int main()
{
  inf>>n>>a>>b;
  for (i=1;i<=a;i++)
    inf>>jia[i];
  for (i=1;i<=b;i++)
    inf>>jib[i];
  pai(jia,a);
  pai(jib,b);
  sheng=n;
  for (i=1;i<=a;i++)
  {
    if (!sheng)
      break;
    tt.shi=jia[i];
    tt.hao=i;
    xian.insert(tt);
    sheng--;
  }
  while (true)
  {
    t=*(xian.begin());
    ss++;
    huo[ss]=t.shi;
    xian.erase(xian.begin());
    if (sheng)
    {
      tt.shi=t.shi+jia[t.hao];
      tt.hao=t.hao;
      xian.insert(tt);
      sheng--;
    }
    else
    {
      if (xian.empty())
        break;
      ttt=*(xian.rbegin());
      if (t.shi+jia[t.hao]<ttt.shi)
      {
        xian.erase(--xian.end());
        tt.shi=t.shi+jia[t.hao];
        tt.hao=t.hao;
        xian.insert(tt);
      }
    }
  }
  ouf<<t.shi<<' ';
  xian.clear();
  sheng=n;
  ss=0;
   for (i=1;i<=b;i++)
  {
    if (!sheng)
      break;
    tt.shi=jib[i];
    tt.hao=i;
    xian.insert(tt);
    sheng--;
  }
  while (true)
  {
    t=*(xian.begin());
    ss++;
    huob[ss]=t.shi;
    xian.erase(xian.begin());
    if (sheng)
    {
      tt.shi=t.shi+jib[t.hao];
      tt.hao=t.hao;
      xian.insert(tt);
      sheng--;
    }
    else
    {
      if (xian.empty())
        break;
      ttt=*(xian.rbegin());
      if (t.shi+jib[t.hao]<ttt.shi)
      {
        xian.erase(--xian.end());
        tt.shi=t.shi+jib[t.hao];
        tt.hao=t.hao;
        xian.insert(tt);
      }
    }
  }
  for (i=1;i<=n;i++)
    mm=(huo[i]+huob[n+1-i]>mm)?(huo[i]+huob[n+1-i]):mm;
  ouf<<mm<<endl;
}

