
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const int sushu=1003001;

struct D
{
  int d,n;
};
int hash[sushu+1],rr[150000];
int i,j,k,n,m,t,mm,c;
D shu[150000];

bool cha(int x)
{
  int i,t;
  t=x%sushu;
  if (hash[t]==0)
    return false;
  i=hash[t];
  while (i)
  {
    if (shu[i].d==x)
      return true;
    i=shu[i].n;
  }
  return false;
}

void jia(int x)
{
  int i,t;
  t=x%sushu;
  if (hash[t]==0)
  {
    c++;
    hash[t]=c;
    shu[c].d=x;
    shu[c].n=0;
    return;
  }
  i=hash[t];
  while (1)
  {
    if (shu[i].d==x)
      return;
    if (shu[i].n==0)
    {
      c++;
      shu[c].d=x;
      shu[c].n=0;
      shu[i].n=c;
      break;
    }
  }
}

    
int main()
{
  cin>>n>>m;
  while (n)
  {
    memset(hash,0,sizeof(hash));
    mm=0;
    c=0;
    for (i=1;i<=n;i++)
    {
      cin>>t;
      jia(t);
    }
    for (i=1;i<=m;i++)
    {
      cin>>t;
      if (cha(t))
      {
        mm++;
        rr[mm]=t;
      }
    }
    if (mm>n/2)
    {
      cout<<"美丽的女孩，你不适合种田，你适合做ACM！"<<endl;
      cin>>n>>m;
      continue;
    }
    if (mm==0)
      cout<<"有没有女孩子愿意跟我一起回家种田~~"<<endl;
    else
    {
      cout<<"就是你了，陪我回家种田去吧！"<<endl;
      sort(&(rr[1]),&(rr[mm])+1);
      cout<<mm<<endl;
      for (i=1;i<=mm;i++)
        cout<<rr[i]<<endl;
    }
    cin>>n>>m;
  }
}

      
      
      
