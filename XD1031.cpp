#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ofstream outf("out.out");
ifstream inf("data.in");

int zushu,n,qi,zhi,i,j,he,shu[101],k,t;

int main()
{
	inf>>zushu;
	for (k=1;k<=zushu;k++)
	{
		memset(shu,0,sizeof(shu));
		inf>>n>>qi>>zhi;
		for (i=1;i<=n-1;i++)
			inf>>shu[i];
		(qi>zhi)?((j=-1),(t=-1)):((j=1),(t=0));
		if (qi==zhi)
		{
			outf<<0<<endl;
			continue;
		}
		he=0;
		for (i=qi;i!=zhi;i+=j)
			he+=shu[i+t];
		outf<<he<<endl;
	}
	return 0;
}
