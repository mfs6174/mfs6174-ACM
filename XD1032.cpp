#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
ofstream ouf("out.out");
ifstream inf("data.in");

int main()
{
	string s,zis;
	int zushu,wei,i;
	inf>>zushu;
	for (i=1;i<=zushu;i++)
	{
		inf>>s>>zis;
		wei=s.find(zis);
		if (wei==string::npos)
			ouf<<-1;
		else
			ouf<<wei;
		ouf<<endl;
	}
}
