
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

struct B
{
  int n;
  vector<int> l,h;
};
  
int di[100100];
int i,j,k,t,n,m,s,a,b;
long long mm,sa,ab,sb;
B bian[100100];


void spfa(int x)
{
  bool f[100100];
  int dui[100100];
  int i,s,e,d;
  memset(f,0,sizeof(f));
  memset(dui,0,sizeof(dui));
  for (i=1;i<=n;i++)
    di[i]=maxlongint;
  di[x]=0;
  s=0;e=0;
  s++;dui[s]=x;f[x]=true;
  while (s!=e)
  {
    e=(e+1)%n;
    d=dui[e];
    f[d]=false;
    for (i=1;i<=bian[d].n;i++)
      if (di[d]+bian[d].l[i]<di[bian[d].h[i]])
      {
        di[bian[d].h[i]]=di[d]+bian[d].l[i];
        // p[bian[d].h[i]]=d;
        if (!f[bian[d].h[i]])
        {
          if ((di[bian[d].h[i]]<=di[dui[(e+1)%n]]))
          {
            dui[e]=bian[d].h[i];
            e=(e-1)%n;
          }
          else
          {
            //dui[s]=bian[d].h[i];
            s=(s+1)%n;
            dui[s]=bian[d].h[i];
          }
          f[bian[d].h[i]]=true;
        }
      }
  }
}

int main()
{
  //freopen("ti.in","r",stdin);
  scanf("%d%d%d%d%d",&m,&n,&s,&a,&b);
  for (i=1;i<=n;i++)
  {
    bian[i].l.push_back(0);
    bian[i].h.push_back(0);
  }
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&j,&k,&t);
    //cin>>j>>k>>t;
    bian[j].n++;
    bian[k].n++;
    bian[j].h.push_back(k);
    bian[j].l.push_back(t);
    bian[k].h.push_back(j);
    bian[k].l.push_back(t);
  }
  spfa(s);
  sa=di[a];
  sb=di[b];
  spfa(a);
  ab=di[b];
  mm=sa+ab;
  mm=min(mm,sb+ab);
  mm=min(mm,sa*2+sb);
  mm=min(mm,sb*2+sa);
  cout<<mm<<endl;
}

  
  

