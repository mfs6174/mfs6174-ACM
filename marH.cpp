
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
const int maxlongint=2147483647;

int zz,zu,n;
double rr[10];

int main()
{
  rr[1]=1.0;
  rr[2]=2.0;
  rr[3]=2.0;
  rr[4]=2.0;
  rr[5]=2.7071;
  rr[6]=3.0;
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    printf("%.2lf\n",rr[n]);
  }
}

