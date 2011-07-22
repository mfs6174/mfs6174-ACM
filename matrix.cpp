/*
ID: mfs6174
PROG: matrix class
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
ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

class ZHEN
{
public:
  long long z[300][300],dx,dy; //矩阵本体和大小
  ZHEN operator *(const ZHEN &x) //矩阵乘法
  {
    ZHEN r;
    r.dx=dx;r.dy=x.dy;
    long long i,j,k;
    for (i=1;i<=r.dx;i++)
      for (j=1;j<=r.dy;j++)
      {
        r.z[i][j]=0;
        for (k=1;k<=x.dx;k++)
          r.z[i][j]=(r.z[i][j]+(z[i][k]*x.z[k][j]))%mod;
      }
    return r;
  }
  void E(long long x)//单位化，执行后变为x阶单位矩阵
  {
    dx=dy=x;
    long long i,j;
    for (i=1;i<=dx;i++)
      z[i][i]=1;
  }
  ZHEN power(long long e) //矩阵快速幂
  {
    ZHEN tmp = (*this),rr;
    if (e==1) return *this;
    rr.E(dx,dy);
    while (e)
    {
      if (e&1)
        rr=rr*tmp;
      tmp=tmp*tmp;
      e=e>>1;
    }
    return rr;
  }
};
