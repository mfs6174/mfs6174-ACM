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
#include<set>
#include<vector>

using namespace std;
// ifstream inf("ti.in");
// ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int d,p;
  bool operator<(const D &x) const
  {
    return p<x.p;
  }
};

int i,j,k,t,m,n,zz,zu;
int shu[200010],f[200010][2],mm;
set<D> s;
D tt;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    memset(f,0,sizeof(f));
    mm=0;
    shu[0]=0;
    s.clear();
    // cout<<s.size()<<endl;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
      mm=max(mm,shu[i]);
    }
    tt.p=0;
    tt.d=0;
    s.insert(tt);
    mm=1;
    for (i=1;i<=n;i++)
    {
      if (shu[i-1]<shu[i])
      {
        f[i][0]=f[i-1][0]+1;
        f[i][1]=f[i-1][1]+1;
      }
      else
      {
        f[i][0]=1;
        f[i][1]=1;
      }
      mm=max(mm,f[i][0]);
      tt.p=shu[i];
      tt.d=f[i][0];
      // cout<<s.size()<<endl;
      set<D>::iterator it;
      if (s.size()!=1)
      {
        it=s.lower_bound(tt);
        it--;
      }
      else
        it=s.begin();
      //if (((*it).p==tt.p)&&(it!=s.begin()))
      //  it--;
      f[i][1]=max(f[i][1],(*it).d+1);
      mm=max(mm,f[i][1]);
      if (s.size()!=1)
      {
        it=s.lower_bound(tt);
        it--;
      }
      else
        it=s.begin();
      //if (it==s.end())
      // it--; //非常重要！
      if ((*it).p==shu[i])
      {
        if ((*it).d<f[i][0])
        {
          s.erase(it);
          s.insert(tt);
        }
      }
      else
      {
        if (f[i][0]>(*it).d)
        {
          it=(s.insert(tt)).first;
          it++;
          for (;it!=s.end();)
          {
            if ((*it).d<f[i][0])
              s.erase(it++);
            else
              break;
          }
        }
      }
    }
    cout<<mm<<endl;
  }
  return 0;
}

      
