#include<iostream>
//#include<fstream>
#include<cstring>
#include <string>
#include <cstdio>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

int i,j,n,m,t,zushu,k,l,a,b;
unsigned xian[1005],zhi[10];
char shu[9]={'w','r','b','p','y','o','g','k'};
string tt;



int main()
{
	for (i=1;i<=3;i++)
		zhi[i]=1<<(i-1);
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		memset(xian,0,sizeof(xian));
		cin>>n>>m>>l;
		for (i=1;i<=m;i++)
		{
			//scanf("%d%d%d",&a,&b,&tt);
			cin>>a>>b>>tt;
			if (a>b)
			{
				t=a;
				a=b;
				b=t;
			}
			if (tt=="r")
				t=1;
			if (tt=="b")
				t=2;
			if (tt=="y")
				t=3;
			for (j=a;j<=b;j++)
				xian[j]=xian[j]|zhi[t];
		}
		for (i=1;i<=l;i++)
		{
			cin>>a;
			cout<<shu[xian[a]]<<endl;
		}
		cout<<endl;
	}
}

		
