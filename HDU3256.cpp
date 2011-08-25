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
const int mod=10033001;
const double Ling=1e-8;

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
struct D
{
  int x,y;
};
  
int i,j,k,t,n,m,zu,zz,a,b,xx,yy,cc;
bool hash[mod];
SEG xian[600];
double y;

void push(int x,int y)
{
  long long t=x;
  t=t*13331+y*133331;
  t=(t%mod+mod)%mod;
  if (!hash[t])
  {
    cc++;
    hash[t]=true;
  }
  // D tt;
  // tt.x=x;tt.y=y;
  // if (hash[t].size()==0)
  // {
  //   hash[t].push_back(tt);
  //   cc++;
  //   return;
  // }
  // for (int i=0;i<hash[t].size();i++)
  //   if (hash[t][i].x==x&&hash[t][i].y==y)
  //     return;
  // cc++;
  // hash[t].push_back(tt);
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    cc=0;
    //for (i=0;i<mod;i++)
    //  hash[i].clear();
    memset(hash,0,sizeof(hash));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      xian[i].input();
    if (xian[i].s.x>xian[i].e.x)
    {
      P t=xian[i].s;
      xian[i].s=xian[i].e;
      xian[i].e=t;
    }
    for (i=1;i<=n;i++)
    {
      a=(int)(xian[i].s.x);
      b=(int)(xian[i].e.x);
      for (j=a;j<=b;j++)
      {
        if (cwz(xian[i].s.x-xian[i].e.x)==0)
        {
          if (cwz(int(xian[i].s.x)-xian[i].s.x)==0)
          {
            xx=int(xian[i].s.y);yy=int(xian[i].e.y);
            if (xx>yy)
            {
              int t=xx;
              xx=yy;
              yy=t;
            }
            for (k=xx;k<=yy;k++)
              push(int(xian[i].s.x),k);
          }
          continue;
        }
        if (cwz(xian[i].s.y-xian[i].e.y)==0)
        {
          if (cwz(int(xian[i].s.y)-xian[i].s.y)==0)
          {
            yy=(int)xian[i].s.y;
            xx=j;
            push(xx,yy);
          }
          continue;
        }
        y=(j-xian[i].s.x)/(xian[i].s.x-xian[i].e.x)*(xian[i].s.y-xian[i].e.y)+xian[i].s.y;
        if (cwz(int(y)-y)==0)
        {
          xx=j;
          yy=int(y);
          push(xx,yy);
        }
      }
    }
    printf("Case %d: %d\n",zz,cc);
  }
  return 0;
}

