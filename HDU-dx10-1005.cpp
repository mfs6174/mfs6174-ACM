#include<algorithm>
#include<iomanip>
#include<cmath>
#include<iostream>
using namespace std;
//题目要求最大的三角形的面积，最大的三角形的三个点肯定都在外圈，很显然会用到凸包，我一直用的是凸包的模板，把它套进去问题解决得差不多了
//找到了凸包的点，同过叉积求三角形的面，最终找出最大的就OK了。
struct point { double x, y; };
bool mult(point sp, point ep, point op){
  return (sp.x - op.x) * (ep.y - op.y)
    >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator < (const point &l, const point &r){
  return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[])//这个是用的模板，pnt中方的是点的坐标，res是通过判断得到的凸边行边上的点，n是点的个数

{
  int i, len, k = 0, top = 1;
  sort(pnt, pnt + n);
  if (n == 0) return 0; res[0] = pnt[0];
  if (n == 1) return 1; res[1] = pnt[1];
  if (n == 2) return 2; res[2] = pnt[2];
  for (i = 2; i < n; i++) {
    while (top && mult(pnt[i], res[top], res[top-1]))
      top--;
    res[++top] = pnt[i];
  }
  len = top; res[++top] = pnt[n - 2];
  for (i = n - 3; i >= 0; i--) {
    while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
    res[++top] = pnt[i];
  }
  return top; // 返回凸包中点的个数
}
point res[6550001],pnt[6550001];
double area(point a,point b,point c)//利用叉积来算面积
{
  return abs((a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x));
}


int main()
{
  int t,n,i,j,s;
  double ar,max;
  while(cin>>n)
  {
    ar=0;
    max=0;
    for(i=0;i<n;i++)
      cin>>pnt[i].x>>pnt[i].y;
    int k=graham(pnt,n,res);
    for(j=0;j<k-2;j++)
    {
      for(i=j+1;i<k-1;i++)
        for(s=i+1;s<k;s++)
        {
          ar=area(res[i],res[j],res[s]);
          if(max<ar)
            max=ar;
        }
    }
    cout<<fixed<<setprecision(2)<<max/2<<endl;
  }
  return 0;
}
