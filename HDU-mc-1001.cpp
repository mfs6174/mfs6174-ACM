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
#define US unsigned
#define MAX 1200000

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483645;

int i,j,k,t,n,m,la,ld,lh,sm;
int f[MAX];
int gong[30],fang[30],xie[30],e[30];
int zongj[MAX];
string ss;
bool ff[MAX];
US cao[30],st;
int exp[100];


inline int suanji(int e)
{
  int i;
  for (i=0;i<=5;i++)
    if (e>=exp[i]&&e<exp[i+1])
      return i;
}

inline int suan(US x,int p,int h)
{
  int go,fa,fo,fi,t1,t2,ji,hp;
  US t=x;
  if (!zongj[x])
    for (int i=1;i<=n;i++)
    {
      zongj[x]+=((t&1))?0:e[i];
      t=t>>1;
    }
  ji=zongj[x]/100;
  go=ji*la+gong[0];
  fa=ji*ld+fang[0];
  hp=h+lh*ji+xie[0];
  if (hp<=0||h==-maxlongint)
    return -maxlongint;
  fo=max(1,go-fang[p]);
  fi=max(gong[p]-fa,1);
  t1=hp/fi;t2=(xie[p]+fo-1)/fo;
  if (hp-(t2-1)*fi<=0)
    return -maxlongint;
  else
    return h-(t2-1)*fi;
}

void dfs(US x)
{
  if (ff[x])
    return;
  ff[x]=true;
  if (x==st)
  {
    f[x]=0;
    return;
  }
  US t=x;
  int i;
  f[x]=-maxlongint;
  for (i=1;i<=n;i++)
    if ((~x)&cao[i])
    {
      t=x|cao[i];
      dfs(t);
      f[x]=max(f[x],suan(t,i,f[t]));
    }
}

int main()
{
  for (i=1;i<=6;i++)
    exp[i]=exp[i-1]+100*i;
  while (cin>>gong[0]>>fang[0]>>xie[0]>>la>>ld>>lh)
  {
    cin>>n;
    sm=0;
    for (i=1;i<=n;i++)
    {
      cin>>ss>>gong[i]>>fang[i]>>xie[i]>>e[i];
      sm+=e[i];
    }
    memset(ff,0,sizeof(ff));
    memset(f,0,sizeof(f));
    memset(zongj,0,sizeof(zongj));
    st=0;
    for (i=1;i<=n;i++)
    {
      cao[i]=1<<(i-1);
      st=st|cao[i];
    }
    dfs((unsigned)0);
    if ((f[0]==-maxlongint)||(f[0]+sm/100*lh+xie[0]<=0))
      cout<<"Poor LvBu,his period was gone."<<endl;
    else
      cout<<(f[0]+sm/100*lh+xie[0])<<endl;
  }
  return 0;
}
    
