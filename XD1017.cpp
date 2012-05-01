/*
ID: mfs.dev2
For DUAN
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
//ifstream inf("1017.in");
//ofstream ouf("1017.out");
const int maxlongint=2147483647;

string ss;
int n;
bool dengyu;

int val(const string &x)
{
    istringstream t(x);
    int r;
    t>>r;
    return r;
}

void str(long long x,string &y)
{
    ostringstream t;
    t<<x;
    y=t.str();
}


class dashu{
public:
  long long  a[1500];
  dashu (string x)
  {
    int i,l=x.size();
    memset(a,0,sizeof(a));
    a[0]=(x.size()+7)/8;
    for (i=1;i<a[0];i++)
      a[i]=val(x.substr(l-8*i,8));
    a[a[0]]=val(x.substr(0,l-8*(a[0]-1)));
  }
  dashu (int x)
  {
    memset(a,0,sizeof(a));
    a[0]=1;
    a[1]=x;
  }
  void dayins(string &s)
  {
    string t;
    int i,j;
    str(a[a[0]],s);
    for (i=a[0]-1;i>=1;i--)
    {
      str(a[i],t);
      for (j=1;j<=8-t.size();j++)
        t="0"+t;
      s=s+t;
    }
  }
    
  bool operator<(const dashu &x) const
  {
    int i;
    dengyu=false;
    if (a[0]<x.a[0])
      return true;
    else if (a[0]>x.a[0])
      return false;
    for (i=a[0];i>=1;i--)
      if (a[i]<x.a[i])
        return true;
      else if (a[i]>x.a[i])
        return false;
    dengyu=true;
    return false;
  }
};
	
dashu cheng(const dashu &x,const dashu &y)
{
  int i,j;
  dashu rr(0);
  rr.a[0]=x.a[0]+y.a[0];
  for (i=1;i<=x.a[0];i++)
    for (j=1;j<=y.a[0];j++)
    {
      rr.a[i+j-1]+=x.a[i]*y.a[j];
      rr.a[i+j]+=rr.a[i+j-1]/100000000;
      rr.a[i+j-1]=rr.a[i+j-1]%100000000;
    }
  if (rr.a[rr.a[0]+1]!=0)
    rr.a[0]++;
  while ((rr.a[rr.a[0]]==0)&&(rr.a[0]>1))
    rr.a[0]--;
  return rr;
}

int i,j,k;
long long b;

int main()
{
  while (cin>>ss>>b)
  {
    dashu rr(ss),chu(b);
    int ji[15],jie[15],c=0,mm=0;
    memset(ji,0,sizeof(ji));
    rr=cheng(rr,b);
    rr.dayins(ss);
    for (i=0;i<ss.size();i++)
    {
      ji[ss[i]-48]++;
      if (ji[ss[i]-48]>mm)
        mm=ji[ss[i]-48];
    }
    for (i=0;i<=9;i++)
      if (ji[i]==mm)
      {
        c++;
        jie[c]=i;
      }
    for (i=1;i<c;i++)
      cout<<jie[i]<<' ';
    cout<<jie[c]<<endl;
  }
}

      
    
