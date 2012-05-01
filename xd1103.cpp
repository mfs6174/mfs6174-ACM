#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
const int maxlongint=2147483647;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");

int zz,zu,i,j,k,t,yy,mm,dd;
bool ff;
int main()
{
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>yy>>mm>>dd;
    if (yy==2011&&mm==5&&dd==22)
    {
      cout<<"nice day"<<endl;
      continue;
    }
    if (yy<2011)
      ff=false;
    else
      ff=true;
    if (yy==2011)
    {
      if (mm<5)
        ff=false;
        else
        ff=true;
      }
     if (yy==2011&&mm==5)
     {
        if (dd<22)
        ff=false;
        else
        ff=true;
      }
      if (ff)
        cout<<"after"<<endl;
        else
        cout<<"before"<<endl;
      }
    }
     
          

