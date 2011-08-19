/*
ID: mfs6174
PROG: ti
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
#define LL long long
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

LL i,j,k,t,n,m,zz,zu,shua,l,o,p,aa,bb,kk;
LL f[25][25][25][11];
char a[30],b[30];
LL shu[30];

LL dfs(int w,int x,int y,int p)
{
  LL i,re=0;
  if (f[w][x][y][p]!=-1)
    return f[w][x][y][p];
  else
    f[w][x][y][p]=0;
  if (w==1)
    return f[w][x][y][p];
  if (p==4)
  {
    for (i=0;i<=9;i++)
      re+=dfs(w-1,x-1,y,i);
    f[w][x][y][p]=re;
    return re;
  }
  if (p==7)
  {
    for (i=0;i<10;i++)
      re+=dfs(w-1,x,y-1,i);
    f[w][x][y][p]=re;
    return re;
  }
  for (i=0;i<10;i++)
    re+=dfs(w-1,x,y,i);
  f[w][x][y][p]=re;
  return re;
}

void tongji(char s[],LL w,LL x,LL y,LL &aa)
{
  if (w<1)
    return;
  int i;
  for (i=0;i<s[0]-48;i++)
    aa+=f[w][x][y][i]>0?f[w][x][y][i]:0;
  if (s[0]-48==4)
    x--;
  if (s[0]-48==7)
    y--;
  tongji(s+1,w-1,x,y,aa);
}

void cha(int x,int k,int a,int b)
{
  if (x>l)
    return;
  int i,s=0;
  for (i=0;i<10;i++)
  {
    if (s+f[l+1-x][a][b][i]>=k)
      break;
    if (f[l+1-x][a][b][i])
      t=i;
    s+=f[l+1-x][a][b][i];
  }
  //if (s+f[l+1-x][a][b][i]==k)
    t=i;
  k-=s;
  if (t==4)
    a--;
  if (t==7)
    b--;
  shu[x]=t;
  cha(x+1,k,a,b);
}

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    printf("Case #%lld:\n",zz);
    cin>>a>>b>>n>>m;
    memset(f,-1,sizeof(f));
    for (i=0;i<=9;i++)
    {
      if (i==4)
        f[1][1][0][4]=1;
      else
        if (i==7)
          f[1][0][1][7]=1;
        else
          f[1][0][0][i]=1;
    }
    l=max(strlen(a),strlen(b));
    aa=0;
    for (i=0;i<10;i++)
      dfs(l,n,m,i);
    l=strlen(a);
    tongji(a,l,n,m,aa);
    bb=0;
    l=strlen(b);
    tongji(b,strlen(b),n,m,bb);
    cin>>kk;
    l=max(strlen(a),strlen(b));
    for (i=1;i<=kk;i++)
    {
      memset(shu,0,sizeof(shu));
      cin>>k;
      k+=aa;
      if (k>bb)
      {
        cout<<"Nya!"<<endl;
        continue;
      }
      cha(1,k,n,m);
      bool fl=false;
      for (j=1;j<=l;j++)
        if (fl||shu[j])
          cout<<shu[j];
        else
          if (shu[j])
            fl=true;
      cout<<endl;
    }
  }
  return 0;
}
