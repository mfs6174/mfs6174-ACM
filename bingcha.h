#include <iostream>
#include <fstream>

const int MAXN=1000;

int ff[MAXN],n,m,i,j,t,tt;

void init(int n)
{
  int i;
  for (i=1;i<=n;i++)
    ff[i]=i;
}

int cha(int x)
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(int x,int y)
{
	int i,j;
	i=cha(x);j=cha(y);
	if (i!=j)
	ff[i]=j;//总根为标志，把总根挂到另一个的总根下
}

int main()
{
  return 0;
}

		
