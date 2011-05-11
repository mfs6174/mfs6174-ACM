#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream inf("data.in");
ofstream outf("out.out");

vector<int> a;
int n,i;


int main()
{
    vector<int>::iterator it;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    outf<<*(a.end()-1)<<endl;
    it=a.erase(a.end()-1);
    outf<<*(a.end()-1);
}
