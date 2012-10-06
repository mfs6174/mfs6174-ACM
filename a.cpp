#include<cstdio>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream cin("1");
ofstream cout("2");
int t,m,n;
char g[60][60];
bool ff;

int main()
{
    int i,j,k,l;
    cin>>t;
    for(l=0;l<t;l++){
        cin>>m>>n;
        ff=0;
        cout<<"Case #"<<l+1<<":"<<endl;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                cin>>g[i][j];
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
            if(g[i][j]=='#'){
                if(i+1<=m && j+1<=n && g[i][j+1]=='#' && g[i+1][j]=='#' && g[i+1][j+1]=='#'){
                    g[i][j]='/';g[i][j+1]='\\';g[i+1][j]='\\';g[i+1][j+1]='/';
                }
                else {
                    ff=1;cout<<"Impossible"<<endl;break;
                }
            }
            if(ff) break;
            }
            if(ff) break;
        }
        if(!ff)
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++)
            if(g[i][j]=='#'){
                cout<<"Impossible"<<endl;ff=1;break;
            }
            if(ff) break;
        }
        if(!ff) for(i=1;i<=m;i++){
            for(j=1;j<=n;j++)
                cout<<g[i][j];
            cout<<endl;
        }
    }
    return 0;
}
