#include<iostream>
//#include<fstream>
#include<cstring>


using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

struct dian{
		int ru,chu,dao[20];
		};
		
int i,j,n,t,m,zhi[20],tt,biao[20],rr,mm;
dian guo[20];
bool yong[20],jie[20];


void dfs(int xx)
{
	int i,t,tt,x;
	bool tyong[20];
	x=biao[xx];
	if (xx>n)
	{
		if (rr>mm)
		{
			mm=rr;
			for (i=1;i<=n;i++)
				jie[i]=yong[i];
		}
		return;
	}
	tt=rr;
	for (i=1;i<=n;i++)
		tyong[i]=yong[i];
	if (yong[x])
	{
		for (i=1;i<=guo[x].chu;i++)
		{
			t=guo[x].dao[i];
			if (yong[t]==false)
			{
				rr+=zhi[t];
				yong[t]=true;
			}
		}
		dfs(xx+1);
		for (i=1;i<=n;i++)
			yong[i]=tyong[i];
		rr=tt;
		return;
	}

		
	dfs(xx+1);
	rr+=zhi[x];
	yong[x]=true;
	for (i=1;i<=guo[x].chu;i++)
		{
			t=guo[x].dao[i];
			if (yong[t]==false)
			{
				rr+=zhi[t];
				yong[t]=true;
			}
		}

	dfs(xx+1);
	yong[x]=false;
	rr=tt;
	for (i=1;i<=n;i++)
		yong[i]=tyong[i];
}
	
int main()
{
	while (cin>>n)
	{
		memset(guo,0,sizeof(guo));
		for (i=1;i<=n;i++)
		{
			cin>>zhi[i]>>guo[i].chu;
			for (j=1;j<=guo[i].chu;j++)
			{
				cin>>guo[i].dao[j];
				guo[guo[i].dao[j]].ru++;
			}
		}
		t=0;
		memset(yong,false,sizeof(yong));
		while (t<n)
			for (i=1;i<=n;i++)
				if ((guo[i].ru==0)&&(!yong[i]))
				{
					t++;
					biao[t]=i;
					yong[i]=true;
					for(j=1;j<=guo[i].chu;j++)
						guo[guo[i].dao[j]].ru--;
				}
		rr=0;
		mm=0;
		memset(yong,false,sizeof(yong));
		memset(jie,false,sizeof(jie));
		dfs(1);
		cout<<mm<<endl;
		if (mm!=0)
		{
			for (i=1;i<n;i++)
				if (jie[i])
					cout<<i<<" ";
			if (jie[n])
				cout<<n<<endl;
		}
		else
		cout<<0<<endl;
	}
}

			
				
		
		
			
				
				
