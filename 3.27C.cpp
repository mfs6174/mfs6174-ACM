
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;
//ifstream inf("C.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

long long mm,t,c,he;
int n,m,zz,zu,i,j,k;
long long  yu[1000005];

int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>m>>n;
    he=0;
    mm=0;
    memset(yu,0,sizeof(yu));
    yu[0]=1;
    for (i=1;i<=n;i++)
    {
      cin>>t;
      t%=m;
      he=(he+t)%m;
      yu[he]++;
    }
    for (i=0;i<m;i++)
      if (yu[i]>1)
        mm+=((yu[i])*(yu[i]-1)/2);
    cout<<mm<<endl;
  }
  return 0;
}
