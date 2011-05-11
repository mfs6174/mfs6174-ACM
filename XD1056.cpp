#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

int zushu,i,j,k;
double a[3],b[3],c[3],dd,mm,ling=1e-9,tt,t,aa,bb,cc,jie,ttt;

double suan(int t,double x)
{
	return a[t]*x*x+b[t]*x+c[t];
}

double max(double x,double y)
{
	return (x>y)?(x):(y);
}

double min(double x,double y)
{
	return (x<y)?(x):(y);
}

int main()
{
	cin>>zushu;
	for (k=1;k<=zushu;k++)
	{
		mm=1e100;
		for (i=0;i<=1;i++)
			cin>>a[i]>>b[i]>>c[i];
		mm=min(mm,max(suan(1,0.),suan(0,0.)));
		mm=min(mm,max(suan(1,1000.),suan(0,1000.)));
		for (i=0;i<=1;i++)
			if (abs(a[i])>=ling)
			{
				t=(4*a[i]*c[i]-b[i]*b[i])/4.0/a[i];
				ttt=(-b[i])/2.0/a[i];
				if ((ttt>0)&&(ttt<1000))
				{
					tt=suan(1-i,ttt);
					mm=min(mm,max(t,tt));
				}
			}
		
		aa=a[0]-a[1];
		bb=b[0]-b[1];
		cc=c[0]-c[1];
		if (abs(aa)<ling)
		{
			if (abs(bb)>=ling)
			{
				jie=(-cc)/bb;
				if ((jie>0)&&(jie<1000))
					mm=min(mm,max(suan(0,jie),suan(1,jie)));
			}
		}
		else
		{
			dd=bb*bb-4*aa*cc;
			if (abs(dd)<ling)
			{
				tt=(-bb)/2.0/aa;
				if ((tt>0)&&(tt<1000))
					mm=min(mm,max(suan(0,tt),suan(1,tt)));
			}
			else
			if (dd>0)
			{
				tt=(-bb+sqrt(dd))/2.0/aa;
				if ((tt>0)&&(tt<1000))
					mm=min(mm,max(suan(0,tt),suan(1,tt)));
				tt=(-bb-sqrt(dd))/2.0/aa;
				if ((tt>0)&&(tt<1000))
					mm=min(mm,max(suan(0,tt),suan(1,tt)));
			}
		}
		printf("%.4lf\n",mm);
	}
}

	
				
