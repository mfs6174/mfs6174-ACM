/*
ID: mfs6174
PROG: uestc1487 WFS
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
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

struct D
{
  int x,y,t;
  unsigned z;
};
D dui[1000000],d;
int i,j,k,t,n,m,mm,s,ss,e,a,b,xx,yy,zz;
bool hash[30][30][1200];
int tu[30][30],zou[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
char tc;
unsigned ke,kk[20];

int main()
{
  kk[1]=1;
  for (i=2;i<20;i++)
    kk[i]=kk[i-1]<<1;
  while (inf>>n>>m>>ss)
  {
    zz++;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        inf>>tc;
        if (tc=='.')
          tu[i][j]=0;
        else if (tc=='*')
          tu[i][j]=-111;
        else if (tc=='@')
        {
          a=i;b=j;
          tu[i][j]=0;
        }
        else if (tc=='^')
          tu[i][j]=111;
        else if ((tc>='a')&&(tc<='j'))
          tu[i][j]=tc-'a'+1;
        else
          tu[i][j]=-(tc-'A'+1);
      }
    memset(hash,0,sizeof(hash));
    s=e=0;
    mm=-1;
    hash[a][b][0]=1;
    e++;
    dui[e].x=a;
    dui[e].y=b;
    dui[e].z=0;
    dui[e].t=0;
    while (s!=e)
    {
      s=(s+1)%500000;
      d=dui[s];
      if (d.t>=ss-1)
        continue;
      for (i=1;i<=4;i++)
      {
        xx=d.x+zou[i][0];
        yy=d.y+zou[i][1];
        if (xx<1||yy<1||xx>n||yy>m)
          continue;
        if (tu[xx][yy]==111)
        {
          mm=d.t+1;
          break;
        }
        if (tu[xx][yy]==0)
        {
          if (hash[xx][yy][d.z])
            continue;
          hash[xx][yy][d.z]=true;
          e=(e+1)%500000;
          dui[e].x=xx;
          dui[e].y=yy;
          dui[e].z=d.z;
          dui[e].t=d.t+1;
          continue;
        }
        if (tu[xx][yy]>0)
        {
          ke=(d.z)|(kk[tu[xx][yy]]);
          if (hash[xx][yy][ke])
            continue;
          hash[xx][yy][ke]=true;
          e=(e+1)%500000;
          dui[e].x=xx;
          dui[e].y=yy;
          dui[e].z=ke;
          dui[e].t=d.t+1;
          continue;
        }
        if (tu[xx][yy]!=-111)
          if ((d.z)&(kk[-tu[xx][yy]]))
          {
            if (hash[xx][yy][d.z])
              continue;
            hash[xx][yy][d.z]=true;
            e=(e+1)%500000;
            dui[e].x=xx;
            dui[e].y=yy;
            dui[e].z=d.z;
            dui[e].t=d.t+1;

          }
      }
      if (mm>0)
        break;
    }
    cout<<"Case "<<zz<<": "<<mm<<endl;
  }
}

          
