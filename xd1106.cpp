#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
const int maxlongint=2147483647;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");



int shu[20][30000],dui[10][3];
bool sushu[150000];
int i,j,zz,zu,k,t,m,n,r,rr,mm,c;

void shai(int x)
{
  int i,j,t;
  //t=(int)sqrt(x);
  t=x/2+1;
  c=0;
  sushu[1]=false;
  for (i=2;i<=x;i++)
    sushu[i]=true;
  for (i=2;i<=t;i++)
    if (sushu[i])
      for (j=2;j<=x/i+1;j++)
        sushu[i*j]=false;
  for (i=2;i<=x;i++)
    if (sushu[i])
    {
      int k=i%10;
      shu[k][0]++;
      shu[k][shu[k][0]]=i;
    }
}


void pan(int y,int x)
{
  int i,j,t;
  for (i=1;i<=shu[x][0];i++)
    {
      int t=n-shu[x][i],rt,rrt;
      if (t<=0)
        break;
      if (sushu[t])
      {
        if (t<shu[x][i])
        {
          rt=t;rrt=shu[x][i];
        }
        else
        {
          rt=shu[x][i];rrt=t;
        }
        if (rrt-rt<mm)
        {
          mm=rrt-rt;
          rr=rrt;r=rt;
        }
      }
    }
    t=n-5;
    int rt,rrt;
    if (sushu[t])
      {
        if (t<5)
        {
          rt=t;rrt=5;
        }
        else
        {
          rt=5;rrt=t;
        }
        if (rrt-rt<mm)
        {
          mm=rrt-rt;
          rr=rrt;r=rt;
        }
      }
}

int main()
{
  dui[0][1]=9;
  dui[0][2]=1;
  dui[2][1]=9;
  dui[2][2]=3;
  dui[4][1]=3;
  dui[4][2]=1;
  dui[6][1]=9;
  dui[6][2]=7;
  dui[8][1]=7;
  dui[8][2]=1;
  shai(100018);
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    cin>>n;
    t=n%10;
    mm=maxlongint;
    //pan(dui[t][1],dui[t][2]);
    //if (t==2)
    pan(0,1);
    //if (t==4)
    pan(0,7);
    //if (t==6)
    pan(0,3);
    //if (t==8)
    pan(0,9);
    pan(0,5);
    pan(0,2);
    cout<<r<<' '<<rr<<endl;
  }
}

