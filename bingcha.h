#include <iostream>
#include <fstream>

ofstream outf("out.out");
const int maxn=1000;

int ff[maxn],n,m,i,j,t,tt;

int cha(int x);
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(int x,int y);
{
	int i,j;
	i=cha(x);j=cha(y);
	if (i!=j)
	ff[i]=j;//总根为标志，把总根挂到另一个的总根下
}

int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
		ff[i]=i;
	for (i=1;i<=m;i++)
	{
		cin>>t>>tt;
		bing(t,tt);
	}
	cin>>m;
	for (i=1;i<=m;i+=)
	{
		cin>>t>>tt;
		outf<<(cha(t)==cha(tt));
	}
}

		
