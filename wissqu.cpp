/*
ID: mfs.dev2
PROG: wissqu
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
ifstream inf("wissqu.in");
ofstream ouf("wissqu.out");
const long long  maxlongint=2147483647;

int i,j,k,m,n,t,mm,o,p;
int tu[5][5],c[10]={0,3,3,3,4,3},rr[20][2],bu[10][10][10];
bool fl,hash[5][5];
char ct;

void dfs(int x,int s,int e)
{
	int i,j,k,t;
	if (x>16)
	{
		if (!fl)
		{
			for (i=1;i<=16;i++)
				ouf<<(char)(tu[rr[i][0]][rr[i][1]]+64)<<' '<<rr[i][0]<<' '<<rr[i][1]<<endl;
			fl=true;
		}
		mm++;
		return;
	}
	for (k=s;k<=e;k++)
	{
		if (!c[k])
			continue;
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++)
			{
				if (hash[i][j])
					continue;
				if (!bu[k][i][j])
				{
					hash[i][j]=true;
					for (o=-1;o<=1;o++)
						for (p=-1;p<=1;p++)
						{
							bu[tu[i][j]][i+o][j+p]--;
							bu[k][i+o][j+p]++;
						}
					t=tu[i][j];
					tu[i][j]=k;
					c[k]--;
					rr[x][0]=i;rr[x][1]=j;
					dfs(x+1,1,5);
					hash[i][j]=false;
					for (o=-1;o<=1;o++)
						for (p=-1;p<=1;p++)
						{
						  bu[t][i+o][j+p]++;//back seq if tu[i][j] not t is wrong
							bu[k][i+o][j+p]--;
						}
					tu[i][j]=t;
					c[k]++;

				}
			}
	}

}
int main()
{
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
		{
			inf>>ct;
			tu[i][j]=ct-64;
			for (o=-1;o<=1;o++)
				for (p=-1;p<=1;p++)
				  bu[ct-64][i+o][j+p]++;
		}
	dfs(1,4,4);
	ouf<<mm<<endl;
}

