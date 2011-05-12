#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

int zushu,n,i,j,t,rr[2011],k,f[2011];

int main()
{
	f[0]=1;rr[0]=1;
	for (i=1;i<=2000;i++)
	{
		for (j=1;j<i;j++)
			f[j]=(f[j]%9997+f[j-1]%9997)%9997;
		rr[i]=f[i]=f[i-1];
	}
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		cin>>n;
		cout<<rr[n]<<endl;
	}
}


		
