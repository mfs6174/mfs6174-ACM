//平面点集最大三角形
#include <iostream>
#include <cmath>
#include <algorithm>
#include<cstdio>

using namespace std;

const int MAX_N = 50050;
const double Ling= 1e-8;

struct P
{
public:
  int x, y;

  P(int xx=0, int yy=0)
    : x(xx), y(yy) { };
};

P ch[MAX_N], tmp[MAX_N];
int n;

istream &operator>>(istream &is, P &p)
{
  return is >> p.x >> p.y;
}

P operator-(const P &p1, const P &p2)
{
  P ret;
  ret.x = p1.x - p2.x;
  ret.y = p1.y - p2.y;
  return ret;
}

int Max(const int &a, const int &b)
{
  return a > b ? a : b;
}

int cha(const P &p1, const P &p2)
{
  return p1.x*p2.y - p2.x*p1.y;
}

void swap(P &a, P &b)
{
  P t = a;
  a = b;
  b = t;
}

int Cmp(const P &p1, const P &p2)
{
  return p1.y < p2.y || p1.y == p2.y && p1.x < p2.x;
}

int Graham_scan()
{  

  //这个算法已经不是纯洁的Graham了
  sort(tmp, tmp+n, Cmp);
  int stack[MAX_N], top=0;
  stack[top] = top++;
 
  int i;
  for (i=1; i<n; )
  {
    if (top == 1 || cha(tmp[stack[top-1]]-tmp[stack[top-2]], tmp[i]-tmp[stack[top-1]]) > 0)
      stack[top++] = i++;
    else
      top--;
  }
  int t=top;
  for (i=n-2; i>=0; )
  {
    if (top == t || cha(tmp[stack[top-1]]-tmp[stack[top-2]], tmp[i]-tmp[stack[top-1]]) > 0)
      stack[top++] = i--;
    else 
      top--;
  }
  for (i=0; i<top; ++i)
  {
    ch[i] = tmp[stack[i]];
  }

  n = top-1;
  return 1;
}

//旋转卡壳的思想：

//枚举多边形的第i个点， 设j = i+1, k = j+1， 然后进行如下操作

//1. a1 = Area(i, j, k), a2 = Area(i, j, k+1), 如果a2 < a1, 进行第2步，否则k++,循环

//2. b1 = Area(i, j, k), b2 = Area(i, j+1, k), 如果b2 < b1, 退出， 否则，j++, 循环

int Max_Triangle()
{
  int ans = 0, tmp;
  int p=1, q=2;
  int i = 0;
  while (i != n)
  {
    while (cha(ch[p]-ch[i], ch[q]-ch[i])
           - (cha(ch[p]-ch[i], ch[(q+1)%n]-ch[i])) < 0)
    { 
      q = (q+1)%n;
    }
    tmp=cha(ch[p]-ch[i], ch[q]-ch[i]);
    ans = Max(ans, tmp);
  
    while (cha(ch[p]-ch[i], ch[q]-ch[i])
           - (cha(ch[(p+1)%n]-ch[i], ch[q]-ch[i])) < 0)
    {
      p = (p+1)%n;
    }tmp=cha(ch[p]-ch[i], ch[q]-ch[i]);
    ans = Max(ans, tmp);
    i++;
  }

  printf("%.2lf\n", double(ans)/2);

  return 1;
}

int main()
{
  while (scanf("%d", &n)!=EOF)
  {
    for (int i=0; i < n; ++i)
    {
      cin >> tmp[i];
      if (tmp[i].y < tmp[0].y || tmp[i].y == tmp[0].y && tmp[i].x < tmp[0].x)
        swap(tmp[i], tmp[0]);
    }
    Graham_scan();

    Max_Triangle();
  }
  return 0;
}
