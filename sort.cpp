#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream inf("data.in");
ofstream outf("out.out");

vector<int> a(101);
int n,i;


int main()
{
	inf>>n;
	for (i=1;i<=n;i++)
        inf>>a[i];
    sort(a.begin()+1,a.begin()+n+1);//习惯从1开始存，begin是0，所以从begin+1开始，第二个参数是最后元素以后，所以是begin+n+1 
    outf<<*(a.begin()+1)<<endl;
    for (i=1;i<=n;i++)
        outf<<a[i]<<" ";
    outf<<endl;
}
