#include<iostream>

#include<cmath>

using namespace std;

int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};

int n,i,temp,a[1000]={0},j,ans[10000],c[10000],b[10000],t[10000];

void chenggao(int a[],int b[])

{

     int i,c[10000]={0},j;

     for(i=1;i<=a[0];i++)

       for( j=1;j<=b[0];j++)c[i+j-1]+=a[i]*b[j];

     c[0]=a[0]+b[0];

     for( i=1;i<=c[0];i++)

     {

          c[i+1]+=c[i]/10;

          c[i]%=10;

          }

     while(c[c[0]]==0&&c[0]>0)c[0]--;

     memcpy(a,c,sizeof(c));

}

void print(int a[])

{

     if(a[0]==0){cout<<0<<endl;return;}

     for(int i=a[0];i>0;i--)cout<<a[i];

     cout<<endl;

}

double pro(int x,int y)
{
     double ans=x,t=x;
     int c[100],i;c[0]=0;
     while(y!=0){c[++c[0]]=y%2;y/=2;}
     for( i=c[0]-1;i>=1;i--)
     {
          ans*=ans;
          if(c[i]==1)ans*=t;
          }
     return ans;
}

void clean()

{

     int i,j;

     for( i=1;i<=a[0];i++)

          for(j=a[0];j>i;j--)

          if(a[i]*a[j]!=0)

          if ( pro(prime[a[0]-i+1],a[i]-1) > pro( prime[a[0]-j+1],a[j]*(a[i]-1)) )

          {

               a[j]*=a[i]; a[i]=0; break;

               }

}

int main()

{

    while(cin>>n)

    {

    memset(a,0,sizeof(a));

    memset(ans,0,sizeof(ans));

    for(i=2;i<=sqrt(n);i++)

    while(n%i==0){a[++a[0]]=i;n/=i;}

    if(n>1)
		a[++a[0]]=n;
	clean();

    ans[0]=ans[1]=1;

    for(i=1;i<=a[0];i++)

      if(a[a[0]-i+1]>0)

      { temp=a[a[0]-i+1]-1;

        memset(c,0,sizeof(c));

        memset(t,0,sizeof(t));

        memset(b,0,sizeof(b));

        while(temp!=0){c[++c[0]]=temp%2;temp/=2;}

        b[0]=t[0]=1; b[1]=t[1]=prime[i]%10;

        if(prime[i]/10>0)b[0]=t[0]=2,b[2]=t[2]=prime[i]/10;

        for( j=c[0]-1;j>=1;j--)

        {

             chenggao(b,b);

             if(c[j]==1)chenggao(b,t);

            }

        chenggao(ans,b);

        }

    print(ans);

    }

     return 0;

}

