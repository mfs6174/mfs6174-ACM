/*
ID: mfs6174
PROG: POJ 1743 suffix array
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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

//rank从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//high从2开始,因为表示的是sa[i-1]和sa[i]
#define M 22000
int rank[M],sa[M],X[M],Y[M],high[M],init[M];
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

int shu[M];
int i,j,n,m,t,mm;
int main()
{
  //*******************************************
  //	n为数组长度,下标0开始
  //	将初始数据,保存在init里,并且保证每个数字都比0大
  //	m = max{ init[i] } + 1
  //	一般情况下大多是字符操作,所以128足够了
  //*******************************************
  freopen("ti.in","r",stdin);
  while (scanf("%d",&n)!=EOF,n)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
      if (i>1)
        init[i-2]=shu[i]-shu[i-1]+88;
    }
    init[n-1]=0;
    m=87+88+1;
    suffix(n,m);
    mm=0;
    int x,y,k;
    x=1;y=n/2-1;
    while (x<=y)
    {
      k=(x+y)>>1;
      int ma=-maxlongint,mi=maxlongint;
      bool fl=false;
      for (i=1;i<=n;i++)
      {
        ma=max(ma,sa[i]);
        mi=min(mi,sa[i]);
        if (high[i+1]<k)
        {
          if (ma-mi>k)
          {
            fl=true;
            break;
          }
          ma=-maxlongint;
          mi=maxlongint;
        }
      }
      if (fl)
      {
        mm=max(mm,k+1);
        x=k+1;
      }
      else
        y=k-1;
    }
    if (mm<5)
      mm=0;
    cout<<mm<<endl;
  }
  return 0;
}
