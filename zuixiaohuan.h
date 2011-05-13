using namespace std;
const int maxlongint=2147483647;
ifstream inf("fence6.in");
ofstream ouf("fence6.out");

int dian[205][205],d[205][205];

int min(int x,int y)
{
  return x<y?x:y;
}

int zuixiaohuan(int n)
{
  int i,j,k,mm=maxlongint;
  for (k=1;k<=n;k++)
  {
    for (i=1;i<k;i++)
      for (j=i+1;j<k;j++)
        if ((dian[i][k]!=maxlongint)&&(dian[k][j]!=maxlongint)&&(d[j][i]!=maxlongint))
          mm=min(mm,dian[i][k]+dian[k][j]+d[j][i]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if ((d[i][k]!=maxlongint)&&(d[k][j]!=maxlongint))
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }
  return mm;
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      d[i][j]=dian[i][j];
  ouf<<zuixiaohuan(n)<<endl;
}
