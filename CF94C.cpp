/*
ID: mfs6174
email: mfs6174@gmail.com
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,dd,tt,o;
int ff[10][10][10],tu[10][10];
int d[12][3]={{0,0},{0,0},{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };

bool ch(int x)
{
  if (x>0&&x<9)
    return true;
  else
    return false;
}

int main()
{
  //freopen("ti.in","r",stdin);
  for (i=1;i<=8;i++)
  {
    char ss[12];
    sf("%s",ss);
    for (j=0;j<8;j++)
      if (ss[j]=='S')
      {
        tu[i][j+1]=1;
        dd++;
      }
  }
  ff[0][8][1]=1;
  bool win=false;
  while (dd>0)
  {
    for (i=1;i<=8;i++)
      for (j=1;j<=8;j++)
        if (ff[k][i][j])
          for (o=1;o<=9;o++)
          {
            t=i+d[o][0];tt=j+d[o][1];
            if (ch(t)&&ch(tt))
              if (tu[t][tt]<1)
                ff[k+1][t][tt]=1;
          }
    k++;
    if (ff[k][1][8])
    {
      win=true;
      break;
    }
    for (i=8;i>0;i--)
      for (j=1;j<=8;j++)
        if (tu[i][j])
        {
          tu[i][j]=0;
          if (i+1>8)
            dd--;
          else
          {
            tu[i+1][j]=1;
            ff[k][i+1][j]=0;
          }
        }
  }
  for (i=1;i<=8;i++)
    for (j=1;j<=8;j++)
      if (ff[k][i][j])
      {
        win=true;
        break;
      }
  if (win)
    cout<<"WIN"<<endl;
  else
    cout<<"LOSE"<<endl;
  return 0;
}
              
      

