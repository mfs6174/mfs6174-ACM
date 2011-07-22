#include <cmath>
using namespace std;

const int maxn=200000;
int t,i,n,m,l,r,f[32][maxn];

int max(int x,int y)
{
	return (x>y)?(x):y;
}

void rmqchuli(int x)
{
	int i,j,t=(int)(log(x)/log(2));
	for (j=1;j<=t;j++)
		for (i=n-1<<j+1;i>=i;i--)
			f[i][j]=max(f[i][j-1],f[i+1<<(j-1)][j-1]);
}

int cha(int x,int y)
{
	int k;
	k=(int)(log(y-x+1)/log(2));
	return max(f[x][k],f[y-1<<k+1][k]);
}

