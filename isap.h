const int maxn=205;k

int g[maxn][maxn];//,c[maxn][maxn],f[maxn][maxn];
int m,n,mm,i,j;
int vd[maxn],d[maxn];
/*g是流量(可用流量,会被修改),mm是最大流*/
int min(int x,int y)
{
  return x<y?x:y;
}

int dfs(int x, int y,int n)//x是起点,y是当前改进量,n是点数,同时也是终点....
{
  int mm,v,t;
  if(x == n)
    return y;
  mm = 0;
  for(v=1;v<=n;v++)
    if(g[x][v] > 0 && d[x] == d[v] + 1)
    {
      t = dfs(v,min(y-mm,g[x][v]),n);
      g[x][v] -= t;
      g[v][x] += t;
      //if(c[x][v] > 0)f[x][v] += t;
      //else f[v][x] -= t;
      mm += t;
      if(mm == y)return mm;
    }
  
  if(d[1] >= n) return mm;
  vd[d[x]]--;
  if(vd[d[x]] == 0)d[1] = n;
  d[x]++;
  vd[d[x]]++;
  return mm;
}

int main()
{
  vd[0] = n;
  while(d[1] < n)
    mm+=dfs(1,maxlongint,n);
  return 0;
}
