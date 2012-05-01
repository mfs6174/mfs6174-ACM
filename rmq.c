#include "math.h"
//using namespace std;

const int maxn=200000;
long long j,t,i,n,m,l,r,f[100][32];//f[i][j]为从i开始往后2^j个数中的最大值，f[i][0]要处理成a[i]
//以下都是max的，所以f[i][j]初始值为0


void rmqchuli(long long x)//预处理，x为数字个数
{
  long long i,j,t=(long long)(log((double)x)/log(2.0));
	for (j=1;j<=t;j++)
      for (i=x-(1<<j)+1;i>=1;i--)
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

long long cha(long long x,long long y)//查询过程，x到y闭区间
{
	long long k;
	k=(long long)(log((double)(y-x+1))/log(2.0));
	return max(f[x][k],f[y-(1<<k)+1][k]);
}

int main()
{
  return 0;
}
