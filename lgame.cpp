/*
ID: mfs.dev2
PROG: lgame
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
ifstream inf("lgame.in");
ofstream ouf("lgame.out");
ifstream infd("lgame.dict");
const int maxlongint=2147483647;

int i,j,k,t,m,n,mm;
string zu[40000],rr[40000],ss;
int f[27],ff[27],fen[40001],quan[27]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
bool fl;

int main()
{
  inf>>ss;
  for (i=0;i<ss.size();i++)
    ff[ss[i]-97]++;
  infd>>ss;
  while (ss!=".")
  {
    memset(f,0,sizeof(f));
    fl=true;
    for (i=0;i<ss.size();i++)
    {
      f[ss[i]-97]++;
      if (f[ss[i]-97]>ff[ss[i]-97])
      {
        fl=false;
        break;
      }
    }
    if (fl)
    {
      t=0;
      for (i=0;i<ss.size();i++)
        t+=quan[ss[i]-97];
      if (t>mm)
      {
        m=1;
        mm=t;
        rr[m]=ss+' ';
      }
      else
      {
        if (t==mm)
        {
            m++;
            rr[m]=ss+' ';
        }
      }
      if (ss.size()<5)
      {
        n++;
        zu[n]=ss;
        fen[n]=t;
      }
    }
    infd>>ss;
  }
    
  for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
    {
      if ((zu[i].size()==4)&&(zu[j].size()==4))
        continue;
      if (fen[i]+fen[j]<mm)
        continue;
      fl=false;
      memset(f,0,sizeof(f));
      for (k=0;k<zu[i].size();k++)
      {
        f[zu[i][k]-97]++;
        if (f[zu[i][k]-97]>ff[zu[i][k]-97])
        {
          fl=true;
          break;
        }
      }
      for (k=0;k<zu[j].size();k++)
      {
        f[zu[j][k]-97]++;
        if (f[zu[j][k]-97]>ff[zu[j][k]-97])
        {
          fl=true;
          break;
        }
      }
      if (fl)
        continue;
      if (fen[i]+fen[j]>mm)
      {
        m=1;
        mm=fen[i]+fen[j];
        rr[m]=zu[i]+' '+zu[j];
      }
      else
      {
        m++;
        rr[m]=zu[i]+' '+zu[j];
      }
    }
  sort(rr,&(rr[m])+1);
  ouf<<mm<<endl;
  for (i=1;i<=m;i++)
  {
    if (*(rr[i].rbegin())==' ')
      rr[i].erase(rr[i].end()-1);
    ouf<<rr[i]<<endl;
  }
}

        
