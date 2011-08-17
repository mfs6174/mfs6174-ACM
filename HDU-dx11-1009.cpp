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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const int mod=1003001;
char s[110100];
int dp[220200], len;
bool hash[mod+10];
int i,j,k,t,n,m,zz,zu,cc,ll,rr;
char tc;
bool fl[300];

unsigned bkdrhash(char x[])
{
  unsigned int seed=131,hash=0,i,l=strlen(x);
  for (i=0;i<l;i++)
    hash=(hash*seed+x[i])&0xffffffff;
  return (hash&0x7FFFFFFF)%mod;
}

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
    ret = r - l - 1;//这里就是找到的回文串的左端之前和右端
    if (ret>1)
    {
      ll=l;rr=r;
      while (rr-ll-1>1)
      {
        tc=s[rr];s[rr]=0;
        t=bkdrhash(s+ll+1);
        if (!hash[t])
        {
          cc++;
          hash[t]=true;
        }
        else
        {
          s[rr]=tc;
          break;
        }
        s[rr]=tc;
        ll++;rr--;
      }
    }
    if(r > dp[max]) max = i;
    if((r >= len)) break;
  }
  return ret;
}



int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%s",s);
    memset(hash,0,sizeof(hash));
    cc=0;memset(fl,0,sizeof(fl));
    len=strlen(s);
    for (i=0;i<len;i++)
      if (!fl[s[i]])
      {
        fl[s[i]]=true;
        cc++;
      }
    solve();
    printf("Case #%d: %d\n",zz,cc);
  }
  return 0;
}
