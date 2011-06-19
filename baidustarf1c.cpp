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
#include<ctime>
#include<cstdlib>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int main()
{
  int n;
  string t;
  srand(time(NULL));
  cin>>n;
  while (n)
  {
    for (int i=1;i<=n;i++)
      cin>>t;
    if (n!=5)
      n=rand()%n+1;
    cout<<n<<endl;
    cin>>n;
  }
}
