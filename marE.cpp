

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

const int maxn=205;

struct jiedian
{
  int n,dao[maxn];
};
		
int n,m,zuo[maxn],i,j,duiz[maxn],duiy[maxn],nn,t,rr=0;
jiedian dian[maxn];
bool yong[maxn];

bool xiong(int x)
{
  int i,tt;
  for (i=1;i<=dian[x].n;i++)
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(duiy[tt]))
      {
        duiz[x]=tt;
        duiy[tt]=x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  cin>>m>>n;
  int t,tt;
  cin>>t>>tt;
  while (t!=-1)
  {
    dian[t].n++;
    dian[t].dao[dian[t].n]=tt;
    cin>>t>>tt;
  }
  for (i=1;i<=m;i++)
    zuo[i]=i;
  for (i=1;i<=m;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t))
          rr++;
    }
  }
  cout<<rr<<endl;
}


