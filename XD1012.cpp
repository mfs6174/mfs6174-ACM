#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

int f[100005],n,a,b,i,j,t;
bool fl=false;

int min(int x,int y,bool &z)
{
	if (x>y)
	{
		z=true;
		return y;
	}
	return x;
}

int main()
{
	while (cin>>a>>b)
	{
		for (i=a+1;i<=b;i++)
			f[i]=2147483647;
		f[a]=0;
		do
		{
			fl=false;
			for (i=a+1;i<=b;i++)
			{
				f[i]=min(f[i],f[i-1]+1,fl);
				if (!(i&1))
					if (i/2>=a)
						f[i]=min(f[i],f[i/2]+1,fl);
					else
						f[i]=min(f[i],a-i/2+1,fl);
				if (i*2>b)
					f[b]=min(f[b],f[i]+i*2-b+1,fl);
			}
			for (i=b-1;i>a;i--)
			{
				f[i]=min(f[i],f[i+1]+1,fl);
				if (i*2>b)
					f[b]=min(f[b],f[i]+i*2-b+1,fl);
			}
		}
		while (fl);
		cout<<f[b]<<endl;
	}
}

		
