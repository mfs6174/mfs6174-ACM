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
#define maxn 110
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=100000;

int i,j,k,t,cc;
int bianx[11000],biany[11000];
int huan[110],ff[110];
bool h[110];
bool fl=true;
int g[maxn][maxn]; //存放原图 
int dis[maxn][maxn];//存放每两点的最短路径值 
int pre[maxn][maxn];//存放前驱结点 
int path[maxn];     //存放最终路径 
int n,m,cnt,minc;
int a,b;

void floyd()
{
  minc=maxlongint;
  for(int k=0;k<n;k++)
  {
    for(int i=0;i<k;i++)
      for(int j=i+1;j<k;j++)
      {
        if(minc>dis[i][j]+g[k][i]+g[k][j])
        {
          minc=dis[i][j]+g[k][i]+g[k][j];
          cnt=0;
          int p=j;
          while(p!=i)      //逆向寻找前驱结点直到找到最前面的i。i->…->j 
          {
            path[cnt++]=p;
            p=pre[i][p];
          }               
          path[cnt++]=i;
          path[cnt++]=k;   
        }    
      }
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        if(dis[i][j]>dis[i][k]+dis[k][j])
        {
          dis[i][j]=dis[i][k]+dis[k][j];
          pre[i][j]=pre[k][j];//自己好好根据注释好好理一下。                                 
        }        
      }      
  }
}

void dfs(int x,int fu)
{
  int i;
  if (!fl)
    return;
  if (h[x]&&x!=fu)
  {
    fl=false;
    return;
  }
  h[x]=true;
  for (i=0;i<n;i++)
    if ((g[x][i]!=maxlongint)&&(i!=fu)&&((x!=fu)||(i!=a)&&(i!=b)))
      dfs(i,x);
}

void sv()
{
  int i;
  for (i=0;i<cnt;i++)
  {
    huan[i+1]=path[i];
    h[path[i]]=true;
  }
  for (i=1;i<=cnt;i++)
  {
    cc++;
    if (i==1)
      a=huan[cnt];
    else
      a=huan[i-1];
    if (i==cnt)
      b=huan[1];
    else
      b=huan[i+1];
    dfs(huan[i],huan[i]);
    if (!fl)
      break;
  }
}

int main()
{
  cin>>n>>m;
   for(int i=0;i<n;i++) //初始化 
     for(int j=0;j<n;j++)
     {
       g[i][j]=maxlongint;
       dis[i][j]=maxlongint;
       pre[i][j]=i; //见前注释 
     }
  for (i=1;i<=m;i++)
  {
    cin>>j>>k;
    g[j-1][k-1]=1;
    g[k-1][j-1]=1;
    dis[j-1][k-1]=1;
    dis[k-1][j-1]=1;
    bianx[i]=j;
    biany[i]=k;
  }
  floyd();
  if (minc==maxlongint)
  {
    cout<<"NO"<<endl;
    exit(0);
  }
  sv();
  if (fl&&cc>=3)
    cout<<"FHTAGN!"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
