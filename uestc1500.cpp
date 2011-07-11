/*
ID: mfs.dev2
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

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,n,m,t,c,cc,ccc,mm,zz,tt;
int f[11000][110],wu[11000][2],duo[110][110][2],shao[110][110][2],ff[110][110];

int main()
{
  while(cin>>n>>m)
  {
    c=cc=ccc=0;
    for (i=1;i<=n;i++)
    {
      cin>>zz>>t;
      if (t==2)
      {
        for (j=1;j<=zz;j++)
        {
          ccc++;
          cin>>wu[ccc][0]>>wu[ccc][1];
        }
        continue;
      }
      if (t==1)
      {
        cc++;
        duo[cc][0][0]=zz;
        for (j=1;j<=zz;j++)
          cin>>duo[cc][j][0]>>duo[cc][j][1];
        continue;
      }
      c++;
      shao[c][0][0]=zz;
      for (j=1;j<=zz;j++)
        cin>>shao[c][j][0]>>shao[c][j][1];
    }
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for (i=1;i<=ccc;i++)
    {
      f[i][0]=0;
      for (j=0;j<=m;j++)
      {
        f[i][j]=f[i-1][j];
        if (j>=wu[i][0]&&f[i-1][j-wu[i][0]]>=0)
          f[i][j]=max(f[i][j],f[i-1][j-wu[i][0]]+wu[i][1]);
      }
    }
    for (i=ccc+1;i<=ccc+cc;i++)
    {
      f[i][0]=0;
      for (j=0;j<=m;j++)
      {
        f[i][j]=f[i-1][j];
        for (k=1;k<=duo[i-ccc][0][0];k++)
          if (j>=duo[i-ccc][k][0]&&f[i-1][j-duo[i-ccc][k][0]]>=0)
            f[i][j]=max(f[i][j],f[i-1][j-duo[i-ccc][k][0]]+duo[i-ccc][k][1]);
      }
    }
    tt=ccc+cc;
    for (i=tt+1;i<=c+tt;i++)
    {
      memset(ff,-1,sizeof(ff));
      //特别的，至少选一个的背包要重新开一个背包，初始－1，（包括f[i][0]),然后循环［后］给当前物品本身大小对应的背包一个值比较（这样可处理有0体积的物品），最后将每个不为值-1的容量的背包（包括0的，因为可能有0体积物品）做为物品对主背包做［选且只选一个的背包］
      for (k=1;k<=shao[i-tt][0][0];k++)
      {
        for (j=0;j<=m;j++)
        {
          ff[k][j]=ff[k-1][j];
          if (j>=shao[i-tt][k][0]&&ff[k-1][j-shao[i-tt][k][0]]>=0)
            ff[k][j]=max(ff[k][j],ff[k-1][j-shao[i-tt][k][0]]+shao[i-tt][k][1]);
        }
        if (shao[i-tt][k][0]<=m)
          ff[k][shao[i-tt][k][0]]=max(ff[k][shao[i-tt][k][0]],shao[i-tt][k][1]);
      }
      for (j=0;j<=m;j++)
        for (k=0;k<=j;k++)
          if (ff[shao[i-tt][0][0]][k]>=0&&f[i-1][j-k]>=0)
            f[i][j]=max(f[i][j],f[i-1][j-k]+ff[shao[i-tt][0][0]][k]);//这里要搞清楚，不让不用意思是至少选取一种做好的容量用，而选一种时，结果都存入f[i][j]，要与自身比较而不是赋值
      mm=-maxlongint;
    }
    for (i=0;i<=m;i++)
      mm=max(mm,f[tt+c][i]);
    cout<<mm<<endl;
  }
  return 0;
}

    
