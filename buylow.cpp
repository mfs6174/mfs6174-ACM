/*
ID: mfs.dev2
PROG: buylow
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
ifstream inf("buylow.in");
ofstream ouf("buylow.out");
const int maxlongint=2147483647;


class dashu
{
public:
  int a[160];
  void zhuan(string x)
  {
    int i;
    memset(a,0,sizeof(a));
    a[0]=x.size();
    for (i=1;i<=a[0];i++)
      a[i]=x[a[0]-i]-48;
  }
  bool xiaoyu(dashu &x,bool &ff)
  {
    int i;
    ff=false;
    if (a[0]<x.a[0])
      return true;
    else if (a[0]>x.a[0])
      return false;
    for (i=a[0];i>=1;i--)
      if (a[i]<x.a[i])
        return true;
      else if (a[i]>x.a[i])
        return false;
    ff=true;
    return false;
  }
				
  void dayin(int x)
  {
    int i,t;
    for (t=1;a[t]==0;t++);
    if (!x)
      t=1;
    if (a[0]<x)
    {
      ouf<<'.';
      for (i=1;i<=x-a[0];i++)
        ouf<<'0';
    }
    for (i=a[0];i>=t;i--)
    {
      if (i==x)
        ouf<<'.';
      ouf<<a[i];
    }
    ouf<<endl;
  }
};

dashu jia(dashu &x,dashu &y)
{
	int i;
	dashu rr;
	memset(rr.a,0,sizeof(rr.a));
	rr.a[0]=(x.a[0]>y.a[0])?(x.a[0]):(y.a[0]);
	for (i=1;i<=rr.a[0];i++)
	{
		rr.a[i]+=x.a[i]+y.a[i];
		if (rr.a[i]>9)
		{
			rr.a[i+1]++;
			rr.a[i]-=10;
		}
	}
	if (rr.a[rr.a[0]+1]!=0)
		rr.a[0]++;
	return rr;
}

int i,j,n,mm=1;
int shu[5100],f[5100];
dashu zhong[5100],rr;
bool ff,dengyu;


int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>shu[i];
    f[i]=1;
  }
  zhong[1].zhuan("1");
  rr.zhuan("1");
  for (i=2;i<=n;i++)
  {
    ff=false;
    for (j=i-1;j>=1;j--)
    {
      if (shu[j]==shu[i])
      {
        ff=true;
        break;
      }
      if (shu[j]>shu[i])
      {
        if (f[j]+1>f[i])
        {
          zhong[i]=zhong[j];
          f[i]=f[j]+1;
        }
        else
        {
          if (f[j]+1==f[i])
            zhong[i]=jia(zhong[i],zhong[j]);
        }
      }
    }
    if ((f[i]==1)&&(!ff))
      zhong[i].zhuan("1");
    if (f[i]>mm)
    {
      mm=f[i];
      rr=zhong[i];
    }
    else
    {
      if (f[i]==mm)
        rr=jia(rr,zhong[i]);
    }
  }
  ouf<<mm<<' ';
  rr.dayin(0);
  return 0;
}

  
