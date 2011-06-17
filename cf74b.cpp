#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int i,j,k,n,m;
char tu[200][200];
int cc[300];
bool hang[300][300],lie[300][300];
string ss;

int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin>>tu[i][j];
	for (i=1;i<=n;i++)
	{
		memset(cc,0,sizeof(cc));
		for (j=1;j<=m;j++)
			cc[tu[i][j]]++;
		for (j='a';j<='z';j++)
			if (cc[j]>1)
				hang[i][j]=true;
	}
	for (i=1;i<=m;i++)
	{
		memset(cc,0,sizeof(cc));
		for (j=1;j<=n;j++)
			cc[tu[j][i]]++;
		for (j='a';j<='z';j++)
			if (cc[j]>1)
				lie[i][j]=true;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (hang[i][tu[i][j]]||lie[j][tu[i][j]])
				continue;
			ss.push_back(tu[i][j]);
		}
	cout<<ss<<endl;
	return 0;
}
