#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

struct jiedian
		{
			int qi,zhi,zuo,you;
			long long he,d;
		};

jiedian shu[450000];
int i,j,k,t,n,q,d=0,chu[150005],a,b;
long long rr=0;
char c;

int chushi(int x,int y)
{
	int t;
	t=++d;
	shu[t].qi=x;
	shu[t].zhi=y;
	shu[t].d=0;
	if (x==y)
	{
		shu[t].he=chu[x];
		shu[t].zuo=shu[t].you=0;
		return t;
	}
	shu[t].zuo=chushi(x,(x+y)/2);
	shu[t].you=chushi((x+y)/2+1,y);
	shu[t].he=shu[shu[t].zuo].he+shu[shu[t].you].he;
	return t;
}

int max(int x,int y)
{
	return (x>y)?x:y;
}

int min(int x,int y)
{
	return (x<y)?x:y;
}
	
void jia(int x,int m,int n,int z)
{
	int  t=(shu[x].qi+shu[x].zhi)/2;
	if (!z)
		return;
	if(m>n)
		return;
	if ((m<=shu[x].qi)&&(n>=shu[x].zhi))
	{
		shu[x].d+=z;
		return;
	}
	shu[x].he+=(min(shu[x].zhi,n)-max(shu[x].qi,m)+1)*z;
	if (n<=t)
	{
		jia(shu[x].zuo,m,n,z);
		return;
	}
	if (m>t)
	{
		jia(shu[x].you,m,n,z);
		return;
	}

	jia(shu[x].zuo,m,n,z);	
	jia(shu[x].you,m,n,z);
}


void cha(int x,int m,int n)
{
	int t=(shu[x].qi+shu[x].zhi)/2;
	if(m>n)
		return;
	if ((m<=shu[x].qi)&&(n>=shu[x].zhi))
	{
		rr+=shu[x].he+(shu[x].zhi-shu[x].qi+1)*shu[x].d;
		return;
	}
	rr+=(min(shu[x].zhi,n)-max(shu[x].qi,m)+1)*shu[x].d;
	if (n<=t)
	{
		cha(shu[x].zuo,m,n);
		return;
	}
	if (m>t)
	{
		cha(shu[x].you,m,n);
		return;
	}
	cha(shu[x].zuo,m,n);
	cha(shu[x].you,m,n);
}

/*void dayin()
{
	int i;
	for (i=1;i<=19;i++)
		ouf<<shu[i].qi<<' '<<shu[i].zhi<<' '<<shu[i].d<<endl;
	ouf<<endl;
}
*/	
int main()
{
	cin>>n>>q;
	for (i=1;i<=n;i++)
		scanf("%d",&chu[i]);
		//inf>>chu[i];
	chushi(1,n);
	for (i=1;i<=q;i++)
	{
		//inf>>c;
		scanf("%c%c",&c,&c);
		rr=0;
		if (c=='C')
		{
			//inf>>a>>b>>t;
			scanf("%d%d%d",&a,&b,&t);
			jia(1,a,b,t);
			//dayin();
			
		}
		else
		{
			//inf>>a>>b;
			scanf("%d%d",&a,&b);
			cha(1,a,b);
			cout<<rr<<endl;
		}
	}
}
