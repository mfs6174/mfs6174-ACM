/*
ID: mfs6174
PROG: BIT
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
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

#define MAXN 60000
int f[MAXN];
int n;

//f[x]总是表示x-lowbit+1 到 x的和
//注意up中的n表示数组最大范围，如果离散化就是数字数，在线算法不方便离散化就是数字最大范围，灵活处理
//注意从1开始，如果有0号数组，可以每个加1表示
inline int lowbit(int x)
{
  return x&(x^(x-1));
}

void upc(int x,int d,int n) //更新，x是位置，d是增加量，n是上界
{
  while (x<=n)
  {
    f[x]+=d;
    x+=lowbit(x);
  }
}

int downs(int x) //查找
{
  int s=0;
  while (x>0)
  {
    s+=f[x];
    x-=lowbit(x);
  }
  return s;
}

int i,j,k,t,m,zz,zu,a,b,rr;
char ss[MAXN];
char tc;

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    printf("Case %d:\n",zz);
    scanf("%d%d",&n,&m);
    scanf("%s",ss+1);
    memset(f,0,sizeof(f));
    for (i=3;i<=n;i++)
      if (ss[i]=='w'&&ss[i-1]=='b'&&ss[i-2]=='w')
        upc(i,1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&t,&a);
      a++;
      if (t==0)
      {
        scanf("%d",&b);b++;
        rr=downs(b)-downs(a-1);
        if ( ( (a>1)&&ss[a]=='b'&&ss[a-1]=='w'&&ss[a+1]=='w' )|| ( (a>2)&&ss[a]=='w'&&ss[a-1]=='b'&&ss[a-2]=='w'))
          rr--;
        cout<<rr<<endl;
      }
      else
      {
        scanf(" %c",&tc);
        if (a>2&&ss[a-2]=='w'&&ss[a-1]=='b')
        {
          if (ss[a]=='w'&&tc=='b')
            upc(a,-1,n);
          if (ss[a]=='b'&&tc=='w')
            upc(a,1,n);
        }
        if (a>1&&a<n&&ss[a-1]=='w'&&ss[a+1]=='w')
        {
          if (ss[a]=='b'&&tc=='w')
            upc(a+1,-1,n);
          if (ss[a]=='w'&&tc=='b')
            upc(a+1,1,n);
        }
        if (a+2<=n&&ss[a+1]=='b'&&ss[a+2]=='w')
        {
          if (ss[a]=='w'&&tc=='b')
            upc(a+2,-1,n);
          if (ss[a]=='b'&&tc=='w')
            upc(a+2,1,n);
        }
        ss[a]=tc;
      }
    }
  }
  return 0;
}
