/*
ID: mfs.dev2
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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

class MysteriousRestaurant
{
public:
  int maxDays(vector<string> prices,int budget)
  {
    int q=budget;
    int i,j,mm,n=prices.size(),m=prices[1].size();
    int shu[10];
    int d=1;
    int qian[300];
    int maxlongint=2147482647;
    for (char i='0';i<='9';i++)
      qian[i]=i-48;
    for (char i='A';i<='Z';i++)
      qian[i]=i-55;
    for (char i='a';i<='z';i++)
      qian[i]=i-61;
    for (i=1;i<=7;i++)
    {
      mm=maxlongint;
      for (j=0;j<m;j++)
        if (qian[prices[i-1][j]]<mm)
        {
          mm=qian[prices[i-1][j]];
          shu[i]=mm; 
        }
      q-=mm;
      if (q<0)
        break;
      if (i>=n)
        break;
    }
    if (q<0||n<=7)
      return (i-1<n)?(i-1):n;
    d=8;
    while (d<=n)
    {
      int t=(n+6)/7,ttt,z=n%7;
      if (z==0)
        z=7;
      for (j=0;j<m;j++)
      {
        int tt=0;
        for (i=1;i<=t;i++)
          tt+=qian[prices[d-(t-1)*7-1][j]];
        if (tt<mm)
        {
          mm=tt;
          ttt=j;
        }
      }
      q=q-mm+shu[z];
      shu[z]=mm;
      if (q<0)
        return d-1;
      if (d>=n)
        return n;
      d++;
    }
  }
};

int main()
{
  vector<string> s;
  string ss;
  MysteriousRestaurant lei;
  while (inf>>ss)
    s.push_back(ss);
  cout<<lei.maxDays(s,20)<<endl;
}

    
      
          
