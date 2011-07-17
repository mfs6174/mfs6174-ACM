 /*
ID: mfs6174
PROG: XDOJ1118
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,m,n,xx,yy,t,zz,zu,mm;
int f[1010][1010],shu[15][4];

int mfs(int x,int y)
{
	int i;
    if (x<=0||y<=0)
      return 0;
	if (f[x][y]!=-1)
      return f[x][y];
    f[x][y]=0;
    for (i=1;i<=n;i++)
    {
      if (x>=shu[i][0]&&y>=shu[i][1])
      {
        f[x][y]=max(f[x][y],mfs(x-shu[i][0],y)+mfs(shu[i][0],y-shu[i][1])+shu[i][2]);
        f[x][y]=max(f[x][y],mfs(x-shu[i][0],shu[i][1])+mfs(x,y-shu[i][1])+shu[i][2]);
      }
      if (x>=shu[i][1]&&y>=shu[i][0])
      {
        f[x][y]=max(f[x][y],mfs(x-shu[i][1],y)+mfs(shu[i][1],y-shu[i][0])+shu[i][2]);
        f[x][y]=max(f[x][y],mfs(x-shu[i][1],shu[i][0])+mfs(x,y-shu[i][0])+shu[i][2]);
      }
    }
    return f[x][y];
}
      
		
int main()
{
	cin>>zu;
	for (zz=1;zz<=zu;zz++)
	{
		memset(f,-1,sizeof(f));
		cin>>n>>xx>>yy;
		if (xx>yy)
		{
			t=xx;
			xx=yy;
			yy=t;
		}
		for (i=1;i<=n;i++)
		{
			cin>>shu[i][0]>>shu[i][1]>>shu[i][2];
			if (shu[i][0]>shu[i][1])
			{
				shu[i][3]=shu[i][0];
				shu[i][0]=shu[i][1];
				shu[i][1]=shu[i][3];
			}
		}
		mm=mfs(xx,yy);
		cout<<mm<<endl;
	}
	return 0;
}

		
