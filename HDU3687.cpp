#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include<cstring>

using namespace std;

const int maxlongint=2147483647;
int i,j,k,t,n,m,s,mm;
int wei[60][60];

inline int abs(int x)
{
	if (x<0)
		return -x;
	else
		return x;
}

int main()
{
	freopen("ti.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		memset(wei,0,sizeof(wei));
		for (i=1;i<=n*n;i++)
		{
			scanf("%d%d",&j,&k);
			wei[j][0]++;
			wei[j][wei[j][0]]=k;
		}
		for (i=1;i<=n;i++)
			sort(&(wei[i][1]),&(wei[i][n+1]));
		mm=maxlongint;
		for (i=1;i<=m-n+1;i++)
		{
			s=0;
			for (j=1;j<=n;j++)
				for (k=1;k<=n;k++)
					s+=abs(i+k-1-wei[j][k]);
			mm=min(s,mm);
		}
		cout<<mm<<endl;
	}
	return 0;
}
				
