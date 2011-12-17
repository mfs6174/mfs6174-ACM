/*
ID: mfs6174
PROG: 计算几何基本函数
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
#define sf scanf
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
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
  int  x; 
  int y;
  //constructor
  P(int a=0, int b=0) 
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
  int operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  int operator *(const P &b) const
  {
    return x*b.x+y*b.y;
  }
  void input()
  {
    scanf("%d%d",&x,&y);
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

inline double dst(P p1,P p2)                
{ 
  return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
}

inline double cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

inline bool os(SEG &l,P &p) //点在线段上
{ 
  return( (cwz(cha(l.s,l.e,p))==0) &&( ( cwz((p.x-l.s.x)*(p.x-l.e.x))<=0 )&&( cwz((p.y-l.s.y)*(p.y-l.e.y))<=0 ) ) ); 
}

P lcp(P aa, P ad, P ba, P bd)//返回fail如果true说明平行或重合再交叉相减叉积即可
{ // 求直线交点  
  ad = ad - aa;  
  bd = bd - ba;  
  double tmp = bd ^ ad;
  fail=false;
  if (cwz(tmp)==0)
  {
    fail=true;
    return P(0,0);
  }
  else
    return P((ad.x * bd.x * (ba.y - aa.y) + aa.x * bd.x * ad.y - ba.x * ad.x * bd.y) / tmp,  
             (ad.y * bd.y * (aa.x - ba.x) + ba.y * ad.y * bd.x - aa.y * bd.y * ad.x) / tmp);  
}  


inline P scp(SEG l1,SEG l2) //线段交点 不考虑（部分）重合的数据 fail表示不相交
{
  P rr;
  rr=lcp(l1.s,l1.e,l2.s,l2.e);
  if (!fail)
    if (os(l1,rr)&&os(l2,rr))
      return rr;
  fail=true;
  return P(0,0);
}


int i,j,k,t,n,m;
P dian[10];
int fang[10],sui[10];
bool yong[10],fl;

bool check()
{
  int i,j;
  memset(yong,0,sizeof(yong));
  for (i=1;i<=4;i++)
    yong[fang[i]]=true;
  j=0;
  for (i=1;i<=8;i++)
    if (!yong[i])
      sui[++j]=i;
  int z=0,zhi[5];
  if ( (dian[fang[1]]-dian[fang[2]])*(dian[fang[1]]-dian[fang[4]])==0)
  {
    z++;
    zhi[1]=2;zhi[2]=4;zhi[3]=3;
  }
  if ( (dian[fang[1]]-dian[fang[2]])*(dian[fang[1]]-dian[fang[3]])==0)
  {
    z++;
    zhi[1]=2;zhi[2]=3;zhi[3]=4;
  }
  if ( (dian[fang[1]]-dian[fang[3]])*(dian[fang[1]]-dian[fang[4]])==0)
  {
    z++;
    zhi[1]=3;zhi[2]=4;zhi[3]=2;
  }
  if (z!=1)
    return false;
  if (!( ( (dian[fang[1]]-dian[fang[zhi[1]]])*(dian[fang[zhi[1]]]-dian[fang[zhi[3]]])==0)&&(dian[fang[1]]-dian[fang[zhi[2]]])*(dian[fang[zhi[2]]]-dian[fang[zhi[3]]])==0))
    return false;
  if (cwz(dst(dian[fang[1]],dian[fang[zhi[1]]])-dst(dian[fang[1]],dian[fang[zhi[2]]]))!=0)
    return false;
  z=0;
  if ( (dian[sui[1]]-dian[sui[2]])*(dian[sui[1]]-dian[sui[4]])==0)
  {
    z++;
    zhi[1]=2;zhi[2]=4;zhi[3]=3;
  }
  if ( (dian[sui[1]]-dian[sui[2]])*(dian[sui[1]]-dian[sui[3]])==0)
  {
    z++;
    zhi[1]=2;zhi[2]=3;zhi[3]=4;
  }
  if ( (dian[sui[1]]-dian[sui[3]])*(dian[sui[1]]-dian[sui[4]])==0)
  {
    z++;
    zhi[1]=3;zhi[2]=4;zhi[3]=2;
  }
  if (z!=1)
    return false;
  if (!( ( (dian[sui[1]]-dian[sui[zhi[1]]])*(dian[sui[zhi[1]]]-dian[sui[zhi[3]]])==0)&&(dian[sui[1]]-dian[sui[zhi[2]]])*(dian[sui[zhi[2]]]-dian[sui[zhi[3]]])==0))
    return false;
  return true;
}
  
void dfs(int x)
{
  int i;
  for (i=fang[x-1]+1;i<=8-(4-x);i++)
  {
    fang[x]=i;
    if (x==4)
      fl=check();
    else
      dfs(x+1);
    if (fl)
      return;
  }
}

int main()
{
  //freopen("ti.in","r",stdin);
  for (i=1;i<=8;i++)
    dian[i].input();
  dfs(1);
  if (fl)
  {
    cout<<"YES"<<endl;
    for (i=1;i<4;i++)
      cout<<fang[i]<<' ';
    cout<<fang[4]<<endl;
    for (i=1;i<4;i++)
      cout<<sui[i]<<' ';
    cout<<sui[4]<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}
    
