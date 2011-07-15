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
#include<deque>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int d,p;
};

int i,j,k,t,n,m,zu,zz,mm,c,xt,yt,tt;
int s[100100],d[100100],f[100100],w[100100];
deque<D> q;
D dd;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&c,&n);
    xt=0;yt=0;
    q.clear();
    w[0]=0;
    s[0]=0;
    memset(f,-1,sizeof(f));
    for (i=1;i<=n;i++)
    {
      t=xt;tt=yt;
      scanf("%d%d%d",&xt,&yt,&w[i]);
      w[i]+=w[i-1];
      s[i]=s[i-1]+abs(t-xt)+abs(tt-yt);
      s[1]=0;
      d[i]=xt+yt;
    }
    f[0]=0;
    dd.d=f[0]-s[1]+d[1];
    dd.p=0;
    q.push_back(dd);
    for (i=1;i<=n;i++)
    {
      while (w[i]-w[q.front().p]>c) q.pop_front();
      f[i]=q.front().d+s[i]+d[i];
      dd.p=i;
      dd.d=f[i]-s[i+1]+d[i+1];
      while ((!q.empty())&&(q.back().d>dd.d)) q.pop_back();
      q.push_back(dd);
    }
    cout<<"Case "<<zz<<": "<<f[n]<<endl;
  }
  return 0;
}


