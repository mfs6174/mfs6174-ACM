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

#ifndef LXKDTREE_H
#define LXKDTREE_H

#define MAX_DIM 2
#define MAX_RANG_DIM 1

llg myabs(llg x)
{
  if (x<0)
    return -x;
  else
    return x;
}

struct _KDNode
{
  int pnt,spt;
  llg mid;
  int left,right;
  llg rect[MAX_RANG_DIM][2];
};

struct _KDPoint
{
  llg d[MAX_DIM];
  int dim;
  bool pd;
  llg dist(llg _q[]) const
  {
    llg t=0;
    for (int i=0;i<dim;i++)
      t+=myabs(d[i]-_q[i]);
    return t;
  }
};

struct _Backtracer
{
  int x,y;
  llg dist;
  _Backtracer()
  {
    x=y=-1;
    dist=0;
  }
  _Backtracer(int _x,int _y,llg _dist)
  {
    x=_x;y=_y;
    dist=_dist;
  }
  bool operator <(const _Backtracer &a) const
  {
    return dist>a.dist;
  }
};

struct LxKDTree
{
  vector<_KDNode> nodes;
  int nd,dim,sflag;
  vector<_KDPoint> data;
  vector<int> pset;
  static bool cmp(const int a,const int b);
  bool pointInRange(llg _point[],llg _range[MAX_RANG_DIM][2]);
  int rectInRange(llg _rect[MAX_RANG_DIM][2],llg _range[MAX_RANG_DIM][2]);
  void reportSub(int now,int lst[]);
  void upPoint(int _p,llg _q[],int lst[],llg &mmdist,int k);
  void set(int _dim,int _size);
  void build(int now,int l,int r,int dep);
  void rangeSearch(int now,llg range[MAX_RANG_DIM][2],int lst[]);
  void exp2Leaf(int now,int lst[],llg &mmdist,llg _q[],priority_queue<_Backtracer> &Q,int k);
  void aknns(llg _q[],int lst[],int k,llg sigma);
};

#endif

llg mrad;

LxKDTree *LXKDTree_Operating;

void LxKDTree::set(int _dim,int _size)
{
  dim=_dim;
  if (nodes.size()<_size+1)
    nodes.resize(_size+1);
  if (data.size()<_size+1)
    data.resize(_size+1);
  if (pset.size()<_size+1)
    pset.resize(_size+1);
  nd=1;
  sflag=0;
}

void LxKDTree::build(int now,int l,int r,int dep)
{
  sflag=nodes[now].spt=dep%dim;
  if (l==r)
  {
    nodes[now].pnt=pset[l];
    nodes[now].left=nodes[now].right=-1;
    nodes[now].mid=data[nodes[now].pnt].d[nodes[now].spt];
    return;
  }
  int t=(r-l)>>1;
  nth_element(&pset[l],&pset[l+t],&pset[r+1],cmp);
  nodes[now].pnt=pset[l+t];
  nodes[now].mid=data[nodes[now].pnt].d[nodes[now].spt];
  if (t>=1)
  {
    nd++;
    nodes[now].left=nd;
    for (int i=0;i<MAX_RANG_DIM;i++)
    {
      nodes[nd].rect[i][0]=nodes[now].rect[i][0];
      nodes[nd].rect[i][1]=nodes[now].rect[i][1];
    }
    nodes[nd].rect[nodes[now].spt][1]=nodes[now].mid;
    build(nd,l,l+t-1,dep+1);
  }
  else
    nodes[now].left=-1;
  nd++;
  for (int i=0;i<MAX_RANG_DIM;i++)
  {
    nodes[nd].rect[i][0]=nodes[now].rect[i][0];
    nodes[nd].rect[i][1]=nodes[now].rect[i][1];
  }
  nodes[nd].rect[nodes[now].spt][0]=nodes[now].mid;
  nodes[now].right=nd;
  build(nd,l+t+1,r,dep+1);
}

bool LxKDTree::cmp(const int a,const int b)
{
  return LXKDTree_Operating->data[a].d[LXKDTree_Operating->sflag]<LXKDTree_Operating->data[b].d[LXKDTree_Operating->sflag];
}

void LxKDTree::reportSub(int now,int lst[])
{
  if (now==-1)
    return;
  lst[0]++;
  lst[lst[0]]=nodes[now].pnt;
  reportSub(nodes[now].left,lst);
  reportSub(nodes[now].right,lst);
}

bool LxKDTree::pointInRange(llg _point[],llg _range[MAX_RANG_DIM][2])
{
  bool t=true;
  for (int i=0;i<MAX_RANG_DIM;i++)
    t=t&&(_point[i]>=_range[i][0])&&(_point[i]<=_range[i][1]);
  return t;
}

int LxKDTree::rectInRange(llg _rect[MAX_RANG_DIM][2],llg _range[MAX_RANG_DIM][2])
{
  bool ins=true,ous=false;
  for (int i=0;i<MAX_RANG_DIM;i++)
  {
    ins=ins&&(_rect[i][0]>=_range[i][0])&&(_rect[i][1]<=_range[i][1]);
    ous=ous||(_rect[i][0]>_range[i][1])||(_rect[i][1]<_range[i][0]);
  }
  if (ins)
    return 1;
  if (ous)
    return -1;
  return 0;
}

void LxKDTree::rangeSearch(int now,llg range[MAX_RANG_DIM][2],int lst[])
{
  if (now==-1)
    return;
  int rt=rectInRange(nodes[now].rect,range);
  if (rt==-1)
    return;
  if (rt==1)
  {
    reportSub(now,lst);
    return;
  }
  if (pointInRange(data[nodes[now].pnt].d,range))
  {
    lst[0]++;
    lst[lst[0]]=nodes[now].pnt;
  }
  rangeSearch(nodes[now].left,range,lst);
  rangeSearch(nodes[now].right,range,lst);
}

void LxKDTree::upPoint(int _p,llg _q[],int lst[],llg &mmdist,int k)
{
  llg dd=data[_p].dist(_q);
  if (dd>mmdist)
    return;
  int pos=lst[0];
  while (pos>0 && data[lst[pos]].dist(_q)>dd) pos--;
  //if (lst[0]<k)
    lst[0]++;
  for (int i=lst[0];i>pos+1;i--)
    lst[i]=lst[i-1];
  lst[pos+1]=_p;
  // if (lst[0]>=k)
  //   mmdist=data[lst[lst[0]]].dist(_q);
}

void LxKDTree::exp2Leaf(int now,int lst[],llg &mmdist,llg _q[],priority_queue<_Backtracer> &Q,int k)
{
  while (nodes[now].left!=-1)
  {
    if (_q[nodes[now].spt]<=nodes[now].mid)
    {
        Q.push(_Backtracer(now,nodes[now].right,nodes[now].mid-_q[nodes[now].spt]) );
        now=nodes[now].left;
    }
    else
    {
      Q.push(_Backtracer(now,nodes[now].left,_q[nodes[now].spt]-nodes[now].mid) );
      now=nodes[now].right;
    }
  }
  if (nodes[now].right==-1)
  {
    upPoint(nodes[now].pnt,_q,lst,mmdist,k);
  }
  else
  {
    upPoint(nodes[now].pnt,_q,lst,mmdist,k);
    upPoint(nodes[nodes[now].right].pnt,_q,lst,mmdist,k);
  }
}

void LxKDTree::aknns(llg _q[],int lst[],int k,llg sigma)
{
  lst[0]=0;
  priority_queue<_Backtracer> Q;
  llg mmdist=mrad;
  exp2Leaf(1,lst,mmdist,_q,Q,k);
  while ( (!Q.empty()) && (Q.top().dist/**Q.top().dist*/)<=mmdist/(1+sigma) )
  {
    int t=Q.top().y;
    upPoint(nodes[Q.top().x].pnt,_q,lst,mmdist,k);
    Q.pop();
    exp2Leaf(t,lst,mmdist,_q,Q,k);
  }
}


// void setData(LxKDTree &tree,const vector<KeyPoint> &kp)
// {
//   //1 to size set size+1 to n pushback(pset and data)
//   //set nd to 1
//   //set rect of root
// }

int i,j,k,t,n,m,dim,zz,zu;
llg tpnt[6],tp[6],rp[6];
LxKDTree mytree;
int res[110000];
queue<int> Q;
llg dian[101000][2];

int main()
{
  dim=2;
  LXKDTree_Operating=&mytree;
  freopen("ti.in","r",stdin);
  //freopen("ti.out","w",stdout);
  zz=0;
  while (sf("%d",&n)!=EOF)
  {
    zz++;
    if (n==0)
      break;
    pf("Case #%d:\n",zz);
    mytree.set(dim,n+10);
    for (i=1;i<=n;i++)
    {
      for (j=0;j<dim;j++)
      {
        sf("%d",&t);
        mytree.data[i].d[j]=t;
        dian[i][j]=t;
      }
      mytree.data[i].dim=dim;
      mytree.pset[i]=i;
      sf("%lld",&dian[i][2]);
      mytree.data[i].pd=false;
    }
    mytree.build(1,1,n,0);
    sf("%d",&m);
    for (i=1;i<=m;i++)
    {
      llg mc=0;
      Q=queue<int>();
      sf("%d",&t);
      Q.push(t);
      if (mytree.data[t].pd==false)
      {
        mc++;
        mytree.data[t].pd=true;
      }
      while (!Q.empty())
      {
        t=Q.front();
        Q.pop();
        for (j=0;j<dim;j++)
        {
          tp[j]=dian[t][j];
        }
        mrad=dian[t][2];
        mytree.aknns(tp,res,k,0);
      for (int o=1;o<=res[0];o++)
      {
        if (mytree.data[res[o]].pd==false)
        {
          mc++;
          mytree.data[res[o]].pd=true;
          Q.push(res[o]);
        }
      }
      }
      cout<<mc<<endl;
    }
  }
  return 0;
}
