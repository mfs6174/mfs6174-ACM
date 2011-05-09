/*
ID: mfs.dev2
PROG: snail
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
ifstream inf("snail.in");
ofstream ouf("snail.out");
const long long  maxlongint=2147483647;

int n,m,i,j,k,t,mm;
bool tu[200][200],hash[200][200];
int zou[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
char d;

void dfs(int x,int y,int z,int l)
{
	int i,xx,yy;
	if (l>mm)
		mm=l;	
	if (hash[x][y])
		return;
	xx=x+zou[z][0];
	yy=y+zou[z][1];
	hash[x][y]=true;
	if (tu[xx][yy])
	{
		for (i=0;i<4;i++)
			if (!tu[x+zou[i][0]][y+zou[i][1]])
				dfs(x+zou[i][0],y+zou[i][1],i,l+1);
	}
	else
		dfs(xx,yy,z,l+1);
	hash[x][y]=false;
}

int main()
{
	inf>>n>>m;
	for (i=1;i<=m;i++)
	{
		inf>>d>>t;
		tu[d-64][t]=true;
	}
	for (i=1;i<=n;i++)
	{
		tu[i][0]=true;
		tu[i][n+1]=true;
		tu[0][i]=true;
		tu[n+1][i]=true;
	}
	dfs(1,1,0,0);
	dfs(1,1,1,0);
	ouf<<mm<<endl;
}

