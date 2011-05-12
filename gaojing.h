#include<iostream>
//#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
//ifstream cin("data.in");
//ofstream cout("out.out");
string ss;
int n;
bool dengyu;

class dashu{
	public:
		int a[160];
		void zhuan(string x)
		{
			int i;
			memset(a,0,sizeof(a));
			a[0]=x.size();
			for (i=1;i<=a[0];i++)
				a[i]=x[a[0]-i]-48;
		}
		bool xiaoyu(dashu &x,bool &ff)
		{
			int i;
			ff=false;
			if (a[0]<x.a[0])
				return true;
			else if (a[0]>x.a[0])
					return false;
			for (i=a[0];i>=1;i--)
				if (a[i]<x.a[i])
					return true;
				else if (a[i]>x.a[i])
						return false;
			ff=true;
			return false;
		}
				
		void dayin(int x)
		{
			int i,t;
			for (t=1;a[t]==0;t++);
			if (!x)
				t=1;
			if (a[0]<x)
			{
				cout<<'.';
				for (i=1;i<=x-a[0];i++)
					cout<<'0';
			}
			for (i=a[0];i>=t;i--)
			{
				if (i==x)
					cout<<'.';
				cout<<a[i];
			}
			cout<<endl;
		}
	};
	
dashu cheng(dashu &x,dashu &y)
		{
			int i,j;
			dashu rr;
			memset(rr.a,0,sizeof(rr.a));
			rr.a[0]=x.a[0]+y.a[0];
			for (i=1;i<=x.a[0];i++)
				for (j=1;j<=y.a[0];j++)
				{
					rr.a[i+j-1]+=x.a[i]*y.a[j];
					rr.a[i+j]+=rr.a[i+j-1]/10;
					rr.a[i+j-1]=rr.a[i+j-1]%10;
				}
			if (rr.a[rr.a[0]+1]!=0)
				rr.a[0]++;
			while ((rr.a[rr.a[0]]==0)&&(rr.a[0]>1))
				rr.a[0]--;
			return rr;
		}
dashu jia(dashu &x,dashu &y)
{
	int i;
	dashu rr;
	memset(rr.a,0,sizeof(rr.a));
	rr.a[0]=(x.a[0]>y.a[0])?(x.a[0]):(y.a[0]);
	for (i=1;i<=rr.a[0];i++)
	{
		rr.a[i]+=x.a[i]+y.a[i];
		if (rr.a[i]>9)
		{
			rr.a[i+1]++;
			rr.a[i]-=10;
		}
	}
	if (rr.a[rr.a[0]+1]!=0)
		rr.a[0]++;
	return rr;
}

dashu jian(dashu &x,dashu &y)
{
	int i;
	dashu rr;
	memset(rr.a,0,sizeof(rr.a));
	rr.a[0]=x.a[0];
	for (i=1;i<=rr.a[0];i++)
	{
		if (x.a[i]<y.a[i])
		{
			rr.a[i+1]--;
			rr.a[i]+=10;
		}
		rr.a[i]+=x.a[i]-y.a[j];
	}
	while ((rr.a[rr.a[0]]==0)&&(rr.a[0]>1))
		rr.a[0]--;
	return rr;
}	

int main()
{
}
