/*
ID: mfs6174
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
#define LL long long
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

LL i,j,k,t,n,m,zz,zu,shua,l,o,p,aa;
LL f[25][25][25][11];
string a,b;

LL dfs(char s[],int w,int x,int y,int p)
{
  int i;
  for (i=
  if (p==4)
    dfs(w-1,x-1,y,
}

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>a>>b>>n>>m;
    memset(f,0,sizeof(f));
    for (i=0;i<=9;i++)
    {
      if (i==4)
        f[1][1][0][4]=1;
      else
        if (i==7)
          f[1][0][1][7]=1;
        else
          f[1][0][0][i]=1;
    }
    l=strlen(a);
    aa=0;
    for (i=0;i<a[0]-48;i++)
      aa+=dfs(a,l,n,m,i);
    aa+=dfs(
