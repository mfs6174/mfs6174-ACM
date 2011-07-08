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
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,n,m,t,l;
string ss,s,biao,xiao;
vector<string> zi;
bool ff[200];

string bianxiao(string &s)
{
  int i;
  for (i=0;i<s.size();i++)
    if (s[i]>='A'&&s[i]<='Z')
      s[i]+=32;
  return s;
}

void mark(int x,int y)
{
  int i;
  for (i=x;i<x+y;i++)
    ff[i]=true;
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    cin>>s;
    bianxiao(s);
    zi.push_back(s);
  }
  cin>>s>>biao;
  l=s.size();
  xiao=bianxiao(s);
  for (i=0;i<zi.size();i++)
    for (j=0;j<l;j++)
      if (zi[i]==xiao.substr(j,zi[i].size()))
        mark(j,zi[i].size());
  
    
  
