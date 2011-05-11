#include<fstream>
#include<cmath>

using namespace std;

ofstream ouf("sushu");

int c,i,pp[150000];

void shai(int x,int &c)
{
  int i,j,t;
  bool f[150000]={true};
  t=(int)(sqrt(x));
  c=0;
  for (i=2;i<=t;i++)
    if (f[i])
      for (j=2;j<=x/i;j++)
        f[i*j]=false;
  for (i=2;i<=x;i++)
    if (f[i])
    {
      c++;
      pp[c]=i;
    }
}

int main()
{
  shai(100000,c);
  ouf<<c<<',';
  for (i=1;i<=c;i++)
    ouf<<pp[i]<<',';
  ouf<<endl;
}

  
