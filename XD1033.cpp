#include <iostream>
//#include <fstream>

using namespace std;
//ofstream ouf("out.out");
//ifstream inf("data.in");

struct danyuan{
		int x,y,s;
	};
	
int zushu,i,j,k,zhan[16][30],shu[7],ge[50][6],she,r,n;
bool jie[50],dang[50],cheng;
danyuan kai[6],t;

void chuli(int x,int y,int hao)
{
	int t;
	if ((x<1)||(x>16)||(y<1)||(y>30))
		return;
	if (zhan[x][y]==-1)
		return;
	if (!zhan[x][y])
	{
		she++;
		ge[she][0]=1;
		ge[she][1]=hao;
		zhan[x][y]=she;
	}
	else
	{
		t=zhan[x][y];
		ge[t][0]++;
		ge[t][ge[t][0]]=hao;
	}
}

void dfs(int x)
{
	int i;
	if (x>she)
	{
		bool ff=true;
		for (i=1;i<=n;i++)
			ff=ff&&(shu[i]==kai[i].s);
		if (ff)
		{
			for (i=1;i<=she;i++)
				jie[i]=jie[i]&&dang[i];
			cheng=true;
		}
		return;
	}
	dfs(x+1);
	dang[x]=true;
	for (i=1;i<=ge[x][0];i++)
		//if ((++shu[ge[x][i]])>kai[ge[x][i]].s)
		shu[ge[x][i]]++;
			//dang[x]=false;
	if (dang[x])
		dfs(x+1);
	dang[x]=false;
	for (i=1;i<=ge[x][0];i++)
		--shu[ge[x][i]];
}
			
		
int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		memset(zhan,0,sizeof(zhan));
		memset(shu,0,sizeof(shu));
		memset(dang,0,sizeof(dang));
		memset(ge,0,sizeof(ge));
		cheng=false;
		she=0;r=0;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>kai[i].x>>kai[i].y>>kai[i].s;
			zhan[kai[i].x][kai[i].y]=-1;
		}
		/*for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++)
				if (kai[j].s<kai[i].s)
				{
					t=kai[i];
					kai[i]=kai[j];
					kai[j]=t;
				}
		*/
		for (i=1;i<=n;i++)
		{
			for (j=-1;j<=1;j++)
			{
				chuli(kai[i].x-1,kai[i].y+j,i);
				chuli(kai[i].x+1,kai[i].y+j,i);
			}
			chuli(kai[i].x,kai[i].y+1,i);chuli(kai[i].x,kai[i].y-1,i);
		}
		for (i=1;i<=she;i++)
			jie[i]=true;
		dfs(1);
		r=0;
		for (i=1;i<=she;i++)
			if (jie[i])
				r++;
		if (!cheng)
			cout<<0<<endl;
		else
			cout<<r<<endl;
	}
}
