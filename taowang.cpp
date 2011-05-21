#include<fstream>
#include<queue>
#include<cstring>
using namespace std;
ifstream cin("1");
ofstream cout("2");
struct node
{
    int x,y,step;
    bool key[15];
}now,temp;
queue<struct node> q;
char g[25][25];
int m,n,t,x,y,ans;
bool can[50000000],ok=0;
int suan(struct node a)
{
    int n=1;
    for(int i=1;i<=26;i++)
        if(a.key[i]) n+=i;
    return n*a.x*a.y;
}
int main()
{
    int i,j,k,l=0;
    while(cin>>n>>m>>t){
        memset(g,0,sizeof(g));
        memset(can,0,sizeof(can));
        ok=0;l++;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                cin>>g[i][j];
                if(g[i][j]=='@'){
                    now.x=i;now.y=j;g[i][j]='.';
                    q.push(now);
                }
            }
        while(!q.empty()){
            now=q.front();
            q.pop();
            if(g[i][j]=='^'){
                ans=now.step;ok=1;break;
            }
            if(now.step>t) continue;
            if(now.x-1>0 && !(g[now.x-1][now.y]=='*'|| (g[now.x-1][now.y]>='A' && g[now.x-1][now.y]<='Z' && !now.key[g[now.x-1][now.y]-63]))){
                temp=now;temp.x-=1;temp.step+=1;
                if(g[temp.x][temp.y]<='z' && g[temp.x][temp.y]>='a')
                    temp.key[g[temp.x][temp.y]-95]=1;
                if(!can[(t=suan(temp))]){
                    can[t]=1;
                    q.push(temp);
                }
            }
            if(now.x+1<=n && !(g[now.x+1][now.y]=='*' || (g[now.x+1][now.y]>='A' && g[now.x+1][now.y]<='Z' && !now.key[g[now.x+1][now.y]-63]))){
                temp=now;temp.x+=1;temp.step+=1;
                if(g[temp.x][temp.y]<='z' && g[temp.x][temp.y]>='a')
                    temp.key[g[temp.x][temp.y]-95]=1;
                if(!can[(t=suan(temp))]){
                    can[t]=1;q.push(temp);
                }
            }
            if(now.y-1>0 &&!(g[now.x][now.y-1]=='*' || (g[now.x][now.y-1]>='A' && g[now.x][now.y-1]<='Z' && !now.key[g[now.x][now.y-1]-63]))){
                temp=now;temp.y-=1;temp.step+=1;
                if(g[temp.x][temp.y]<='z' && g[temp.x][temp.y]>='a')
                    temp.key[g[temp.x][temp.y]-95]=1;
                if(!can[(t=suan(temp))]){
                    can[t]=1;q.push(temp);
                }
            }
            if(now.y+1<=m &&!(g[now.x][now.y+1]=='*' || (g[now.x][now.y+1]>='A' && g[now.x][now.y+1]<='Z' && !now.key[g[now.x][now.y+1]-63]))){
                temp=now;temp.y+=1;temp.step+=1;
                if(g[temp.x][temp.y]<='z' && g[temp.x][temp.y]>='a')
                    temp.key[g[temp.x][temp.y]-95]=1;
                if(!can[(t=suan(temp))]){
                    can[t]=1;q.push(temp);
                }
            }
        }
        if(ok==1) cout<<"Case "<<l<<": "<<ans<<endl;
        else cout<<"Case "<<l<<": -1"<<endl;
    }
    return 0;
}
