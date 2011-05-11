#include<iostream>
//#include<fstream>
#include<string>
#include<sstream>
using namespace std;
//ifstream inf("data.in");
//ofstream outf("out.out");
const int maxlongint=2147483646;

int quan[101][101],duan[101];
int n,i,j,s=0;
string t;

int val(const string &x)
{
    istringstream t(x);
    int r;
    t>>r;
    return r;
}

/*string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
}
*/
    
void dijie(int x)
{
    int i,j,k,mm;
    bool f[101]={false};
    for (i=1;i<=n;i++)
        duan[i]=quan[x][i];
    duan[x]=0;
    f[x]=true;
    for (i=1;i<n;i++)
    {
        mm=maxlongint;
        for (j=1;j<=n;j++)
            if ((!f[j])&&(duan[j]<mm))
            {
                k=j;
                mm=duan[j];
            }
        f[k]=true;
        for (j=1;j<=n;j++)
            if ((quan[k][j]!=maxlongint)&&(duan[k]+quan[k][j]<duan[j]))
                duan[j]=quan[k][j]+duan[k];
    }
}
                

int main()
{
    //inf>>n;
	cin>>n;
    for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	       (i==j)?(quan[i][j]=0):(quan[i][j]=maxlongint);
    for (i=2;i<=n;i++)
        for (j=1;j<i;j++)
        {
            //inf>>t;
            cin>>t;
            if (t!="x")
                quan[i][j]=val(t);
            quan[j][i]=quan[i][j];
        }
    dijie(1);
    for (i=1;i<=n;i++)
            (duan[i]>s)?(s=duan[i]):0;
    //outf<<s<<endl;
    cout<<s<<endl;
}
