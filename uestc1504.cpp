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

long long i,j,k,n,m,t,p,zz,zu,a,mm1,mm2;
long long f[30][12][2][2],ff[30][12],g[30][12],shu[30];
string s,ss;

string str(long long x)
{
    ostringstream t;
    t<<x;
    return t.str();
}

long long mfs(string &s)
{
  long long m=s.size(),mm=0,i,j,o,d;
  memset(f,0,sizeof(f));
  for (i=1;i<s[0]-48;i++)
    f[1][i][0][1]=1;
  f[1][s[0]-48][0][0]=1;
  for (i=2;i<=m;i++)
    for (j=0;j<=9;j++)
    {
      int t;
      if (i>=3)
        t=1;
      else
        t=0;
      for (d=0;d<=t;d++)
      {
        if (!d)
        {
          if (j<s[i-1]-48)
          {
            for (o=0;o<j;o++)
              f[i][j][d][1]+=f[i-1][o][d][0]+f[i-1][o][d][1];
          }
          else
            for (o=0;o<j;o++)
              f[i][j][d][1]+=f[i-1][o][d][1];
          if (j==s[i-1]-48)
            if (s[i-1]>s[i-2])
              f[i][j][d][0]+=f[i-1][s[i-2]-48][d][0];
          
        }
        else
        {
          if (j<s[i-1]-48)
              for (o=j+1;o<=9;o++)
                f[i][j][d][1]+=f[i-1][o][1][0]+f[i-1][o][0][0]+f[i-1][o][d][1]+f[i-1][o][0][1];
          else
            for (o=j+1;o<=9;o++)
              f[i][j][d][1]+=(f[i-1][o][d][1]+f[i-1][o][0][1]);
          if (j==s[i-1]-48)
            if (s[i-1]<s[i-2])
              f[i][j][d][0]+=(f[i-1][s[i-2]-48][d][0]+f[i-1][s[i-2]-48][0][0]);              
        }
      }
    }
  for (i=0;i<=9;i++)
    mm+=f[m][i][1][0]+f[m][i][1][1];
  return mm;
}
  
  
int main()
{
  for (i=1;i<=9;i++)
  {
    ff[1][i]=1;
    g[1][i]=1;
  }
  g[1][0]=1;
  for (i=2;i<=9;i++)
      for (j=i;j<=9;j++)
        for (k=1;k<j;k++)
          ff[i][j]+=ff[i-1][k];
    for (i=2;i<=10;i++)
      for (j=i-1;j<=9;j++)
        for (k=0;k<j;k++)
          g[i][j]+=g[i-1][k];
    for (i=3;i<=20;i++)
      for (j=2;j<i;j++)
        for (k=0;k<=9;k++)//k=1是漏情况的
          shu[i]+=(ff[j][k]*g[i+1-j][k]);
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>a>>ss;
    s=str(a-1);
    mm1=mfs(s);
    mm2=mfs(ss);
    for (i=1;i<s.size();i++)
      mm1+=shu[i];
    for (i=1;i<ss.size();i++)
      mm2+=shu[i];
     cout<<"Case #"<<zz<<": "<<mm2-mm1<<endl;
  }
  return 0;
}

    
