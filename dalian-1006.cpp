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
#include<queue>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,tt,s,ttt;
priority_queue<int> da;
priority_queue<int,vector<int>,greater<int> > xiao;

int main()
{
  freopen("ti.in","r",stdin);
  while (scanf("%d%d",&n,&k)!=EOF)
  {
    while (!da.empty())
      da.pop();
    while( !xiao.empty())
      xiao.pop();
    s=0;
    getchar();
    for (i=1;i<=n;i++)
    {
      char tc;
      scanf("%c",&tc);
      if (tc=='Q')
      {
        getchar();
        printf("%d\n",da.top());
      }
      else
        if (tc=='I')
        {
          s++;
          scanf("%d",&m);getchar();
          if (s-k+1<1)
          {
            da.push(m);
            continue;
          }
          if (xiao.size()<k-1)
          {
            da.push(m);
            while (da.size()>s-k+1)
            {
              t=da.top();
              da.pop();
              xiao.push(t);
            }
            continue;
          }
          t=da.top();
          tt=xiao.top();
          if (m<=t)
            da.push(m);
          else
          {
            xiao.push(m);
            ttt=xiao.top();
            xiao.pop();
            da.push(ttt);
          }
        }
    }
  }
}
          
  
