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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int p,y;
};

deque<D> qian,hou;
int i,j,k,n,m,t,a,zz,zu,y,mm;
int s[1010],f[1010][1010];
D tt,ttt;

inline int fang(int x)
{
  return x*x;
}

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n>>k>>a;
    for (i=1;i<=n;i++)
      cin>>s[i];
    qian.clear();hou.clear();
    memset(f,-1,sizeof(f));
    t=max(1000,s[1]+k);
    for (i=min(0,s[1]-k);i<=t;i++)
    {
      f[1][i]=fang(i-s[1]);
     
    }
    for (i=1;i<n;i++)
    {
      qian.clear();hou.clear();
      for (j=0;j<=1000;j++)
      {
        tt.y=f[i][j]-a*j;
        tt.p=j;
        while ((!qian.empty())&&((qian.back()).y>=tt.y))
          qian.pop_back();
        qian.push_back(tt);
        while (qian.front().p<j-k) qian.pop_front();
        f[i+1][j]=qian.front().y+a*j;
      }
      for (j=1000;j>=0;j--)
      {
        tt.y=f[i][j]+a*j;
        tt.p=j;
        while ((!hou.empty())&&((hou.back()).y>=tt.y))
          hou.pop_back();
        hou.push_back(tt);
         while (hou.front().p>j+k) hou.pop_front();
         f[i+1][j]=min(f[i+1][j],hou.front().y-a*j);
         f[i+1][j]+=fang(s[i+1]-j);
      }
    }
    mm=maxlongint;
    for (i=0;i<=1000;i++)
      mm=min(mm,f[n][i]);
    cout<<mm<<endl;
  }
  return 0;
}

