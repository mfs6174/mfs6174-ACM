#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

long zi[50000],mu[50000],zit[50000],mut[50000],i,j,l,t,c,yin,rr;
//vector<double> zhi[50000];
double f,ff,mm,tt;


int gcd(int x,int y)
{
	int t;
	while (x%y)
	{
		t=x;
		x=y;
		y=t%y;
	}
	return y;
}

/*double abs(double x)
{
	if (x<0.0)
		return -x;
	else
		return x;
}*/

int main()
{
	cin>>f>>l;
	for (i=1;i<=l;i++)
	{
		ff=f*i;
		t=(int)(ff);
		if ((t>0)&&(t<=l))
		{
			c++;
			zi[c]=t;
			mu[c]=i;
			zit[c]=t/gcd(t,i);
			mut[c]=i/gcd(t,i);
		}
		if ((t+1<=l))
		{
			c++;
			zi[c]=t+1;
			mu[c]=i;
			zit[c]=(t+1)/gcd(t+1,i);
			mut[c]=i/gcd(t+1,i);
		}
	}
	mm=1e10;
	for (i=1;i<=c;i++)
	{
		tt=zit[i]/((double)(mut[i]));
		if (abs((double)(f-tt))<mm)
		{
			rr=i;
			mm=abs((double)(f-tt));
		}
	}
			
	/*yin=mut[1];
	for (i=2;i<=c;i++)
		yin=yin*mut[i]/gcd(yin,mut[i]);
		
	ff=yin*f;
	for (i=1;i<=c;i++)
	{
		zit[i]=zit[i]*(yin/mut[i]);
		if (abs((double)(ff-zit[i]))<mm)
		{
			rr=i;
			mm=abs((double)(ff-zit[i]));
		}
	}*/
	cout<<zi[rr]<<' '<<mu[rr]<<endl;
}

	
