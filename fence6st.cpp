/*
	ID:echooat1
	LANG:C++
	TASK:fence6
	*/
#include <fstream>
#include <cstring>
#include <climits>
using namespace std;
ifstream fin("fence6.in");
ofstream fout("fence6.out");
long a[303][303]={0},n=0,m=0,l[303]={0},ans=LONG_MAX,y=0;
bool hash[303]={false},kk[303]={0};
void dfs(long goal,long u,long t){
	if(goal==u){
		if(y<ans)ans=y;
			return;
	}
	if(y>=ans)return;
	for(long i=1;i<=n;i++)
		if(!hash[i]&&!kk[i]&&a[u][i]==3-t){
			kk[i]=true;
			y+=l[i];
			dfs(goal,i,a[i][u]);
			y-=l[i];
			kk[i]=false;
		}
}
int main(int argc,char** argv){
	fin >>n;
	for(long i=1;i<=n;i++){
		long temp,l1,l2;
		fin >>temp;fin >>l[temp]>>l1>>l2;
		for(long j=1;j<=l1;j++){
			long p=0;fin >>p;
			a[temp][p]=1;
		}
		for(long j=1;j<=l2;j++){
			long p=0;fin >>p;
			a[temp][p]=2;
		}
	}
	for(long i=1;i<=n;i++){
		y=0;
		memset(kk,0,sizeof kk);
		for(long j=1;j<=n;j++)
			if(a[i][j]==1&&!hash[j]){
				kk[j]=true;
				y+=l[j];
				dfs(i,j,a[j][i]);
				kk[j]=false;
				y-=l[j];
			}
		hash[i]=true;
}
	fout <<ans<<endl;
	fin.close();fout.close();
	return 0;
}
