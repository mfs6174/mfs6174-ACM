/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: KD-Tree
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
const int maxlongint=2147483647;

#ifndef LXKDTREE_H
#define LXKDTREE_H

#define MAX_DIM 6
#define MAX_RANG_DIM 1

struct _KDNode
{
  int pnt,spt;
  float mid;
  int left,right;
  float rect[MAX_RANG_DIM][2];
};

struct _KDPoint
{
  float d[MAX_DIM];
  int dim;
  float dist(float _q[]) const//squared distance
  {
    float t=0;
    for (int i=0;i<dim;i++)
      t+=(d[i]-_q[i])*(d[i]-_q[i]);
    return t;
  }
};

struct _Backtracer
{
  int x,y;
  float dist;
  _Backtracer()
  {
    x=y=-1;
    dist=0;
  }
  _Backtracer(int _x,int _y,float _dist)
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
  bool pointInRange(float _point[],float _range[MAX_RANG_DIM][2]);
  int rectInRange(float _rect[MAX_RANG_DIM][2],float _range[MAX_RANG_DIM][2]);
  void reportSub(int now,int lst[]);
  void upPoint(int _p,float _q[],int lst[],float &mmdist,int k);
  void set(int _dim,int _size);
  void build(int now,int l,int r,int dep);
  void rangeSearch(int now,float range[MAX_RANG_DIM][2],int lst[]);
  void exp2Leaf(int now,int lst[],float &mmdist,float _q[],priority_queue<_Backtracer> &Q,int k);
  void aknns(float _q[],int lst[],int k,float sigma);
};

#endif


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

void LxKDTree::build(int now,int lft,int r,int dep)//comment out code is only used in rangesearch
{
  sflag=nodes[now].spt=dep%dim;
  if (lft==r)
  {
    nodes[now].pnt=pset[lft];
    nodes[now].left=nodes[now].right=-1;
    nodes[now].mid=data[nodes[now].pnt].d[nodes[now].spt];
    return;
  }
  int t=(r-lft)>>1;
  nth_element(&pset[lft],&pset[lft+t],&pset[r+1],cmp);
  nodes[now].pnt=pset[lft+t];
  nodes[now].mid=data[nodes[now].pnt].d[nodes[now].spt];
  if (t>=1)
  {
    nd++;
    nodes[now].left=nd;
    // for (int i=0;i<MAX_RANG_DIM;i++)
    // {
    //   nodes[nd].rect[i][0]=nodes[now].rect[i][0];
    //   nodes[nd].rect[i][1]=nodes[now].rect[i][1];
    // }
    // nodes[nd].rect[nodes[now].spt][1]=nodes[now].mid;
    build(nd,lft,lft+t-1,dep+1);
  }
  else
    nodes[now].left=-1;
  nd++;
  // for (int i=0;i<MAX_RANG_DIM;i++)
  // {
  //   nodes[nd].rect[i][0]=nodes[now].rect[i][0];
  //   nodes[nd].rect[i][1]=nodes[now].rect[i][1];
  // }
  // nodes[nd].rect[nodes[now].spt][0]=nodes[now].mid;
  nodes[now].right=nd;
  build(nd,lft+t+1,r,dep+1);
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

bool LxKDTree::pointInRange(float _point[],float _range[MAX_RANG_DIM][2])
{
  bool t=true;
  for (int i=0;i<MAX_RANG_DIM;i++)
    t=t&&(_point[i]>=_range[i][0])&&(_point[i]<=_range[i][1]);
  return t;
}

int LxKDTree::rectInRange(float _rect[MAX_RANG_DIM][2],float _range[MAX_RANG_DIM][2])
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

void LxKDTree::rangeSearch(int now,float range[MAX_RANG_DIM][2],int lst[])
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

void LxKDTree::upPoint(int _p,float _q[],int lst[],float &mmdist,int k)
{
  float dd=data[_p].dist(_q);
  if (dd>=mmdist)
    return;
  int pos=lst[0];
  while (pos>0 && data[lst[pos]].dist(_q)>dd) pos--;
  if (lst[0]<k)
    lst[0]++;
  for (int i=lst[0];i>pos+1;i--)
    lst[i]=lst[i-1];
  lst[pos+1]=_p;
  if (lst[0]>=k)//just fix the mmdist then it is radius search
    mmdist=data[lst[lst[0]]].dist(_q);
}

void LxKDTree::exp2Leaf(int now,int lst[],float &mmdist,float _q[],priority_queue<_Backtracer> &Q,int k)
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

void LxKDTree::aknns(float _q[],int lst[],int k,float sigma)
{
  lst[0]=0;
  priority_queue<_Backtracer> Q;
  float mmdist=1e200;
  exp2Leaf(1,lst,mmdist,_q,Q,k);
  while ( (!Q.empty()) && (Q.top().dist*Q.top().dist)<=mmdist/(1+sigma) )
  {
    int t=Q.top().y;
    upPoint(nodes[Q.top().x].pnt,_q,lst,mmdist,k);
    Q.pop();
    exp2Leaf(t,lst,mmdist,_q,Q,k);
  }
}


int i,j,k,t,n,m,dim;
float tpnt[6],tp[6],rp[6];
LxKDTree mytree;
int res[20];
//replace all float with llg if needed(float have only 7 dights)
int main()
{
  LXKDTree_Operating=&mytree;
  freopen("ti.in","r",stdin);
  freopen("ti.out","w",stdout);
  while (sf("%d%d",&n,&dim)!=EOF)
  {
    mytree.set(dim,n+10);
    for (i=1;i<=n;i++)
    {
      for (j=0;j<dim;j++)
      {
        sf("%d",&t);
        mytree.data[i].d[j]=t;
      }
      mytree.data[i].dim=dim;
      mytree.pset[i]=i;
    }
    mytree.build(1,1,n,0);
    sf("%d",&m);
    for (i=1;i<=m;i++)
    {
      for (j=0;j<dim;j++)
      {
        sf("%d",&t);
        tp[j]=t;
      }
      sf("%d",&k);
      pf("the closest %d points are:\n",k);
      mytree.aknns(tp,res,k,0);
      for (int o=1;o<=k;o++)
      {
        for (j=0;j<dim-1;j++)
          pf("%d ",(int)(mytree.data[res[o]].d[j]));
        pf("%d\n",(int)(mytree.data[res[o]].d[dim-1]));
      }
    }
  }
  return 0;
}
