/*
ID: mfs.dev2
PROG: fence9
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
ifstream inf("fence9.in");
ofstream ouf("fence9.out");

int m,p,mm,i,t,tt,n;
double k,kk,b,bb;

int  suan(double k,double b,int y,int o)
{
	int t;
	t=(int)((y-b)/k);
	if (((y-b)/k-t<1e-7)&&o)
		t--;
	if (!o)
		t++;
	return t;
}

int main()
{
	inf>>n>>m>>p;
	b=0;
	if (n)
		k=(double)m/n;
	else
		k=-1;
	if (n-p)
		kk=(double)m/(n-p);
	bb=-kk*p;
	for (i=1;i<m;i++)
	{
		if (k!=-1)
			t=suan(k,b,i,0);
		else
			t=1;
		if (kk)
			tt=suan(kk,bb,i,1);
		else
			tt=p-1;
		mm+=tt-t+1;
	}
	ouf<<mm<<endl;
	return 0;
}



