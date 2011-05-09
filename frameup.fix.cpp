/*
ID: mfs.dev2
PROG: frameup
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
ifstream inf("frameup.in");
ofstream ouf("frameup.out");
const int maxlongint=2147483647;

int n,m,i,j,k,t,cc,rc;
int yong[30],wei[30][5],lian[30][30],tu[100][100],ru[30];
char c;
bool fl[30],chu[30],ff,hash[30];
string rr[10001],r;


int max(int x,int y)
{
  return (x>y)?x:y;
}
int min(int x,int y)
{
  return (x<y)?x:y;
}

void jian(int a,int b,int c,int d,int t)
{
  int i,j;
  for (i=a;i<=b;i++)
    for (j=c;j<=d;j++)
      if ((tu[i][j]!=t)&&(!hash[tu[i][j]]))
      {
        lian[tu[i][j]][0]++;
        lian[tu[i][j]][lian[tu[i][j]][0]]=t;
        ru[t]++;
        hash[tu[i][j]]=true;
      }
}

void shuchu(int x)
{
  int i,t,j;
  if (x>=cc)
  {
    rc++;
    rr[rc]=r.substr(0,cc);
    reverse(rr[rc].begin(),rr[rc].end());
    return;
  }
  for (i=1;i<=cc;i++)
  {
    t=yong[i];
    if( hash[t])
      continue;
    if (ru[t])
      continue;
    r[x]=t+64;
    hash[t]=true;
    for (j=1;j<=lian[t][0];j++)
      ru[lian[t][j]]--;
    shuchu(x+1);
    hash[t]=false;
    for (j=1;j<=lian[t][0];j++)
      ru[lian[t][j]]++;
  }
}  

int main()
{
  inf>>n>>m;
  for (i=1;i<28;i++)
  {
    wei[i][1]=maxlongint;
    wei[i][2]=maxlongint;
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      inf>>c;
      if ((c>=65) and (c<=90))
      {
        tu[i][j]=c-64;
        wei[tu[i][j]][1]=min(wei[tu[i][j]][1],i);
        wei[tu[i][j]][2]=min(wei[tu[i][j]][2],j);
        wei[tu[i][j]][3]=max(wei[tu[i][j]][3],i);
        wei[tu[i][j]][4]=max(wei[tu[i][j]][4],j);
        if (!fl[tu[i][j]])
        {
          fl[tu[i][j]]=true;
          cc++;
          yong[cc]=tu[i][j];
        }
      }
      else
        tu[i][j]=0;
    }
  for (i=1;i<=cc;i++)
  {
    t=yong[i];
    memset(hash,0,sizeof(hash));
    jian(wei[t][1],wei[t][3],wei[t][2],wei[t][2],t);
    jian(wei[t][1],wei[t][3],wei[t][4],wei[t][4],t);
    jian(wei[t][1],wei[t][1],wei[t][2],wei[t][4],t);
    jian(wei[t][3],wei[t][3],wei[t][2],wei[t][4],t);
  }
  memset(hash,0,sizeof(hash));
  for (i=1;i<=26;i++)
    r=r+"A";
  shuchu(0);
  sort(&(rr[1]),&(rr[rc+1]));
  for (i=1;i<=rc;i++)
    ouf<<rr[i]<<endl;
}

