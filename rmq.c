#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=200000;
int j,t,i,n,m,l,r,f[100][32];//f[i][j]为从i开始往后2^j个数中的最大值，f[i][0]要处理成a[i]
//以下都是max的，所以f[i][j]初始值为0


void rmqchuli(int x)//预处理，x为数字个数
{
  int i,j,t=(int)(log((double)x)/log(2.0));
	for (j=1;j<=t;j++)
      for (i=x-(1<<j)+1;i>=1;i--)
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int cha(int x,int y)//查询过程，x到y闭区间
{
	int k;
	k=(int)(log((double)(y-x+1))/log(2.0));
	return max(f[x][k],f[y-(1<<k)+1][k]);
}

int main()
{
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&f[i][0]);
  rmqchuli(n);
  while (scanf("%d%d",&l,&r)!=EOF)
    cout<<cha(l,r)<<endl;
  return 0;
}
