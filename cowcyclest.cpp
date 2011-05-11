/*
ID: cmykrgb1
PROG: cowcycle
LANG: C++
*/
//written by CmYkRgB123
#include <iostream>
#include <fstream>
#include<cstring>
#define MAX 11
using namespace std;
ifstream fi("cowcycle.in");
ofstream fo("cowcycle.out");
 
int s1[MAX],s2[MAX],ans1[MAX],ans2[MAX];
int F,R,F1,F2,R1,R2,cnt;
double rate[MAX*MAX],diff[MAX*MAX],minvf=0x7FFFFFFF;
 
void init()
{
	fi >> F >> R >> F1 >> F2 >> R1 >> R2;
	cnt=F*R;
}
 
void count()
{
	int i,j,k=0,l;
	double sum=0,avg,vf=0,sumf=0,p;
	for (i=1;i<=F;i++)
		for (j=1;j<=R;j++)
		{
			p=(double)s1[i]/s2[j];
			l=++k;
			while (rate[l-1]>=p)
			{
				rate[l]=rate[l-1];
				l--;
			}
			rate[l]=p;
		}
	for (i=1;i<=cnt-1;i++)
	{
		diff[i]=rate[i+1]-rate[i];
		sum+=diff[i];
		sumf+=diff[i]*diff[i];
	}
	avg=sum/(cnt-1);
	vf=sumf-sum*avg;
	if (vf<minvf)
	{
		minvf=vf;
		memcpy(ans1+1,s1+1,sizeof(int)*F);
		memcpy(ans2+1,s2+1,sizeof(int)*R);
	}
}
 
void sc2(int k,int w)
{
	int i;
	if (k==R+1)
	{
		if (s1[F]*s2[R]<3*s1[1]*s2[1])
			return;
		count();
		return;
	}
	for (i=w;i<=(R2-(R-k));i++)
	{
		s2[k]=i;
		sc2(k+1,i+1);
	}
}
 
void sc1(int k,int w)
{
	int i;
	if (k==F+1)
	{
		sc2(1,R1);
		return;
	}
	for (i=w;i<=(F2-(F-k));i++)
	{
		s1[k]=i;
		sc1(k+1,i+1);
	}
}
 
void print()
{
	int i;
	for(i=1;i<=F-1;i++)
		fo << ans1[i] << ' ';
	fo << ans1[F] << endl;
	for(i=1;i<=R-1;i++)
		fo << ans2[i] << ' ';
	fo << ans2[R] << endl;
	fi.close();
	fo.close();
}
 
int main()
{
	init();
	sc1(1,F1);
	print();
	return 0;
}
