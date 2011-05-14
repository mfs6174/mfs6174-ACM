/*
ID: mfs6174
PROG: uestc1488 WFS Binhash
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

unsigned dui[80000],cao[30];
int i,j,k,t,n,m,mm,s,e;
int hash[80000];
unsigned tt;
char tc;

void init(int x,int y)
{
  int h=(i-1)*4+j;
  unsigned t;
  if (x!=1)
  {
    cao[h]=1;
    cao[h]=cao[h]<<(16-(h-4));
  }
  if (y!=1)
  {
    t=1;
    cao[h]=cao[h]|(t<<(16-(h-1)));
  }
  t=1;
  cao[h]=cao[h]|(t<<(16-h));
  if (y!=4)
  {
    t=1;
    cao[h]=cao[h]|(t<<(16-(h+1)));
  }
  if (x!=4)
  {
    t=1;
    cao[h]=cao[h]|(t<<(16-(h+4)));
  }
}

void bfs(int x)
{
  int i;
  unsigned t,tt;
  e++;
  dui[e]=x;
  hash[x]=0;
  while (s!=e)
  {
    s=(s+1)%65536;
    t=dui[s];
    if ((!t)||(t==65535))
    {
      mm=hash[t];
      return;
    }
    for (i=1;i<=16;i++)
    {
      tt=t^cao[i];
      if (hash[tt]<0)
      {
        hash[tt]=hash[t]+1;
        e=(e+1)%65536;
        dui[e]=tt;
      }
    }
  }
}

int main()
{
  for (i=0;i<=66000;i++)
    hash[i]=-1;
  for (i=1;i<=4;i++)
    for (j=1;j<=4;j++)
      init(i,j);
  tt=0;
  for (i=1;i<=16;i++)
  {
    cin>>tc;
    tt=tt<<1;
    if (tc=='w')
      tt=tt|1;
  }
  mm=-1;
  if (!tt)
    mm=0;
  bfs(tt);
  if (mm<0)
    cout<<"Impossible"<<endl;
  else
    cout<<mm<<endl;
}
  
