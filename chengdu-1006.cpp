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
#define LL long long
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

LL  i,j,k,t,n,m,zu,zz;

struct P 
{ 
  LL x; 
  LL y;
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
  void input()
  {
    scanf("%I64d%I64d",&x,&y);
  }

}; 

P feng[1200];
LL heng[1200],su[1200];
LL g=20;
double mm,h,v,mv=-1;
double gao[1200];
LL zx;
LL wei[1200][5];

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%I64d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%I64d%I64d%I64d",&n,&m,&t);
    mm=-maxlongint;mv=-maxlongint;
    for (i=1;i<=n;i++)
    {
      feng[i].input();
      mm=max(mm,(double)feng[i].y);
    }
    h=fabs(mm-feng[1].y);
    v=sqrt(2*g*h);
    mv=max(mv,v);
    for (i=1;i<=m;i++)
    {
      scanf("%I64d%I64d%I64d",&heng[i],&su[i],&t);
      zx=0;
      for (j=1;j<n;j++)
      {
        if (heng[i]>feng[j].x&&heng[i]<=feng[j+1].x)
        {
          wei[i][0]=j;wei[i][1]=j+1;
          break;
        }
      }
      gao[i]=(double)(feng[wei[i][1]].y-feng[wei[i][0]].y)/(feng[wei[i][1]].x-feng[wei[i][0]].x)*(heng[i]-feng[wei[i][0]].x)+feng[wei[i][0]].y;
    }
    for (i=1;i<=m;i++)
    {
      v=sqrt(su[i]*su[i]+2*g*(gao[i]-feng[1].y));
      mv=max(mv,v);
    }
    printf("Case %I64d: %.2lf\n",zz,mv);
  }
  return 0;
}

    
      
      
    
      
    
      


