#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

struct lnode
{
  int y1,y2,val;
  double x;
}line[20010]; // x坐标事件点

struct knode
{
  double y;
  int id,dy;
}indexy[20010]; // 用于将y坐标离散化

int cmp1(const void *a,const void *b)
{
  return (*(knode *)a).y>(*(knode *)b).y?1:-1;
}
int cmp2(const void *a,const void *b)
{
  return (*(knode *)a).id-(*(knode *)b).id;
}
int cmp3(const void *a,const void *b)
{
  return (*(lnode *)a).x>(*(lnode *)b).x?1:-1;
}

int MAX(int x,int y) {return x>y?x:y; }

struct node
{
  int l,r,val,max;
}s[200010];

void build(int now,int l,int r)
{
  s[now].l=l; s[now].r=r; s[now].val=s[now].max=0;
  if(l!=r)
  {
    int mid=(l+r)>>1;
    build(now+now,l,mid);
    build(now+now+1,mid+1,r);
  }
}

void insert(int now,int l,int r,int val)
{
  if(s[now].l==l&&s[now].r==r)
  {
    s[now].val+=val;
    if(s[now].l==s[now].r) s[now].max=s[now].val;
    else s[now].max=MAX(s[now+now].max,s[now+now+1].max)+s[now].val;
    return;
  }
  int mid=(s[now].l+s[now].r)>>1;
  if(r<=mid) insert(now+now,l,r,val);
  else if(l>mid) insert(now+now+1,l,r,val);
  else
  {
    insert(now+now,l,mid,val);
    insert(now+now+1,mid+1,r,val);
  }
  s[now].max=MAX(s[now+now].max,s[now+now+1].max)+s[now].val;
}


int main()
{
  freopen("ti.in","r",stdin);
  int i,n,k,c,kk,ans;
  int x,y;
  double w,h;
  while(scanf("%d%lf",&n,&w)!=EOF)
  {
    k=0;w+=0.5;h=w;
    for(i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);c=1;
      line[++k].x=x; line[k].val=c; indexy[k].y=y; indexy[k].id=k;
      line[++k].x=x+w; line[k].val=-c; indexy[k].y=y+h; indexy[k].id=k;
    }
    qsort(&indexy[1],k,sizeof(indexy[1]),cmp1);
    indexy[1].dy=1;
    kk=1;
    for(i=2;i<=k;i++)
    {
      if(indexy[i].y==indexy[i-1].y) indexy[i].dy=kk;
      else indexy[i].dy=++kk;
    }
    qsort(&indexy[1],k,sizeof(indexy[1]),cmp2);
    for(i=1;i<=n;i++)
    {
      line[2*i-1].y1=line[2*i].y1=indexy[2*i-1].dy;
      line[2*i-1].y2=line[2*i].y2=indexy[2*i].dy;
    }
    qsort(&line[1],k,sizeof(line[1]),cmp3);
    build(1,1,kk);
    ans=0;
    for(i=1;i<=k;i++)
    {
      insert(1,line[i].y1,line[i].y2,line[i].val);
      ans=MAX(ans,s[1].max);
    }
    printf("%d\n",ans);
  }
  return 0;
}
