#include <iostream>
//#include <fstream>
#include <cstring>
#include <cstdio>


using namespace std;
//ofstream ouf("out.out");
//ifstream inf("data.in");


struct jiedian{
		int n,dao[505];
		};
		
int zuo[505],i,j,dui[1010],nn,rr=0,zushu,k,n,m,t,chu[1010];
jiedian dian[505];
bool yong[1010];

bool xiong(int x)
{
	int i,tt;
	//进入的点都是左点
	for (i=1;i<=dian[x].n;i++)//遍历所连所有右点
	{
		tt=dian[x].dao[i];
		if ((!yong[tt])&&(dui[tt]!=x))//未重复出现且没有和此点匹配（保证交替1）
		{
			yong[tt]=true;
			if ((!dui[tt])||xiong(dui[tt]))//如果是未匹配点，可作为终点，否则顺着它匹配的左点找增广轨（保证交替2），如果找到：
			{
				dui[tt]=x;//连接左右，右与原匹配的边自动删除
				chu[x]=tt;
				return true;
			}
		}
	}
	return false;//木有找到增广轨
}

int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		memset(dian,0,sizeof(dian));
		memset(dui,0,sizeof(dui));
		memset(chu,0,sizeof(chu));
		rr=0;
		scanf("%d%d",&nn,&n);
		for (i=1;i<=nn;i++)
		{
			scanf("%d",&m);
			for (j=1;j<=m;j++)
			{
				scanf("%d",&t);
				dian[i].n++;
				dian[i].dao[dian[i].n]=t;
			}
		}
		/*if (n<nn)
		{
			cout<<"NO"<<endl;
			continue;
		}*/
		for (i=1;i<=nn;i++)
		{
			if (!chu[i])
			{
				memset(yong,0,sizeof(yong));
				if (xiong(i))//找到增广轨
					rr++;//匹配数+1
			}
		}
		if (rr==nn)
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
}
						
