/*
ID: mfs6174
PROG: SRM504.5 div 1 250
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
// const int maxlongint=2147483647;

// int main()
// {
//   int f[20][20];
//   int i,j;
//   for (i=1;i<=2;i++)
//     for (j=0;j<=9;j++)
//       f[i][j]=maxlongint;
//   f[1][0]=0;
//   for (j=4;j<=2000;j++)
//     if (f[1][(j-4)%10]!=maxlongint)
//       f[1][j%10]=min(f[1][j%10],f[1][(j-4)%10]+1);
//   for (j=0;j<=9;j++)
//     f[2][j]=f[1][j];
//   for (j=7;j<=2000;j++)
//     if (f[2][(j-7)%10]!=maxlongint)
//       f[2][j%10]=min(f[2][j%10],f[2][(j-7)%10]+1);
//   for (j=0;j<=9;j++)
//     cout<<f[2][j]<<endl;
// }


class TheNumbersWithLuckyLastDigit
{
public:
  int find(int n)
  {
    int t=n%10;
    if (t==0)
      if (n<20)
        return -1;
      else
        return 5;
    if (t==1)
      if (n<11)
        return -1;
      else
        return 2;
    if (t==2)
      if (n<12)
        return -1;
      else
        return 3;
    if (t==3)
      if (n<23)
        return -1;
      else
        return 5;
    if (t==4)
      return 1;
    if (t==5)
      if (n<15)
        return -1;
      else
        return 3;
    if (t==6)
      if (n<16)
        return -1;
      else
        return 4;
    if (t==7)
      return 1;
    if (t==8)
      return 2;
    if (t==9)
      if (n<19)
        return -1;
      else
        return 4;
  }
};

  
