#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>

using namespace std;
ifstream inf("data.in");

int zushu,n,i,mm,k,t,tt;
double v;

int main()
{
	inf>>zushu;
	for (k=1;k<=zushu;k++)
	{
		inf>>n;
		mm=0;
		for (i=1;i<=n;i++)
		{
			inf>>t>>tt;
			(tt>mm)?(mm=tt):0;
		}
		v=sqrt(2*9.8*mm);
		printf("%.2lf\n",v);
	}
}
