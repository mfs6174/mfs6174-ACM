/*
ID: mfs6174
PROG: poj 3461 kmp
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
const int maxlongint=2147483647;

int p[MAXM];
int i,j,k,t,n,m,cc,zz,zu;
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

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    s[0]='.';
    ss[0]='.';
    scanf("%s",ss+1);
    kmpinit(ss);
    scanf("%s",s+1);
    cc=kmp(s,ss);
    cout<<cc<<endl;
  }
  return 0;
}
