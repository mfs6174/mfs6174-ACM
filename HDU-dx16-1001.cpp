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
#define CH 28 //分支数

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long maxlongint=2147483647;

class ZHEN
{
public:
  double z[300][300];
  long long dx,dy;
  ZHEN operator *(const ZHEN &x)
  {
    ZHEN r;
    r.dx=dx;r.dy=x.dy;
    long long i,j,k;
    for (i=1;i<=r.dx;i++)
      for (j=1;j<=r.dy;j++)
      {
        r.z[i][j]=0;
        for (k=1;k<=x.dx;k++)
          r.z[i][j]=(r.z[i][j]+(z[i][k]*x.z[k][j]));
      }
    return r;
  }
  void E(long long x,long long y)
  {
    dx=x;dy=y;
    long long i;
    for (i=1;i<=dx;i++)
      z[i][i]=1;
  }
  ZHEN power(long long e)
  {
    ZHEN tmp = (*this),rr;
    if (e==1) return *this;
    rr.E(dx,dy);
    while (e)
    {
      if (e&1)
        rr=rr*tmp;
      tmp=tmp*tmp;
      e=e>>1;
    }
    return rr;
  }
 
};


long long i,j,k,n,t,m;
long long cc,c;//cc是统计使用了多少个节点
long long zh[NODE][CH];//自动机机体
long long shu[NODE];//相应节点的数据域
long long fail[NODE];//失败指针，貌似是指向［彻底］失败的位置
long long sn[300];//每个字符的代号，无效字符是0
long long q[NODE];//队列

char ss[30][30],ke[30]="abcdefghijklmnopqrstuvwxyz";
bool ff[1000];
double gai[100];
double ex;

void init() //每次都要先执行
{
  fail[0]=0;
  memset(zh[0],0,sizeof(zh[0]));
  cc=0;
}

void ins(const char *s, long long d) //建立trie
{
  long long p=0;
  for(;*s;s++)
  {
    long long t=sn[*s];
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
  long long *s=q,*e=q,i;
  for (i=0;i<=CH;i++) //先把紧邻root的fail设成0
    if (zh[0][i])
    {
      fail[zh[0][i]]=0;
      *e++=zh[0][i];
    }
  while (s!=e)
  {
    long long p=*s++;
    for (i=0;i<=CH;i++)
    {
      if (zh[p][i])//如果goto存在
      {
        long long v=zh[p][i];
        *e++=v;
        fail[v]=zh[fail[p]][i];//fail直接设成彻底fail后应该转移的位置（最长后缀位置）
      }
      else
        zh[p][i]=zh[fail[p]][i];//goto不存在，转移到fail位置
    }
  }
}
ZHEN mm,rr;
void make(long long p)
{
  if (ff[p])
    return;
  ff[p]=true;
  char *s=ke;
  long long tt;
  for (;*s;s++)
  {
    tt=zh[p][sn[*s]];
    bool fl=false;
    long long t=tt;
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
      mm.z[p+1][tt+1]+=gai[sn[*s]];
      make(tt);
    }
  }
}
char tc;
double ppp=1;
int main()
{
  freopen("ti.in","r",stdin);
  for (tc='a';tc<='z';tc++)
    sn[tc]=tc-'a'+1;
  while (scanf("%lld",&n)!=EOF)
  { 
    init();
    for (i=1;i<=26;i++)
      scanf("%lf",&gai[i]);
    for (i=1;i<=n;i++)
    {
      scanf("%s",ss[i]);
      ins(ss[i],i);
    }
    acinit();
    memset(ff,0,sizeof(ff));
    make(0);
    mm.dx=mm.dy=cc+1;
    ex=0;
    for (m=1;m<=2000;m++)
    {
      rr=mm.power(m);
      double res=0,pr;
      for (i=1;i<=cc;i++)
        if (ff[i])
          res=(res+rr.z[1][i+1]);
      res=res+rr.z[1][1];
      pr=(1-res)*ppp*m;
      //if ((pr<1e-12)&&(pr!=0.0))
      // break;
      ex+=pr;
      ppp*=res;
    }
    ex+=1e-7;
    printf("%.6lf",ex);
  }
  return 0;
}
