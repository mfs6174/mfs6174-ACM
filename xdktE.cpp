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
#include<cmath>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

const double INF=1e200;
const double Ling=1e-8;
bool fail;

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

struct P 
{ 
  double x; 
  double y;
  //constructor
  P(double a=0, double b=0) 
  { x=a; y=b;}
  P operator+(const P &b) const
  {  
    return P(x + b.x, y + b.y);  
  }
  P operator - (const P &b) const
  {  
    return P(x - b.x, y - b.y);  
  }  
  bool operator<(const P &b) const//a在b逆时针 
  {   
    return x * b.y < y * b.x;  
  }
  bool operator==(const P &b) const
  {
    return ((cwz(x-b.x)==0)&&(cwz(y-b.y)==0));
  }
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  double operator *(const P &b) const
  {
    return x*b.x+y*b.y;
  }
  void input()
  {
    scanf("%lf%lf",&x,&y);
  }

}; 

struct SEG 
{ 
  P s,e; 
  SEG(P a=P(0,0), P b=P(0,0)) { s=a; e=b;}
  void input()
  {
    s.input();e.input();
  }
}; 

inline double cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

inline bool ol(SEG &l,P &p)
{ 
  return( (cwz(cha(l.s,l.e,p))==0)&&(cwz((p-l.s)*(l.e-l.s))>0) ); 
}

inline double dst(P &p1,P &p2)                
{ 
  return (abs(p1.x-p2.x)+abs(p1.y-p2.y));
}

int i,j,k,t,n,m,zu,zz,c;
P dian[550],yuan;
int ff[550];
int shi[550],shu[550];
int she[550][550];
int cc[550];
int tou[550];
double dis[550];
int shih[550][550],shuh[550][550];
int mm;
int f[550][10100];

inline bool cmp(const int a,const int b)
{
  return dis[a]<dis[b];
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    yuan.input();
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      dian[i].input();
      dis[i]=dst(yuan,dian[i]);
      scanf("%d%d",&shi[i],&shu[i]);
    }
    memset(ff,-1,sizeof(ff));
    memset(cc,0,sizeof(cc));
    c=0;
    for (i=1;i<=n;i++)
    {
      if (ff[i]!=-1)
        continue;
      c++;
      SEG ss(yuan,dian[i]);
      for (j=1;j<=n;j++)
        if (ol(ss,dian[j]))
        {
          cc[c]++;
          she[c][cc[c]]=j;
        }
      sort(&she[c][1],&she[c][cc[c]+1],cmp);
      ff[she[c][1]]=0;
      shuh[c][1]=shu[she[c][1]];
      shih[c][1]=shi[she[c][1]];
      for (j=2;j<=cc[c];j++)
      {
        ff[she[c][j]]=she[c][j-1];
        shuh[c][j]=shuh[c][j-1]+shu[she[c][j]];
        shih[c][j]=shih[c][j-1]+shi[she[c][j]];
      }
      tou[c]=she[c][cc[c]];
    }
    for (i=1;i<=m;i++)
      f[0][i]=-1;
    f[0][0]=0;
    for (i=1;i<=c;i++)
    {
      f[i][0]=0;
      for (j=1;j<=m;j++)
      {
        if (f[i-1][j]!=-1)
          f[i][j]=f[i-1][j];
        else
          f[i][j]=-1;
        for (k=1;k<=cc[i];k++)
          if (j>=shih[i][k]&&f[i-1][j-shih[i][k]]!=-1)
            f[i][j]=max(f[i][j],f[i-1][j-shih[i][k]]+shuh[i][k]);
      }
    }
    mm=0;
    for (i=0;i<=m;i++)
      mm=max(mm,f[c][i]);
    cout<<mm<<endl;
  }
  return 0;
}

