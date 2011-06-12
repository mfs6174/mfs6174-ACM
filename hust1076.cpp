//copy from http://blog.163.com/lightyue_leyuan/blog/static/7513607720081059271623/
//kiss_tlx 1076 Accepted 82852 kb 5576 ms C++ 1675 B 2008-10-15 15:08:28 
#include<iostream>
#include<complex> 
#include<algorithm> 
#include<string>
using namespace std; 
#define get2n(n) (int)ceil(log((double)(n))/log(2.0)-eps) 
typedef complex<double> cplx; 
const int maxn=1<<16;    //å¤§äºç­äºnçæå°çå¹ 
const double pi=acos(-1.0),eps=1e-12; 
  
//len : 1<<(get2n(L)+1); 
//inv : 1 DFT : -1 DFT^-1 
void FFT(cplx *a,int len,int inv) 
{ 
    for(int i=0,n1=0,n2=0;i<len;i++,n2^=(len/(i&-i)>>1),n1^=(i&-i)) 
        if(n1>n2)swap(a[n1],a[n2]); 
    for(int m=1; m<=len>>1; m<<=1) 
    { 
        cplx w0(cos(pi/m),sin(pi/(inv*m))),w=1,t; 
        for(int k=0;k<len;k+=(m<<1),w=1) 
        { 
            for(int j=0;j<m;j++,w*=w0) 
            { 
                t=w*a[k+j+m]; 
                a[k+j+m]=a[k+j]-t; 
                a[k+j]+=t; 
            } 
        } 
    } 
    if(inv==-1)for(int i=0;i<len;i++)a[i]/=len; 
}

cplx a[2621440];
cplx b[2621440];
int main()
{

 int Case;
 scanf("%d" , &Case);
 while(Case--)
 {
  int n;
  scanf("%d",&n);
  
  memset(a , 0 , sizeof(a));
  memset(b , 0 , sizeof(b));
  int i;
  for(i = 0 ; i < n ; i++)
  {
   cin>>a[i];
  }
  for(i = n-1 ; i >= 0  ; i--)
  {
   cin>>b[i];
  }
  for (int i = 0; i < n ;++i)
  {
   a[i + n] = a[i]; 
   b[i + n] = b[i];
  }
  int len = 1<<(get2n(4*n));
  FFT(a , len , 1);
  FFT(b , len , 1);
  for(i = 0; i < len ; i++)
  {
   a[i] = a[i] * b[i];
  }
  FFT(a , len , -1);
  printf("%.0lf" , a[n-1].real());
  for(i = n ; i <=  n + n - 2 ; i++)
   printf(" %.0lf" , a[i].real() - a[i-n].real());
  printf("\n");
   
  
 }
 
 return 0;
}
/*
1
4
4 3 2 1
1 2 3 4
*/
