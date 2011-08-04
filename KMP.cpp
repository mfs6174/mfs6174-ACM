/*
ID: mfs6174
PROG: kmp
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
#define MAXN 1100000
#define MAXM 11000
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

int p[MAXM];
int i,j,k,t,n,m,cc;
char ss[MAXM],s[MAXN];

void kmpinit(char s[])
{
  int i,j=0,m=strlen(s);//j指向应当比较位置之前，也就是最长后缀的前缀的结束位置
  p[1]=0;//如果第2位就失败，那么只能讲第一位与其对齐比较，所以指针指0
  for (i=2;i<m;i++)
  {
    while (j>0&&s[j+1]!=s[i]) j=p[j];//当未完全失败，继续寻找更小的后缀来尝试是否可连接
    if (s[j+1]==s[i])//如果是因为可连接而停止的才加，必须判
      j++;
    p[i]=j;
  }
}

int kmp(char s[],char ss[])
{
  int j=0,n=strlen(s),m=strlen(ss),c=0;//c是匹配次数
  for (i=1;i<n;i++)
  {
    while (j>0&&s[i]!=ss[j+1]) j=p[j];
    if (s[i]==ss[j+1])
      j++;
    if (j>=m-1)//以上同理
    {
      //int t=i-m;
      c++;
      j=p[j];//使匹配继续进行
    }
  }
  return c;
}

inline bool bi(char a,char b)//以下是模式中带?（匹配任意一个字母）通配符的匹配
{
  if (b=='?')
    return true; //这里很重要，只有一个是?才认为是相等，具体是哪一个见下面
  else
    return a==b;
}

void kmpinit(char s[])
{
  int i,j=0,m=strlen(s);
  pp[1]=0;
  for (i=2;i<m;i++)
  {
    while (j>0&&(!bi(s[i],s[j+1]))) j=pp[j];
    if (bi(s[i],s[j+1]))//这里注意，只有前面是?才能next过去，否则abca...ab?a处会next到4，明显是错的，因为?处在主串中不一定匹配到c的
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
      c=i;//记录位置并break，也可以改成上面模板那种
      break;
    }
  }
  return c;
}

int main()
{
  s[0]='.';
  ss[0]='.';
  scanf("%s",ss+1); //注意这里和下面，把s[0]设为一个字符，读入ss+1,参数ss，使字符串从1开始
  kmpinit(ss);
  scanf("%s",s+1);
  cc=kmp(s,ss);
  cout<<cc<<endl;
}
