/*
ID: mfs6174
PROG: uestc1331 floodfill
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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,a,b,mm;
bool ff[1010][1010];
int tu[1010][1010];
char tc;

void dfs(int x,int y)
{
  if (ff[x][y])
    return;
  if ((x<1)||(x>n)||(y<1)||(y>m)||(!tu[x][y]))
  {
    ff[x][y]=true;
    return;
  }
  ff[x][y]=true;
  if (tu[x][y]==2)
    mm++;
  dfs(x-1,y);
  dfs(x+1,y);
  dfs(x,y-1);
  dfs(x,y+1);
}

  
int main()
{
  while (cin>>n>>m)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        cin>>tc;
        if (tc=='.')
        tu[i][j]=1;
        else if (tc=='*')
          tu[i][j]=2;
        else
          tu[i][j]=0;
        if (tc=='X')
        {
        tu[i][j]=1;
        a=i;
        b=j;
        }
      }
    mm=0;
    memset(ff,0,sizeof(ff));
    dfs(a,b);
    cout<<mm<<endl;
  }
}
