#include <iostream>
#include <string>

using namespace std;

int n,i,rr;
string s,ss,sss;

int main()
{
	while (cin>>n)
	{
		cin>>s>>ss>>sss;
		rr=0;
		for (i=0;i<n;i++)
		{
			if ((ss[i]==sss[i]))
			{
				if (s[i]!=ss[i])
					rr+=2;
				continue;
			}
		rr++;
		}	
		cout<<rr<<endl;
	}
}

	
			
					
					

