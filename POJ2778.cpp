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

#define NODE 300 //最大可能出现的节点数
#define CH 5 //分支数

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


struct ZHEN
{
  int z[300][300];
};

int i,j,k,n,t,m;
int cc,c;//cc是统计使用了多少个节点
int zh[NODE][CH];//自动机机体
int shu[NODE];//相应节点的数据域
int fail[NODE];//失败指针，貌似是指向［彻底］失败的位置
int sn[300];//每个字符的代号，无效字符是0
int q[NODE];//队列

char ss[15][15],ke[5]="ATCG";
ZHEN mm;
bool ff[300];

void init() //每次都要先执行
{
  fail[0]=0;
  memset(zh[0],0,sizeof(zh[0]));
  cc=0;
}

void ins(const char *s, int d) //建立trie
{
  int p=0;
  for(;*s;s++)
  {
    int t=sn[*s];
    if(!zh[p][t])
    {
      cc++;
      memset(zh[cc],0,sizeof(zh[cc]));
      shu[cc] = 0;
      zh[p][t] =cc;
    }
    p =zh[p][t];
  }
  shu[p]=d;
}

void acinit()//自动机初始化，执行完以后zh里就是goto或fail的位置
{
  int *s=q,*e=q,i;
  for (i=0;i<=CH;i++) //先把紧邻root的fail设成0
    if (zh[0][i])
    {
      fail[zh[0][i]]=0;
      *e++=zh[0][i];
    }
  while (s!=e)
  {
    int p=*s++;
    for (i=0;i<=CH;i++)
    {
      if (zh[p][i])//如果goto存在
      {
        int v=zh[p][i];
        *e++=v;
        fail[v]=zh[fail[p]][i];//fail直接设成彻底fail后应该转移的位置（最长后缀位置）
      }
      else
        zh[p][i]=zh[fail[p]][i];//goto不存在，转移到fail位置
    }
  }
}

void make(int p)
{
  if (ff[p])
    return;
  ff[p]=true;
  char *s=ke;
  int tt;
  for (;*s;s++)
  {
    tt=zh[p][sn[*s]];
    bool fl=false;
    int t=tt;
    while (t)
    {
      if (fl)
        break;
      if (shu[t])
        fl=true;
      t=fail[t];
    }
    if (!fl)
    {
      mm.z[p][tt]++;
      make(tt);
    }
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  sn['A']=1;sn['T']=2;sn['C']=3;sn['G']=4;
  scanf("%d%d",&n,&m);
  init();
  for (i=1;i<=n;i++)
  {
    scanf("%s",ss[i]);
    ins(ss[i],i);
  }
  acinit();
  make(0);
  return 0;
}
