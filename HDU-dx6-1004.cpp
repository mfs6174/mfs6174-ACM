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

#define NODE 100 //最大可能出现的节点数
#define CH 8 //分支数

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long maxlongint=2147483647;
const long long mod=112233;

class ZHEN
{
public:
  long long z[20][20],dx,dy;
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
          r.z[i][j]=(r.z[i][j]+(z[i][k]*x.z[k][j]))%mod;
      }
    return r;
  }
  void E(long long x,long long y)
  {
    dx=x;dy=y;
    long long i;
    memset(z,0,sizeof(z));
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

char ss[15][15]={"","rr","oo","yy","gg","bb","vv","roygbv"},ke[10]="roygbv";
ZHEN mm,rr,rr1;
bool ff[300];
long long res;

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
      mm.z[p+1][tt+1]++;
      make(tt);
    }
  }
}

long long rrr[10],rrr1[10],re;

int main()
{
  freopen("ti.in","r",stdin);
  sn['r']=1;sn['o']=2;sn['y']=3;sn['g']=4;sn['b']=5;sn['v']=6;
  init();
  for (i=1;i<=7;i++)
    ins(ss[i],i);
  acinit();
  make(0);
  mm.dx=mm.dy=cc+1;
  while (scanf("%lld",&m)!=EOF)
  {
    n=m/2;
    rr=mm.power(n);
    memset(rrr,0,sizeof(rrr));
    for (i=1;i<=6;i++)
      rrr[i]=(rrr[i]+rr.z[1][2*i])%mod;
    for (i=2;i<=5;i++)
      rrr[i]=(rrr[i]+rr.z[1][i+12])%mod;
    if (n-5>=1)
    {
      rr1=mm.power(n-5);
      re=0;
      for (i=1;i<=6;i++)
        rrr1[i]=(rrr1[i]+rr1.z[1][2*i])%mod;
      for (i=2;i<=5;i++)
        rrr1[i]=(rrr1[i]+rr1.z[1][i+12])%mod;
      for (i=2;i<=6;i++)
        re=(re+rrr1[i])%mod;
    }
    res=0;
    if (m&1)
    {
      for (i=1;i<=6;i++)
        res=(res+rrr[i])%mod;
      res=(res*5)%mod;
      if (n-5>=1)
        res-=re;
    }
    else
      res=0;
    cout<<(res%mod+mod*2)%mod<<endl;
  }
  return 0;
}
