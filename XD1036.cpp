#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ofstream ouf("out.out");
ifstream inf("data.in");

int zushu,i,j,n,f[102][102],k;

int main()
{
	inf>>zushu;
	for (k=1;k<=zushu;k++)
	{
		inf>>n;
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
			f[i][0]=1;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				f[i][j]=f[i-1][j];
				if (j>=i)
					f[i][j]+=f[i][j-i];
			}
		ouf<<f[n][n]<<endl;
	}
}

		
