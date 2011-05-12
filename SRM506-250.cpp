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
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

class SlimeXSlimeRancher2
{
 public:
  int train(vector<int> attributes)
  {
    int i,mm=0,ss=0;
    for (i=0;i<attributes.size();i++)
      if (attributes[i]>mm)
        mm=attributes[i];
    for (i=0;i<attributes.size();i++)
      ss+=mm-attributes[i];
    return ss;
  }
};

