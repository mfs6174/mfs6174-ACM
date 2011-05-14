/*
ID: mfs6174
PROG: uestc1478 
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
const int maxlongint=2147483647,sushu=1003001;

int i,j,k,t,n,m,mm,zz,zu;
vector<unsigned> hash[sushu+10];
int bu[50][2],qu[50][10],hui[50][2];
unsigned wei[50],zou[50],tt;
bool ff;

int suan(int x,int y)
{
  int t=(x-1)*m+y;
  if ((x<1)||(x>n)||(y<1)||(y>m))
    return 0;
  else
    return t;
}


void init(int x,int y)
{
  int h=(x-1)*m+y,t;
  if (t=suan(x+1,y+2))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x-1,y+2))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x+2,y+1))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x-2,y+1))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x+2,y-1))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x-2,y-1))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x+1,y-2))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
  if (t=suan(x-1,y-2))
  {
    qu[h][0]++;
    qu[h][qu[h][0]]=t;
  }
}

bool shash(unsigned x)
{
  unsigned t=x%sushu;
  if (hash[t].empty())
  {
    hash[t].push_back(x);
    return false;
  }
  for (vector<unsigned>::iterator i=hash[t].begin();i!=hash[t].end();i++)
    if ((*i)==x)
      return true;
  hash[t].push_back(x);
  return false;
}
    

bool dfs(int h,unsigned zh)
{
  if (ff)
    return true;
  int i;
  bool tf=false;
  zh=zh&zou[h];
  if (shash(zh+h*7+h*h*h*13))
    return false;
  bu[0][0]++;
  bu[bu[0][0]][0]=hui[h][0];
  bu[bu[0][0]][1]=hui[h][1];
  if (!zh)
  {
    ff=true;
    return true;
  }
  for (i=1;i<=qu[h][0];i++)
    if (zh&wei[qu[h][i]])
      tf=tf||dfs(qu[h][i],zh);
  bu[0][0]--;
  return tf;
}

int main()
{
  wei[1]=1;
  zou[1]=~wei[1];
  for (i=2;i<=30;i++)
  {
    wei[i]=wei[i-1]<<1;
    zou[i]=~wei[i];
  }
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>n>>m;
    for (i=0;i<sushu;i++)
      hash[i].clear();
    memset(bu,0,sizeof(bu));
    memset(qu,0,sizeof(qu));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        init(i,j);
        hui[(i-1)*m+j][0]=i;
        hui[(i-1)*m+j][1]=j;
      }
    ff=false;
    tt=1;
    for (i=2;i<=n*m;i++)
    {
      tt=tt<<1;
      tt=tt|1;
    }
    for (i=m;i>=1;i--)
      for (j=n;j>=1;j--)
        if (dfs((j-1)*m+i,tt))
        {
          ff=true;
          break;
        }
    cout<<"Scenario #"<<zz<<':'<<endl;
    if (!ff)
      cout<<"impossible"<<endl;
    else
    {
      for (i=1;i<=n*m;i++)
        cout<<(char)(bu[i][1]+64)<<bu[i][0];
      cout<<endl;
        
    }
    cout<<endl;
  }
}

      
