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

#define NODE 50 //最大可能出现的节点数
#define CH 5 //分支数

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long maxlongint=2147483647;
const long long mod=10007;

class ZHEN
{
public:
  long long z[NODE*4][NODE*4],dx,dy;
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
  void zero()
  {
    memset(z,0,sizeof(z));
  }
};


long long i,j,k,n,t,m;
long long cc,c;//cc是统计使用了多少个节点
long long zh[NODE][CH];//自动机机体
long long shu[NODE];//相应节点的数据域
long long fail[NODE];//失败指针，貌似是指向［彻底］失败的位置
long long sn[300];//每个字符的代号，无效字符是0
long long q[NODE];//队列

char ss[15][15],ke[5]="ATCG";
ZHEN mm,rr;
bool ff[NODE][2];
long long res;

void init() //每次都要先执行
{
  fail[0]=0;
  memset(zh[0],0,sizeof(zh[0]));
  cc=0;res=0;
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

void make(long long p,long long ti)
{
  if (ff[p][ti])
    return;
  ff[p][ti]=true;
  char *s=ke;
  long long tt;
  for (;*s;s++)
  {
    tt=zh[p][sn[*s]];
    int flt=0;
    long long t=tt;
    while (t)
    {
      if (shu[t])
        flt++;
      t=fail[t];
    }
    if (!flt)
    {
      mm.z[p+1+(cc+1)*ti][tt+1+(cc+1)*ti]++;
      make(tt,ti);
    }
    else
    {
      if (ti+flt<2)
      {
        mm.z[p+1+(cc+1)*ti][tt+1+(cc+1)*(ti+1)]++;
        make(tt,ti+1);
      }
    }
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  sn['A']=1;sn['T']=2;sn['C']=3;sn['G']=4;
  while (scanf("%lld%lld",&n,&m)!=EOF)
  {
    init();
    for (i=1;i<=n;i++)
    {
      scanf("%s",ss[i]);
      ins(ss[i],i);
    }
    acinit();
    mm.z[1][1]=4;
    mm.dx=mm.dy=1;
    rr=mm.power(m);
    res=rr.z[1][1];
    mm.zero();
    memset(ff,0,sizeof(ff));
    make(0,0);
    mm.dx=mm.dy=(cc+1)*2;
    rr=mm.power(m);
    for (i=0;i<=cc;i++)
    {
      res=(res-rr.z[1][i+1])%mod;
      res=(res-rr.z[1][i+1+cc+1])%mod;
    }
    res%=mod;res+=mod;res%=mod;
    cout<<res<<endl;
  }
  return 0;
}
