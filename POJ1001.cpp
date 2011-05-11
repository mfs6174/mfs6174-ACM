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
			while (rr.a[rr.a[0]]==0)
				rr.a[0]--;
			return rr;
		}

int main()
{
	while (cin>>ss)
	{
		dashu shu,r;
		int lingshu=0,dian=0,i=0;
		bool ff=false,fff=false;
		cin>>n;
		for (i=ss.size()-1;i>=0;i--)
		{
			if ((!ff)&&(ss[i]=='0'))
				lingshu++;
			if ((!ff)&&(ss[i]!='0'))
				ff=true;
			if ((!fff)&&(ss[i]!='.'))
				dian++;
			if ((!fff)&&(ss[i]=='.'))
				fff=true;
		}
		if (dian>=ss.size())
		{
			dian=0;
			if (ss.find('.')!=string::npos)
				ss.erase(ss.find('.'));
		}
		else
		{
			ss.erase(ss.end()-dian-1);
			if (lingshu)
				ss.erase((ss.end()-lingshu),ss.end());
			dian-=lingshu;
		}
		while (*(ss.begin())=='0')
			ss.erase(ss.begin());
		if (ss.size()==0)
		{
			cout<<0<<endl;
			continue;
		}
		shu.zhuan(ss);
		r.zhuan(ss);
		if (n==1)
		{
			shu.dayin(dian);
			continue;
		}
		for (i=2;i<=n;i++)
		{
			r=cheng(r,shu);
		}
		r.dayin(dian*n);
	}
	return 0;
}
