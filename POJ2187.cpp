//旋转卡壳 平面最远点对（凸包直径）模板 这个是个整数的题，求方距离，可以改成实数的
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;

#define LL long long
const int N = 50005;

struct P
{
  LL x, y;
};

P p[N];
int stk[N], top;

inline LL mult(P a, P b, P c)
{
  return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}
#define fmult(a, b, c) mult(p[a], p[b], p[c])

inline LL dist(P a, P b)    // squared distance
{
  LL dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}
#define fdist(u, v) dist(p[u], p[v])

bool cmp(const P &a, const P &b)
{
  LL x = mult(a, b, p[0]);
  if (x > 0 || x == 0 && dist(a, p[0]) < dist(b, p[0]))
    return 1;
  return 0;
}

void graham(int n)
{
  int i = 1;
  for (P t; i < n; i++) 
  {
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
      t = p[i], p[i] = p[0], p[0] = t;
  }
  sort(p + 1, p + n, cmp);
  for (stk[0] = 0, top = 1, i = 2; i < n; i++)
    if (fmult(i-1, i, 0) != 0) 
    {
      stk[1] = i-1, stk[2] = i++, top++;
      break;
    }
  if (i == n) return;
  LL s;
  while (i < n)
  {
    while ((s = fmult(i, stk[top], stk[top-1])) > 0) top--;
    if (s == 0) stk[top] = i++;
    else stk[++top] = i++;
  }
}

LL caliper(int n)
{
  if (top == 1) return fdist(0, n-1);
  LL ret = 0;
  stk[++top] = 0;
  for (int t = 1, i = 0; i < top; ++i)
  {
    while (fmult(stk[i+1], stk[t+1], stk[i]) > fmult(stk[i+1], stk[t], stk[i]))
      t = (t + 1) % top;
    ret = max(max(fdist(stk[i], stk[t]), fdist(stk[i+1], stk[t+1])), ret);
  }
  return ret;
}

int main()
{
  int i, n;
  while (scanf("%d",&n) != EOF)
  {
    for (i = 0; i < n; ++i) 
      scanf("%lld %lld", &p[i].x, &p[i].y);
    if (n == 2)
    {
      printf("%lld\n", fdist(0, 1));
      continue;
    }
    graham(n);
    printf("%lld\n", caliper(n));
  }
  return 0;
}
