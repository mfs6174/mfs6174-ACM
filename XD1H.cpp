#include<iostream>
//#include<fstream>
#include<cstring>
#include <string>
#include <cstdio>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

const ling=0.000001;
int a[3],b[3],c[3],i,j,k,zushu
double aa,bb,cc;
bool ff=false;

double abs(double x)
{
	if (x<0)
		return -x;
	else
		return x;
}

double min(double x,double y)
{
	if (x>y)
		return y;
	else
		return x;
}


int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		cin>>a[1]>>b[1]>>c[1]>>a[2]>>b[2]>>c[2];
		aa=a[2]-a[1];
		bb=b[2]-b[1];
		cc=c[2]-c[1];
		if ((aa==0)&&(bb==0)&&(cc==0))
		{
			continue;
		}
		if (cc==0)
		{
			continue;
		}
		
		if (abs(aa)<ling)
		{
			
		
		
		