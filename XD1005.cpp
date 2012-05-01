#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;
//ifstream inf("data.in");
//ofstream ouf("out.out");

int a,b,c,f[1010][1010],i,j,t,m,n,mm;
string r,jin;

int min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	while (cin>>a>>b>>c)
	{
		cin>>r>>jin;
		m=r.size();
		n=jin.size();
		//memset(f,0x00FFFFFF,sizeof(f));
		for (i=0;i<=m;i++)
		    for (j=0;j<=n;j++)
		        f[i][j]=2147483647;
        //for (i=0;i<=n;i++)
			f[0][0]=0;
		for (i=0;i<=m;i++)
			for (j=0;j<=n;j++)
			{	
				if (r[i]==jin[j])
					f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
				f[i+1][j]=min(f[i+1][j],f[i][j]+a);
				f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+c);
				f[i][j+1]=min(f[i][j+1],f[i][j]+b);
			}
		mm=2147483647;
		for (i=0;i<=n;i++)
			mm=min(mm,f[m][i]+b*(n-i));
		cout<<mm<<endl;
     }
}
		
			
		
