/*
ID: mfs6174
PROG: CF 73 A
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

int i,j,k,n,m,t,tt;
map<string,int> tu;
int ss[10],sss[10];
string s;
bool ff[10];

void dfs(int x)
{
  if (ff[0])
    return;
  if (x>3)
  {
    if (ss[1]>ss[2])
    t=ss[2]+12-ss[1];
  else
    t=ss[2]-ss[1];
  if (ss[2]>ss[3])
    tt=ss[3]+12-ss[2];
  else
    tt=ss[3]-ss[2];
  if (t==4&&tt==3)
  {
    cout<<"major"<<endl;
    ff[0]=true;
  }
  else if (t==3&&tt==4)
  {
    cout<<"minor"<<endl;
    ff[0]=true;
  }
  }
  int i;
  for (i=1;i<=3;i++)
  {
    if (!ff[i])
    {
      ff[i]=true;
      ss[x]=sss[i];
      dfs(x+1);
      ff[i]=false;
    }
  }
}

  
int main()
{
  tu["C"]=0;
  tu["C#"]=1;
  tu["D"]=2;
  tu["D#"]=3;
  tu["E"]=4;
  tu["F"]=5;
  tu["F#"]=6;
  tu["G"]=7;
  tu["G#"]=8;
  tu["A"]=9;
  tu["B"]=10;
  tu["H"]=11;
  for (i=1;i<=3;i++)
  {
    cin>>s;
    sss[i]=tu[s];
  }
  dfs(1);
  if (!ff[0])
    cout<<"strange"<<endl;
  return 0;
}


