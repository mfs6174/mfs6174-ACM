#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int zushu,i,n,k,shu[20000],l,he;
string ss;

int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		cin>>ss;
		l=ss.size();
		he=0;
		memset(shu,0,sizeof(shu));
		for (i=0;i<l;i++)
		{
			shu[i+1]=ss[i]-48;
			he+=shu[i+1];
		}
		if (he==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		n=he%3;
		if (n==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

		
			
