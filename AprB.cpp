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

class D
{
public:
  long long x,y;
  bool operator <(const D w) const
  {
    if (x!=w.x)
      return x<w.x;
    else
      return y<w.y;
  }
};

int i,j,k,n,m,zz,zu,mm;
bool f[1050];
map<D,int> hash;
D dian[1005];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    hash.clear();
    for (i=1;i<=n;i++)
    {
      cin>>dian[i].x>>dian[i].y;
      hash[dian[i]]=i;
    }
    mm=0;
    for (i=1;i<=n;i++)
    {
      int ttx=dian[i].x*2,tty=dian[i].y*2;
      for (j=1;j<=n;j++)
      {
        if ((i==j)||(!(dian[j]<dian[i])))
          continue;
        D tt;
        tt.x=ttx-dian[j].x;tt.y=tty-dian[j].y;
        if (hash.count(tt))
          mm++;
      }
    }
    cout<<mm<<endl;
  }
}

        



