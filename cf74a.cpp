#include <iostream>
#include <fstream>

using namespace std;

int r,g,b,mm;

int main()
{
	cin>>r>>g>>b;
	r=(r+1)/2;
	g=(g+1)/2;
	b=(b+1)/2;
	r=(r-1)*3;
	g=(g-1)*3+1;
	b=(b-1)*3+2;
	mm=max(max(r,g),b)+30;
	cout<<mm<<endl;
	return 0;
}
