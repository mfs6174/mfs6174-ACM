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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

class MagicalGirlLevelTwoDivTwo
{
public:
  bool dao[200][200];
  int n;
  vector<int> ke;
  void dfs(int x,int y,int xx,int yy)
  {
     if (abs(x)>70||abs(y)>70)
      return;
    if (dao[xx+75][yy+75])
      return;
    if (dao[x+75][y+75])
      return;
    dao[x+75][y+75]=true;
    int i,j,k;
    for (i=-1;i<=1;i++)
      for (j=-1;j<=1;j++)
      {
        if (!(i*j))//卧槽的运算顺序
          continue;
        for (k=0;k<n;k++)
        {
          dfs(x+ke[k]*i,y+j,xx,yy);
          dfs(x+j,y+ke[k]*i,xx,yy);
        }
      }
  }
    
  string isReachable(vector <int> tiao, int x, int y)
  {
    n=tiao.size();
    memset(dao,0,sizeof(dao));
    ke.clear();
    for (int i=0;i<n;i++)
      ke.push_back(tiao[i]);
    dfs(0,0,x,y);
    if (dao[x+75][y+75])
      return "YES";
    else
      return "NO";
  }
};

vector<int> a;
MagicalGirlLevelTwoDivTwo t;
int main()
{
  a.clear();
  a.push_back(29);
  cout<<t.isReachable(a,29,0)<<endl;
}
