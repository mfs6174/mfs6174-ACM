#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100012;

typedef pair<int, int> point;
typedef long long LL;

long long sum[N],fenmu,fenzi;
point s[N];

LL cross(point a, point b, point c) {
    // a->b x b->c
    LL x0 = b.first - a.first;
    LL y0 = b.second - a.second;
    LL x1 = c.first - b.first;
    LL y1 = c.second - b.second;
    return x0 * y1 - x1 * y0;
}

int bsearch(int l, int r, point &now) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (cross(s[mid], s[mid + 1], now) < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void read(int &r) {
    char c;
    while (c = getchar(), c < '0' || c > '9');
    r = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') r = r * 10 + c - '0';
}

long long gcd(long long x,long long y)
{
  long long t;
  if (x<y)
  {
    t=x;
    x=y;
    y=t;
  }
  while (x%y!=0)
  {
    t=x;
    x=y;
    y=t%y;
  }
  return y;
}

int main() {
    int n, d, p;
    scanf("%d%d", &n, &d);
    p = sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld",&sum[i]);
      sum[i] += sum[i - 1];
    }
    double ans = 0;
    for (int i = d; i <= n; ++i) {
      point r(i - d, sum[i - d]), now(i, sum[i]);
      while (p > 1 && cross(s[p - 1], s[p], r) < 0) p--;
      s[++p] = r;
      int opt = bsearch(1, p, now);
      double f = (double)(s[opt].second - sum[i]) / (s[opt].first - i);
      if (f > ans)
      {
        ans = f;
        fenzi=(s[opt].second - sum[i]);
        fenmu=(s[opt].first - i);
      }
    }
    if (fenzi%fenmu==0)
      cout<<fenzi/fenmu<<endl;
    else
      cout<<(fenzi/gcd(fenzi,fenmu))<<'/'<<(fenmu/gcd(fenzi,fenmu))<<endl;
    return 0;
}
