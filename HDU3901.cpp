/*
ID: mfs6174
PROG: AC auto
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

#define MAXN 110000
#define MAXM 110000

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


int pp[MAXM];
int i,j,k,t,n,m,cc;
char ss[MAXM],s[MAXN],st[MAXN];

inline bool bi(char a,char b)
{
  if (b=='?')
    return true;
  else
    return a==b;
}

void kmpinit(char s[])
{
  int i,j=0,m=strlen(s);//j指向应当比较位置之前，也就是最长后缀的前缀的结束位置
  pp[1]=0;//如果第2位就失败，那么只能讲第一位与其对齐比较，所以指针指0
  for (i=2;i<m;i++)
  {
    while (j>0&&(!bi(s[i],s[j+1]))) j=pp[j];//当未完全失败，继续寻找更小的后缀来尝试是否可连接
    if (bi(s[i],s[j+1]))//如果是因为可连接而停止的才加，必须判
      j++;
    pp[i]=j;
  }
}

int kmp(int st,char s[],char ss[])
{
  int j=0,n=strlen(s),m=strlen(ss),c=0;
  for (i=st;i<n;i++)
  {
    while (j>0&&(!bi(s[i],ss[j+1])))
      j=pp[j];
    if (bi(s[i],ss[j+1]))
      j++;
    if (j>=m-1)//以上同理
    {
      c=i;
      break;
    }
  }
  return c;
}

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%s%s",s+1,ss)!=EOF)
  {
    s[0]='.';
    int c=0;st[0]='.';
    bool fl=true;
    char *p;
    for (p=ss;*p;p++)
      if ((*p)!='*')
      {
        c++;
        st[c]=*p;
      }
      else
        break;
    st[c+1]=0;
    if (c>0)
    {
      kmpinit(st);
      t=kmp(1,s,st);
      if (t!=strlen(st)-1)
      {
        cout<<"NO"<<endl;
        continue;
      }
    }
    st[0]='*';st[1]=0;i=1;
    for (;*p;p++)
      if (*p=='*')
      {
        st[i]=0;
        if (strlen(st)>1)
        {
          kmpinit(st);
          t=kmp(t+1,s,st);
          if (!t)
          {
            fl=false;
            break;
          }
        }
        i=1;
      }
      else
      {
        st[i]=*p;
        i++;
      }
    st[i]=0;
    if (!fl||t+strlen(st)>strlen(s))
    {
      cout<<"NO"<<endl;
      continue;
    }
    if (i!=1)
    {
      st[i]=0;
      int l=strlen(s)-1,ll=strlen(st)-1;
      for (i=0;i<ll;i++)
        if (!bi(s[l-i],st[ll-i]))
        {
          cout<<"NO"<<endl;
          fl=false;
          break;
        }
    }
    if (fl)
      cout<<"YES"<<endl;
  }
  return 0;
}
