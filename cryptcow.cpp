/*
ID: mfs.dev2
PROG: cryptcow
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
ifstream inf("cryptcow.in");
ofstream ouf("cryptcow.out");
const int prime=19991;

string s,ss,q="Begin the Escape execution at the Break of Dawn";
int i,j,k,t,l,mm,c,o,w,fl;
bool hashz[prime];
map<string,bool> zi;
int cc[10],ww[10],oo[10];

void chushi(const string &x)
{
  int i,j,l;
  l=x.size();
  for (i=0;i<l;i++)
    for (j=2;j<=l-i;j++)
      zi[x.substr(i,j)]=true;
}
  
bool hashing(unsigned x,const string &s)
{
  int t=x%prime;
  // if (!hashz[t].size())
  // {
  //   hashz[t].push_back(s);
  //   return false;
  // }
  // for (i=0;i<hashz[t].size();i++)
  //   if (s==hashz[t][i])
  //     return true;
  // hashz[t].push_back(s);
  // return false;
  if (!hashz[t])
  {
    hashz[t]=true;
    return false;
  }
  else
    return true;
}

void dfs(string s,int x)
{
  if (mm) return;
  int cc[10]={0},oo[10]={0},ww[10]={0};
  int i,j,k,t=-1;
  unsigned seed=131,l=s.size(),ha=0;
  for (i=0;i<l;i++)
  {
    ha=(ha*seed+s[i])&0xffffffff;
    if (s[i]=='C')
    {
      cc[0]++;
      cc[cc[0]]=i;
      if (i-t-1>1)
        if (!zi.count(s.substr(t+1,i-t-1)))
          return;
      t=i;
      continue;
    }
    if (s[i]=='O')
    {
      oo[0]++;
      oo[oo[0]]=i;
      if (i-t-1>1)
        if (!zi.count(s.substr(t+1,i-t-1)))
          return;
      t=i;
      continue;
    }
    if (s[i]=='W')
    {
      ww[0]++;
      ww[ww[0]]=i;
      if (i-t-1>1)
        if (!zi.count(s.substr(t+1,i-t-1)))
          return;
      t=i;
    }
  }
  ha=ha&0x7FFFFFFF;
  if (hashing(ha,s))
      return;
  if (t==-1)
  {
    if (s==q)
    {
      mm=x;
      fl=1;
    }
    return;
  }
  if ((cc[1]>oo[1])||(ww[ww[0]]<oo[oo[0]]))
    return;
  if ((s.substr(0,cc[1])!=q.substr(0,cc[1]))||(s.substr(ww[ww[0]]+1)!=q.substr(q.size()-s.size()+1+ww[ww[0]])))
    return;
  for (i=1;i<=oo[0];i++)
    for (j=1;j<=cc[0];j++)
    {
      if (cc[j]>oo[i])
        break;
      for (k=ww[0];k>=1;k--)
      {
        if (ww[k]<oo[i])
          break;
        dfs(s.substr(0,cc[j])+s.substr(oo[i]+1,ww[k]-oo[i]-1)+s.substr(cc[j]+1,oo[i]-cc[j]-1)+s.substr(ww[k]+1),x+1);
      }
    }
}
int main()
{
  getline(inf,s);
  chushi(q);
   for (i=0;i<s.size();i++)
  {
    if (s[i]=='C')
    {
      cc[0]++;
      cc[cc[0]]=i;
      continue;
    }
    if (s[i]=='O')
    {
      oo[0]++;
      oo[oo[0]]=i;
      continue;
    }
    if (s[i]=='W')
    {
      ww[0]++;
      ww[ww[0]]=i;
    }
  }
  c=cc[0];o=oo[0];w=ww[0];      
  if ((c!=o)||(o!=w)||(cc[1]>oo[1])||(ww[ww[0]]<oo[oo[0]])||(s.size()-c-w-o!=q.size()))
  {
    ouf<<0<<' '<<0<<endl;
    return 0;
  }
  dfs(s,0);
  ouf<<(fl)<<' '<<mm<<endl;
  return 0;
}
