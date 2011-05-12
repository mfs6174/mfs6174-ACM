using namespace std;
const int maxlongint=2147483647;

struct bian
{
  int n,m,a[102],b[102],d[105];
};
int n,m,t,i,j,tt;
int chang[105],dian[205][205],d[205][205],f[205],dui[205];
bian lian[105];

int cha(int x)
{
  if (!f[x])
    return x;
  f[x]=cha(f[x]);
  return f[x];
}

void bing(int x,int y)
{
  int t=cha(x),tt=cha(y);
  if(t!=tt)
    f[t]=tt;
}

int  bian2dian(int n)
{
  int m=0,i,j;
  for (i=1;i<=2*n;i++)
    for (j=1;j<=2*n;j++)
      dian[i][j]=maxlongint;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=lian[i].m;j++)
      bing(2*i-1,lian[lian[i].a[j]].d[i]);
    for (j=1;j<=lian[i].n;j++)
      bing(2*i,lian[lian[i].b[j]].d[i]);
  }
  for (i=1;i<=2*n;i++)
    if (cha(i)==i)
    {
      m++;
      dui[i]=m;
    }
  for (i=1;i<=n;i++)
  {
    int t=dui[cha(2*i-1)],tt=dui[cha(2*i)];
    dian[t][tt]=chang[i];
    dian[tt][t]=chang[i];
  }
  return m;
}
int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>t;
    inf >>chang[t]>>lian[t].m>>lian[t].n;
    for (j=1;j<=lian[t].m;j++)
    {
      inf>>lian[t].a[j];
      lian[t].d[lian[t].a[j]]=2*t-1;
    }
    for (j=1;j<=lian[t].n;j++)
    {
      inf>>lian[t].b[j];
      lian[t]. d[lian[t].b[j]]=2*t;
    }
  }
  m=bian2dian(n);
}
