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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

char s[110100];
int dp[220200], len;

int solve()
{
  int ret = 1, max = 1;
  len = strlen(s);
  int l, r, m;
  dp[0] = 0;
  dp[1] = 1;
  for(int i = 2; i < 2 * len; ++i)
  {
    if(i / 2 >= dp[max])
    {
      r = i / 2;
      l = i - 1 - r;
    }
    else
    {
      m = max * 2 - i;
      if(dp[m] - m / 2 > dp[max] - i / 2)
      {
        r = dp[max];
        l = i - 1 - r;
      } else
      {
        l = max - 1 - dp[m];
        r = i - 1 - l;
      }
    }
    while(l >= 0 && r < len && s[l] == s[r]) --l, ++r;
    dp[i] = r;
    if(r - l - 1 > ret)
      ret = r - l - 1;//这里就是找到的回文串的左端之前和右端
    if(r > dp[max]) max = i;
    if((r >= len) || (2 * len - i <= ret)) break;
  }
  return ret;
}

int main()
{
  while(gets(s))
  {
    printf("%d\n", solve());
    gets(s);
  }
  return 0;
}
