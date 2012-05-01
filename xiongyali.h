#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
ofstream ouf("out.out");
ifstream inf("data.in");

const int maxn=500;

struct jiedian
{
  int n,dao[maxn];
};

int zuo[maxn],i,j,duiz[maxn],duiy[maxn],nn,rr=0,t;
jiedian dian[maxn];
bool yong[maxn];

bool xiong(int x)
{
  int i,tt;
  //进入的点都是左点
  for (i=1;i<=dian[x].n;i++)//遍历所连所有右点
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))//未重复出现且没有和此点匹配（保证交替1）
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(dui[tt]))//如果是未匹配点，可作为终点，否则顺着它匹配的左点找增广轨（保证交替2），如果找到：
      {
        duiz[x]=tt;
        duiy[tt]=x;//连接左右，右与原匹配的边自动删除
        return true;
      }
    }
  }
  return false;//木有找到增广轨
}

int main()
{
  for (i=1;i<=nn;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t)//找到增广轨
          rr++;//匹配数+1
	}
  }
			
			
			
