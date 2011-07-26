/*
ID: mfs6174
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
//ofstream ouf("ti.out");
//freopen("ti.i","r",stdin);
const int maxlongint=2147483647;

class TrainingCamp
{
public:
  vector <string> determineSolvers(vector <string> a, vector <string> p)
  {
    vector<string> rr;
    rr.clear();
    int i,j,o;
    int n=a.size(),m=a[0].size(),k=p.size();
    for (i=1;i<=n;i++)
    {
      string ss="";
      for (j=1;j<=k;j++)
      {
        bool fl=true;
        for (o=0;o<m;o++)
        {
          if (p[j-1][o]=='X')
            if (a[i-1][o]!='X')
            {
              fl=false;
              break;
            }
        }
        if (fl)
          ss=ss+"X";
        else
          ss=ss+"-";
      }
      rr.push_back(ss);
    }
    return rr;
  }
};
  
