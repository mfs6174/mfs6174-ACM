#include<string>

using namespace std;

unsigned bkdrhash(string x)
{
  unsigned int seed=131,hash=0,i,l=x.size();
  for (i=0;i<l;i++)
    hash=(hash*seed+x[i])&0xffffffff;
  return hash&0x7FFFFFFF;
}

int main()
{
}

