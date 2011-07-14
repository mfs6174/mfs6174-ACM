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
#include<dqueue>
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int p,y;
};

dqueue<D> qian,hou;
int i,j,k,n,m,t,a,k,zz,zu,y;
int s[1010],f[1010][1010];
D tt,ttt;

inline int fang(int x)
{
  return x*x;
}

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>k>>a;
    for (i=1;i<=n;i++)
      inf>>s[i];
    qian.clear();hou.clear();
    memset(f,-1,sizeof(f));
    t=max(1000,s[1]+k);
    for (i=min(0,s[1]-k);i<=t;i++)
    {
      f[1][i]=fang(i-s[1]);
      tt.y=f[1][i]-a*i;
      tt.p=i;
      while ((!qian.empty())&&((qian.back()).y>=tt.y))
        qian.pop_back();
      qian.push_back(tt);
      tt.y=f[1][i]+a*i;
      while ((!hou.empty())&&((hou.back()).y>=tt.y))
        hou.pop_back();
      hou.push_back(tt);
    }
    for (i=2;i<=n;i++)
    {
      for (j=0;j<=1000;j++)
      {
        while (qian.front().p<j-k) qian.pop_front();
        f[i][j]=qian.front().y+a*j;
        while (hou.back().p>j+k) hou.pop_back();
        f[i][j]=min(f[i][j],hou.back().y-a*j);
        f[i][j]+=fang(s[i]-j);
        tt.y=f[i][j]-a*j;
        tt.p=j;
        while ((!qian.empty())&&((qian.back()).y>=tt.y))
          qian.pop_back();
        qian.push_back(tt);
        tt.y=f[i][j]+a*j;
        while ((!hou.empty())&&((hou.back()).y>=tt.y))
          hou.pop_back();
        hou.push_back(tt);
    }
    
