/*
ID: mfs6174
PROG: ti
LANG: C++
*/

#include "fnmatch.h"
#include<stdio.h>
//using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

char ss[110000],s[110000];
int t;

int main()
{
  //freopen("ti.in","r",stdin);
  while (scanf("%s%s",s,ss)!=EOF)
  {
    t=fnmatch(ss,s,0);
    if (!t)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}

