#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

ifstream inf("H.in");

class SHU
{
public:
  int g,n;
  bool operator <(const SHU &x) const
  {
    if (g!=x.g)
      return x.g<g;
    return x.n<n;
  }
};

int i,j,k,t,n,m,zz,zu,kk,w,q,c,mm,tttt,ccc;
int shu[10100],shang[10000],dang[10000],qiu[250];
priority_queue<SHU> dui;
SHU tt,ttt;

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>qiu[zz];
    mm=max(mm,qiu[zz]);
  }
  while (!dui.empty())
  {
    dui.pop();
  }
  tt.g=1;tt.n=1;
  dui.push(tt);
  tt.g=2;tt.n=2;
  dui.push(tt);
  tt.g=2;tt.n=3;
  dui.push(tt);
  tt.g=1;tt.n=4;
  dui.push(tt);
  tt.g=1;tt.n=5;
  dui.push(tt);
  shu[1]=1;shu[2]=2;shu[3]=3;shu[4]=4;shu[5]=5;shu[6]=2;shu[7]=3;
  shang[1]=2;shang[2]=3;shang[3]=4;shang[4]=5;shang[5]=2;shang[6]=3;
  kk=2;
  k=3;
  c=7;
  m=6;
  while (1)
  {
    while (1)
    {
      SHU a[6];
      int tn=0;
      tt=dui.top();
      tn++;
      a[tn]=tt;
      dui.pop();
      while ((tt.n==shang[m])||(tt.n==shang[1]))
      {
        tt=dui.top();
        tn++;
        a[tn]=tt;
        dui.pop();
      }
      dang[1]=tt.n;
      tt.g++;
      dui.push(tt);
      c++;
      shu[c]=tt.n;
      for (i=1;i<tn;i++)
        dui.push(a[i]);
      if (c>=mm)
        break;
      if (k==3)
      {
        w=0;
        q=1;
        ccc=0;
      }
      else
      {
        w=1;
        q=1;
        ccc=1;
      }
      tttt=(m+6)/6-1;
      for (i=2;i<=m+6;i++)
      {
        tn=0;
        tt=dui.top();
        tn++;
        a[tn]=tt;
        dui.pop();   
        if (w)
        {
          while ((tt.n==shang[q])||(tt.n==shang[q+1])||(tt.n==dang[i-1]))
          {
            tt=dui.top();
            tn++;
            a[tn]=tt;
            dui.pop();
          }
          ccc++;
        }
        else
        {
          while ((tt.n==shang[q])||(tt.n==dang[i-1]))
          {
            tt=dui.top();
            tn++;
            a[tn]=tt;
            dui.pop();
          }
          w=1-w;
        }
        dang[i]=tt.n;
        tt.g++;
        dui.push(tt);
        c++;
        shu[c]=tt.n;
        for (int i=1;i<tn;i++)
          dui.push(a[i]);
        if (c>=mm)
          break;
        if (ccc)
        {
          q++;
          if (q>=m)
          {
            break;
          }
        }
        if (ccc>=tttt)
        {
          w=1-w;
          ccc=0;
        }
        
      }
      m+=6;
      memcpy(dang,shang,sizeof(dang));
      kk=k;
      k++;
      break;
      if (c>=mm)
        break;
    }
    if (c>=mm)
      break;
  }
  
  
  
  for (zz=1;zz<=zu;zz++)
  {
    cout<<shu[qiu[zz]]<<endl;
  }
  //system("pause");
}
                         
