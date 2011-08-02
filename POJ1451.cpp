/*
ID: mfs6174
PROG: POJ14451
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

#define NODE 50000 //最大可能出现的节点数
#define CH 27 //分支数
#define sf scanf

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,n,t,m,zz,zu;
int cc,c;//cc是统计使用了多少个节点
int zh[NODE][CH];//自动机机体
int shu[NODE];//相应节点的数据域
int fu[NODE];
int sn[300];//每个字符的代号，无效字符是0
char ss[120],tc,rr[120],zi[NODE],nc[120];
int ru[120],f[120],g[120];
char ma[12][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void init() //每次都要先执行
{
  memset(zh[0],0,sizeof(zh[0]));
  cc=0;
}

void ins(char *s, int d) //建立trie
{
  int p=0;
  for(;*s;s++)
  {
    int t=sn[*s];
    shu[p]+=d;
    if(!zh[p][t])
    {
      cc++;
      memset(zh[cc],0,sizeof(zh[cc]));
      shu[cc] = 0;
      fu[cc]=p;
      zi[cc]=t+'a'-1;
      zh[p][t] =cc;
    }
    p =zh[p][t];
  }
  shu[p]+=d;
}

int cha(char *s,int &d)
{
  int p=0;
  for (;*s;s++)
  {
    int t=sn[*s];
    if (!zh[p][t])
      return 0;
    p=zh[p][t];
  }
  d=p;
  return shu[p];
}
void pf(int x)
{
  if (!x)
    return;
  rr[0]++;
  rr[rr[0]]=zi[x];
  pf(fu[x]);
}

void dfs(int x)
{
  int t,mm;
  mm=cha(nc,t);
  if (mm>f[x-1])
  {
    f[x-1]=mm;
    g[x-1]=t;
  }
  if (x>ru[0])
    return;
  if (mm)
    for (char *s=ma[ru[x]];*s;s++)
    {
      nc[x]=0;
      nc[x-1]=*s;
      dfs(x+1);
    }
}

int main()
{
  for (char i='a';i<='z';i++)
    sn[i]=i-'a'+1;
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&n);
    init();
    for (i=1;i<=n;i++)
    {
      sf("%s%d",ss,&t);
      ins(ss,t);
    }
    sf("%d",&m);
    cout<<"Scenario #"<<zz<<':'<<endl;
    for (k=1;k<=m;k++)
    {
      sf("%s",ss);
      for (j=1;ss[j-1]!='1';j++)
        ru[j]=ss[j-1]-'0';
      ru[0]=j-1;
      memset(f,0,sizeof(f));
      nc[0]=0;
      dfs(1);
      for (i=1;i<=ru[0];i++)
        if (f[i])
        {
          rr[0]=0;
          pf(g[i]);
          for (j=rr[0];j>0;j--)
            cout<<rr[j];
          cout<<endl;
        }
        else
          cout<<"MANUALLY"<<endl;
      cout<<endl;
    }
  }
  return 0;
}
