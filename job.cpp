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
int n,sheng,a,b,i,j,ss;
int jia[35],jib[35],huo[1020];
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
  sheng=1;
  for (i=b;i>=1;i--)
  {
    if (sheng>n)
      break;
    tt.shi=jib[i]+huo[sheng];
    tt.hao=i;
    xian.insert(tt);
    sheng++;
  }
  a=xian.size();
  while (true)
  {
    t=*(xian.begin());
    xian.erase(xian.begin());
    if (sheng<=n)
    {
      tt.shi=((t.shi>huo[sheng])?(t.shi):(huo[sheng]))+jib[t.hao];
      tt.hao=t.hao;
      xian.insert(tt);
      sheng++;
    }
    else
    {
      if (xian.empty())
        break;
      ttt=*(xian.rbegin());
      if (((t.shi>ttt.shi-jib[ttt.hao])?(tt.shi):(ttt.shi-jib[ttt.hao]))+jib[t.hao]<ttt.shi)
      {
        xian.erase(--xian.end());
        tt.shi=(t.shi>ttt.shi-jib[ttt.hao])?(tt.shi):(ttt.shi-jib[ttt.hao])+jib[t.hao];
        tt.hao=t.hao;
        xian.insert(tt);
      }
    }
  }
  ouf<<t.shi<<endl;
}

