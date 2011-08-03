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

#define NODE 1500000 //最大可能出现的节点数
#define CH 28 //分支数

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


int i,j,k,n,t,tp;
int cc,c;//cc是统计使用了多少个节点
int zh[NODE][CH];//自动机机体
int shu[NODE];//相应节点的数据域
int fail[NODE];//失败指针，貌似是指向［彻底］失败的位置
int sn[300];//每个字符的代号，无效字符是0
int q[NODE];//队列
int zhan[110000];
bool best[110000];
int a[110000],b[110000],pp[110000];
int m,ccc;
char s[110000],ss[110000],st[110000];

int pos=0,head[110000];
struct Edge  
{  
  int next,u,v;  
}node[150000]; 
void add(int u,int v)  //这里没有边权，如果加上边权则结构里加一个东西
{  
  if(u==v) return;  
  node[pos].u=u;                 //如果指向自己的边则舍去  
  node[pos].v=v;  
  node[pos].next=head[u];  
  head[u]=pos++;  
}

void init() //每次都要先执行
{
  fail[0]=0;
  memset(zh[0],0,sizeof(zh[0]));
  memset(head,-1,sizeof(head));
  pos=1;
  cc=0;
  memset(best,0,sizeof(best));
  tp=0;
}

void ins(char *s, int d) //建立trie
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
  shu[p]++;
  add(p,d);
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

void com(char *s) //查找每个模式串出现的次数
{
  int p=0,i=0;
  for (;*s;s++)
  {
    i++;
    p=zh[p][sn[*s]];//转移
    int t=p;
    while (t)//跟随fail找符合的模式
    {
      if (shu[t])
      {
        int j,v;
        for(j=head[t];j!=-1;j=node[j].next)
        {
          v=node[j].v;
          if (i>=a[v]&&(i<=b[v]||b[v]==-1))
          {
            while (tp>0&&zhan[tp]>=v)
            {
              best[zhan[tp]]=false;
              tp--;
            }
            zhan[++tp]=v;
            if (best[v-1]&&zhan[tp-1]==v-1||v==1)
                best[v]=true;
          }
        }
      }
      t=fail[t];
    }
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  for (char tc='a';tc!='z';tc++)
    sn[tc]=tc-'a'+1;
  while (scanf("%s%s",s,ss)!=EOF)
  {
    init();
    char *p=ss;
    c=0;ccc=0;
    bool fl=false;
    if ((*p>='a')&&(*p<='z'))
      i=0;
    else
      i=1;
    for (;*p;p++)
    {
      if ((*p!='*'))
        c++;
      else
        fl=true;
      if ((*p>='a')&&(*p<='z')&&(i==0||(*(p-1)=='?'||(*(p-1)=='*'))))
      {
        ccc++;
        i=0;
        st[i]=*p;
        a[ccc]=c;
        if (fl)
          b[ccc]=-1;
        else
          b[ccc]=c;
      }
      else
      if ((*p>='a')&&(*p<='z'))
      {
        i++;
        st[i]=*p;
      }
      if ((*(p)=='?'||(*(p)=='*'))&&(*(p-1)>='a')&&(*(p-1)<='z'))
      {
        i++;
        st[i]=0;
        ins(st,ccc);
      }
    }
    if ((*(p-1)>='a')&&(*(p-1)<='z'))
    {
      i++;
      st[i]=0;
      ins(st,ccc);
    }
    acinit();
    com(s);
    if (best[strlen(s)])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
