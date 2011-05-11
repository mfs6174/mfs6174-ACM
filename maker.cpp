#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
ofstream ouf("data.in");

int main()
{
	int i;
	string s,ss(499,'A');
	char c;
	//srand(time(NULL));
	for (i=1;i<=200000;i++)
	{
		//c=rand()%26+65;
		s=s+"A";
	}
	ouf<<s<<endl;
	ss=ss+"B";
	ouf<<ss<<endl;
}
