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

struct D
{
  int x,y,l,r,u,d;
};

D ss[200000];
multimap<int,int> heng,shu;
int i,j,k,t,n,m,tt,p,h,cc,d,l;
int xtou[110000],ytou[110000];
bool fh[110000],fs[110000];

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&m)!=EOF&&n)
  {
    memset(ss,0,sizeof(ss));
    memset(fh,0,sizeof(fh));
    memset(fs,0,sizeof(fs));
    heng.clear();shu.clear();
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&t,&tt);
      heng.insert(pair<int,int>(t,i));shu.insert(pair<int,int>(tt,i));
    }
    map<int,int>::iterator it;
    i=0;l=0;p=0;
    for (it=heng.begin();it!=heng.end();it++)
    {
      t=(*it).second;
      if ((*it).first!=l)
      {
        i++;
        l=(*it).first;
        xtou[i]=t;
        p=0;
      }
      ss[t].d=p;ss[p].u=t;
      p=t;
      ss[t].x=i;
    }
    i=0;l=0;p=0;
    for (it=shu.begin();it!=shu.end();it++)
    {
      t=(*it).second;
      if ((*it).first!=l)
      {
        i++;
        l=(*it).first;
        ytou[i]=t;
        p=0;
      }
      ss[t].l=p;ss[p].r=t;
      p=t;
      ss[t].y=i;
    }
    for (k=1;k<=m;k++)
    {
      scanf("%d%d",&t,&tt);
      if (t==0)
      {
        it=heng.find(tt);
        if (it==heng.end())
        {
          cout<<0<<endl;
          continue;
        }
        h=(*it).second;h=ss[h].x;
        if (fh[h])
        {
          cout<<0<<endl;
          continue;
        }
        cc=0;
        fh[h]=true;
        d=xtou[h];
        while (d)
        {
          cc++;
          ss[ss[d].r].l=ss[d].l;
          ss[ss[d].l].r=ss[d].r;
          if (ss[d].l==0)
            ytou[ss[d].y]=ss[d].r;
          d=ss[d].u;
        }
        cout<<cc<<endl;
      }
      else
      {
        it=shu.find(tt);
        if (it==shu.end())
        {
          cout<<0<<endl;
          continue;
        }
        h=(*it).second;h=ss[h].y;
        if (fs[h])
        {
          cout<<0<<endl;
          continue;
        }
        cc=0;
        fs[h]=true;
        d=ytou[h];
        while (d)
        {
          cc++;
          ss[ss[d].u].d=ss[d].d;
          ss[ss[d].d].u=ss[d].u;
          if (ss[d].d==0)
            xtou[ss[d].x]=ss[d].u;
          d=ss[d].r;
        }
        cout<<cc<<endl;
      }
    }
    cout<<endl;
  }
  return 0;
}

    
