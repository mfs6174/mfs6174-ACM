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

int n,m,i,j,k,t,cc,rc,l=-1;
int yong[30],wei[30][5],lian[30][30],tu[30][30],rr[30][30],ru[30],ji[30];
char c;
bool fl[30],chu[30],ff,hash[30];
string r;


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
  int i;
  if (x<1)
  {
    cout<<r.substr(0,cc)<<endl;
    return;
  }
  for (i=1;i<=rr[x][0];i++)
  {
    if( hash[rr[x][i]+64])
      continue;
    l++;
    hash[rr[x][i]+64]=true;
    ji[x]--;
    r[l]=rr[x][i]+64;
    shuchu(x);
    l--;
    ji[x]++;
    hash[rr[x][i]+64]=false;
  }
  if (!ji[x])
    shuchu(x-1);
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
  rc=26;
  for (k=1;k<=26;k++)
  {
    ff=true;
    for (i=1;i<=26;i++)
    {
      if ((!fl[i])||chu[i])
        continue;
      if (!ru[i])
      {
        rr[k][0]++;
        rr[k][rr[k][0]]=i;
        chu[i]=true;
        ff=false;
      }
    }
    if (ff)
    {
      rc=k-1;
      break;
    }
    for (i=1;i<=rr[k][0];i++)
    {
      t=rr[k][i];
      for (j=1;j<=lian[t][0];j++)
        ru[lian[t][j]]--;
    }
  }
  for (i=1;i<=cc;i++)
    r=r+"A";
  for (i=1;i<=rr[rc][0];i++)
  {
    rr[rc-1][0]++;
    rr[rc-1][rr[rc-1][0]]=rr[rc][i];
  }
  rc--;
  for (i=1;i<=rc;i++)
    ji[i]=rr[i][0];
  sort(&(rr[rc][1]),&(rr[rc][rr[rc][0]])+1);
  memset(hash,0,sizeof(hash));
  shuchu(rc);
}

