#include<iostream>
//#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<sstream>

using namespace std;
//ifstream cin("data.in");
//ofstream ouf("out.out");
string ss;
int n,a,b,i,t,rr,tt,ttt;
//bool dengyu;

string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
}

class dashu{
	public:
		int a[350];
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

dashu shu,er;
 

int main()
{
	cin>>a>>b;
	for (i=1;i<=5;i++)
	{
		tt=1<<i;
		rr=0;
		if (i<a)
			continue;
		(tt>10)?(ttt=tt/10):(ttt=tt);
		if (ttt==b)
		{
			rr=i;
			break;
		}
	}
	if (rr==0)
	{
		er.zhuan("2");
		ss=str(tt<<1);
		shu.zhuan(ss);
		for (i=6;i<=62;i++)
		{
			if ((shu.a[shu.a[0]]==b)&&(i>a))
			{
				rr=i;
				break;
			}
			shu=cheng(shu,er);
		}
	}
	cout<<rr<<endl;
}
