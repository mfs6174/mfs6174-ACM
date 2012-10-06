/*
ID: mfs.dev2
PROG: ti
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>

#include<map>
#include<vector>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

#include <vector>
#include<algorithm>
class SlimeXSlimesCity
{
public:
  int merge(std::vector<int> &population)
  {
    int i;
    long long mm=0;
    int f[60]={1};
    std::sort(population.begin(),population.end());
    mm=population[0];
    for (i=1;i<population.size();i++)
    {
      if (mm>=population[i])
        f[i]=f[i-1];
      else
        f[i]=0;
      f[i]+=1;
      mm+=(long long)(population[i]);
    }
    return f[population.size()-1];
  }
};

