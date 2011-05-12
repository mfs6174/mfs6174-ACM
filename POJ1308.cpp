#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;

//ofstream outf("out.out");
const int maxn=5000;

int ff[maxn],dian[maxn],n=1,i,t,tt,m;
bool shi=true,you[maxn];

int cha(int x)//只有调用cha后的根才满足"性质" 
{
	if (!ff[x])
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
	cin>>t>>tt;
	while (t!=-1)
	{
		shi=true;
		memset(ff,0,sizeof(ff));
		memset(you,0,sizeof(you));
		m=0;
		while (t>0)
		{			
			if (!you[t])
			{
				you[t]=true;
				m++;
				dian[m]=t;
			}
			if (!you[tt])
			{
				you[tt]=true;
				m++;
				dian[m]=tt;
			}
			if (cha(t)==cha(tt))
				shi=false;
			bing(t,tt);
			cin>>t>>tt;
		}
		t=cha(dian[1]);
		for (i=2;i<=m;i++)
			if (cha(dian[i])!=t)
			{
				shi=false;
				break;
			}
		cout<<"Case "<<n<<" is "<<(shi?"a ":"not a ")<<"tree."<<endl;
		n++;
		cin>>t>>tt;
	}
}

		
