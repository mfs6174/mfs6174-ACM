/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: ti
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
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;


//rank从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//high从2开始,因为表示的是sa[i-1]和sa[i]
#define M 20000
int rank[M],sa[M],X[M],Y[M],high[M];
char init[M],iss[M];
int buc[M];
void calhigh(int n) {
  int i , j , k = 0;
  for(i = 1 ; i <= n ; i++) rank[sa[i]] = i;
  for(i = 0 ; i < n ; high[rank[i++]] = k)
    for(k?k--:0 , j = sa[rank[i]-1] ; init[i+k] == init[j+k] ; k++);
}
bool cmp(int *r,int a,int b,int l) {
  return (r[a] == r[b] && r[a+l] == r[b+l]);
}
void suffix(int n,int m = 128) {
  int i , l , p , *x = X , *y = Y;
  for(i = 0 ; i < m ; i ++) buc[i] = 0;
  for(i = 0 ; i < n ; i ++) buc[ x[i] = init[i]  ] ++;
  for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
  for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[i] ]] = i;
  for(l = 1,p = 1 ; p < n ; m = p , l *= 2) {
    p = 0;
    for(i = n-l ; i < n ; i ++) y[p++] = i;
    for(i = 0 ; i < n ; i ++) if(sa[i] >= l) y[p++] = sa[i] - l;
    for(i = 0 ; i < m ; i ++) buc[i] = 0;
    for(i = 0 ; i < n ; i ++) buc[ x[y[i]] ] ++;
    for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
    for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[y[i]] ] ] = y[i];
    for(swap(x,y) , x[sa[0]] = 0 , i = 1 , p = 1 ; i < n ; i ++)
      x[ sa[i] ] = cmp(y,sa[i-1],sa[i],l) ? p-1 : p++;
  }
  calhigh(n-1);//后缀数组关键是求出high,所以求sa的时候顺便把rank和high求出来
}
 
 
//当需要反复询问两个后缀的最长公共前缀时用到RMQ
int Log[M];
int best[20][M];
void initlog()
{
  //预处理每个数字的Log值,常数优化,用于RMQ
  Log[0] = -1;
  for(int i = 1; i <= M ; i ++) {
    Log[i] = (i&(i-1)) ? Log[i-1] : Log[i-1] + 1 ;
  }
}
void initRMQ(int n) {//初始化RMQ
  for(int i = 1; i <= n ; i ++) best[0][i] = high[i];
  for(int i = 1; i <= Log[n] ; i ++) {
    int limit = n - (1<<i) + 1;
    for(int j = 1; j <= limit ; j ++) {
      best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
    }
  }
}
int lcp(int a,int b) {//询问a,b后缀的最长公共前缀
  a = rank[a];	b = rank[b];
  if(a > b) swap(a,b);
  a ++;
  int t = Log[b - a + 1];
  return min(best[t][a] , best[t][b - (1<<t) + 1]);
}
 
int i,j,k,t,n,m,tt,nnn;
int zz,zu;
llg rr;

int main()
{
  //*******************************************
  //	n为数组长度,下标0开始
  //	将初始数据,保存在init里,并且保证每个数字都比0大
  //	m = max{ init[i] } + 1
  //	一般情况下大多是字符操作,所以128足够了
  //*******************************************
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d",&tt);
    sf("%s",iss);
    t=-1;
    for (i=1;i<=tt;i++)
    {
      sf("%s",init+t+1);
      t=strlen(init);
      init[t]='#';
    }
    init[t+1]=0;
    nnn=strlen(init);
    n=strlen(iss);
    char *ii;
    for (ii=init+t+1,i=0;i<n;ii++,i++)
      *ii=iss[i];
    *(ii+1)=0;
    n=strlen(init);
    m=max('#','z')+1;
    suffix(n+1,m);
    //initRMQ(n);
    rr=0;
    //if (sa[1]>=nnn)
    // rr=n-sa[1];
    for (i=1;i<=n;i++)
      if (sa[i]>=nnn)
        rr+=n-sa[i]-high[i];
    //else
        //rr-=high[i];
    pf("Case %d: ",zz);
    cout<<rr<<endl;
  }
  return 0;
}

