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

const int maxn=100000;
const int maxm=1000000;
const int inf=1<<30;
struct edge{int from, to, val, next;}e[maxm];;
int v[maxn], que[maxn], dis[maxn],len;
void init()
{
    len=0;
    memset(v, -1, sizeof(v)); 
}
void insert(int from, int to, int va)
{
    e[len].from = from, e[len].to = to; e[len].val = va;
    e[len].next = v[from];v[from] = len++;
    e[len].from = to, e[len].to = from; e[len].val = 0;
    e[len].next = v[to];v[to] = len++;
}
int Dinic(int n, int s, int t)
{
    int ans = 0;
    while(true)
    {
        int head, tail, id,i;
        head = tail = 0; que[tail++] = s;
        memset(dis, -1, sizeof(dis)); dis[s] = 0;
        while(head < tail)
        {
            id = v[que[head++]];
            while(id != -1)
            {
                if (e[id].val > 0 && dis[e[id].to] == -1)
                {
                    dis[e[id].to] = dis[e[id].from] + 1;
                    que[tail++] = e[id].to;
                    if (e[id].to == t)
                    {
                        head = tail;
                        break;
                    }
                }
                id = e[id].next;
            }
        }
        if (dis[t] == -1) break;
        id = s, tail = 0;
        while(true)
        {
            if (id == t) // 找到一条增广路
            {
                int flow =inf,fir;
                for(i = 0; i < tail; i++)
                    if (e[que[i]].val < flow)
                    {
                        fir = i;
                        flow = e[que[i]].val;
                    }
                    for(i = 0; i < tail; i++)
                        e[que[i]].val -= flow, e[que[i] ^ 1].val += flow;
                    ans += flow; tail = fir; id = e[que[fir]].from;
            }
            id = v[id];
            while(id != -1)
            {
                if (e[id].val > 0 && dis[e[id].from] + 1 == dis[e[id].to])
                    break;
                id = e[id].next;
            }
            if (id != -1)
            {
                que[tail++] = id;
                id = e[id].to;
            }
            else
            {
                if (tail == 0) break;
                dis[e[que[tail - 1]].to] = -1;
                id = e[que[--tail]].from;
            }
        }
    }
    return ans;
}
int i,j,k,aa,bb,cc,zl,n,m;
int zu,zz;
int rs;

int main()
{
  freopen("ti.in","r",stdin);
  sf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    sf("%d%d",&n,&m);
    //s=1;t=n;
    rs=0;
    //cnt=0;
    //memset(head,-1,sizeof(head));
    init();
    pf("Case #%d:\n",zz);
    int ans0=0;
    for (j=1;j<=m;j++)
    {
      sf("%d%d%d",&aa,&bb,&cc);
      insert(aa-1,bb-1,cc);
      ans0=Dinic(n,0,n-1);
      zl=ans0-rs;
      rs=ans0;
      if (ans0>0)
        pf("%d %d\n",j,ans0);
    }
  }
  return 0;
}
