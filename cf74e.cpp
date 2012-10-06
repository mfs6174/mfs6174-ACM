#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct D
{
	short z,y,s,x;
};

int i,j,k,n,m,t,mm,cc;
char tu[5000][5000];
D dui[5000][5000];

void mfs(int x,int y)
{
	if (tu[i][j]=='.')
		return;
	int c=0;
	while (x>0&&y>0)
	{
		c++;
		if (dui[x][y].z==0)
			dui[x][y].z=y-1;
		if (dui[x][y].y==0)
			dui[x][y].y=y+1;
		if (dui[x][y].s==0)
			dui[x][y].s=x-1;
		if (dui[x][y].x==0)
			dui[x][y].x=x+1;
		if (dui[x][y].z>0)
			dui[x][dui[x][y].z].y=dui[x][y].y;
		if (dui[x][y].y>0)
			dui[x][dui[x][y].y].z=dui[x][y].z;
		if (dui[x][y].s>0)
			dui[dui[x][y].s][y].x=dui[x][y].x;
		if (dui[x][y].x>0)
			dui[dui[x][y].x][y].s=dui[x][y].s;
		if (tu[x][y]=='L')
		{	
			y=dui[x][y].z;
			while (tu[x][y]=='.')
			{
				if (dui[x][y].z==0)
					dui[x][y].z=y-1;
				y=dui[x][y].z;	
				if (y<1)
					break;
			}
		} else
		if (tu[x][y]=='R')
		{	
			y=dui[x][y].y;
			while (tu[x][y]=='.')
			{
				if (dui[x][y].y==0)
					dui[x][y].y=y+1;
	y=dui[x][y].y;
				if (y>m)
				{
					y=-1;
					break;
				}
			}
		} else
		if (tu[x][y]=='U')
		{	
			x=dui[x][y].s;
			while (tu[x][y]=='.')
			{
					if (dui[x][y].s==0)
					dui[x][y].s=x-1;
				x=dui[x][y].s;

				if (x<1)
					break;
			}
		} else
		if (tu[x][y]=='D')
		{	
			x=dui[x][y].x;

			
			while (tu[x][y]=='.')
			{
					if (dui[x][y].x==0)
					dui[x][y].x=x+1;
				x=dui[x][y].x;
				if (x>n)
				{
					x=-1;
					break;
				}
			}
		}
	}
	if (c>mm)
	{
		mm=c;
		cc=1;
	}
	else if (c==mm)
		cc++;
}

int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>tu[i][j];
			dui[i][j].z=j-1;
			dui[i][j].y=j+1;
			dui[i][j].s=i-1;
			dui[i][j].x=i+1;
		}
	t=max(n,m);	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			memset(dui,0,sizeof(dui));
			for (k=1;k<=t;k++)
			{
				dui[1][k].s=-1;
				dui[n][k].x=-1;
				dui[k][1].z=-1;
				dui[k][m].y=-1;
			}
			mfs(i,j);
		}
	cout<<mm<<' '<<cc<<endl;
	return 0;
}
