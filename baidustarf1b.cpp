#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
using namespace std;
long m[100010],n;
long s[100010],shuu[100010],wei[100010][3],ans[100010],ys[100010],mmax,mmmax=0xfffffff,zui;

void daluan()
{
    bool can[100010];
    memset(can,0,sizeof(can));
    for(int i=0;i<=zui;i++)
        ys[i]=i;
    for(int i=0;i<=zui/2;i++)if(ys[i]==i){
        long temp=rand()%(zui+1);
        ys[i]=temp;ys[temp]=i;
    }
    return ;
}

int main()
{
    //freopen("ti1.in","r",stdin);
    //freopen("2","w",stdout);
    long i,j,k,l;
    scanf("%ld",&n);
n=n;
    for(i=0;i<n;i++){
        scanf("%ld",&m[i]);
        for(j=0;j<m[i];j++){
            scanf("%ld",s+j);
            if(shuu[s[j]]<3) wei[s[j]][shuu[s[j]]]=i;
            shuu[s[j]]++;
            if(zui<s[j]) zui=s[j];
        }
    }
    srand(time(NULL));
n=n;
    long cishu=600000/(zui+1)+1;
while(cishu>0){
    memset(ans,0,sizeof(0));
    daluan();
    for(i=0;i<=zui;i++){
        long ii=ys[i];
        if(shuu[ii]==1)
            ans[wei[ii][0]]+=2;

        else if(shuu[ii]==2){
            if(ans[wei[ii][0]]<ans[wei[ii][1]])
                ans[wei[ii][0]]++;
            if(ans[wei[ii][0]]==ans[wei[ii][1]] && m[wei[ii][0]]<m[wei[ii][1]])
                ans[wei[ii][0]]++;
            else ans[wei[ii][1]]++;
        }
        shuu[ii]=3;
    }
    for(i=0;i<=zui;i++)
        mmax=max(ans[i],mmax);
    cishu--;
    mmmax=min(mmmax,mmax);
}
    printf("%ld\n",mmmax);
    return 0;
}
