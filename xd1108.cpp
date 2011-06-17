#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
const int maxlongint=2147483647;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");

int i,j,k,t,n,m,zz,zu,mm=1,zuo,you,yout;
int shu[150000];
bool ff;

int main()
{
  //freopen("ti.in","r",stdin);
  //freopen("ti.out","w",stdout);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%d%d",&n,&m);
    mm=1;
    for (i=1;i<=n;i++)
      scanf("%d",&shu[i]);
    sort(&(shu[1]),&(shu[n+1]));
    for (i=1;i<n;i++)
    {
      zuo=i;
      you=n;
      yout=n;
      if (n-i+1<=mm)
        break;
      while (1)
      {
        int zhong=(zuo+you)>>1;
        if (you-zuo<1)
          break;
        ff=(shu[you]-shu[i]<=m);
        
        if (!ff)
        {
          yout=you;
          you=zhong;
          
      }
        else
        {
          mm=max(mm,you-i+1);
          zuo=you;
          you=yout-1;
        }
      }
      
    }
    printf("%d\n",mm);
  }
  }
        
