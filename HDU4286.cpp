/*
  ID: mfs6174
  email: mfs6174@gmail.com
  PROG: splay template(http://www.lydsy.com/JudgeOnline/problem.php?id=1500)
  LANG: C++
*/
#pragma comment(linker, "/STACK:1024000000,1024000000") 
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

const int inf=1-maxlongint;//if this can be set far from overflow,sad can be just add
struct{int l,r,size,val,rev;}a[1000010];  
int L[1000010],R[1000010],q[3000000];  
int n,m,root,l,r,i;  
char str[10];  
  
// inline void cover(int x,int y)  
// {  
//   a[x].val=a[x].cov=y;  //what the cover do--this is fuzhi..can change
//   a[x].sum=y*a[x].size;  
//   a[x].dat=a[x].lmax=a[x].rmax=max(y,a[x].sum);  
// }

inline int sad(int x,int y)
{
  if (x==inf||y==inf)
    return inf;
  else
    return x+y;
}

inline void update(int x) //change this to work for a certain problem 
{  
  a[x].size=a[a[x].l].size+a[a[x].r].size+1;  //this is necessary
  // a[x].sum=sad(sad(a[a[x].l].sum,a[a[x].r].sum),a[x].val);
  // a[x].lmax=max(max(a[a[x].l].lmax,sad(a[a[x].l].sum,a[x].val)),sad(sad(a[a[x].l].sum,a[x].val),a[a[x].r].lmax));
  // a[x].rmax=max(max(a[a[x].r].rmax,sad(a[a[x].r].sum,a[x].val)),sad(sad(a[a[x].r].sum,a[x].val),a[a[x].l].rmax));
  // a[x].dat=max(max(max(a[a[x].l].dat,a[a[x].r].dat),max(sad(a[a[x].l].rmax,a[x].val),sad(a[a[x].r].lmax,a[x].val))),max(a[x].val,sad(sad(a[a[x].l].rmax,a[a[x].r].lmax),a[x].val)));  
}  
  
inline void spread(int x)  
{  
  if(!x)return;  
  if(a[x].rev)  
  {  
    if(int y=a[x].l) {a[y].rev^=1; swap(a[y].l,a[y].r); }  
      if(int y=a[x].r) {a[y].rev^=1; swap(a[y].l,a[y].r); }  
    a[x].rev=0;  
  }  
  // if(a[x].cov!=inf)  
  // {  
  //   if(a[x].l) cover(a[x].l,a[x].cov);  
  //   if(a[x].r) cover(a[x].r,a[x].cov);  
  //   a[x].cov=inf;  
  // }
  
}  
  
void zig(int &x)  
{  
  int y=a[x].l; a[x].l=a[y].r; a[y].r=x;  
  update(x); update(y); x=y;  
}  
  
void zag(int &x)  
{  
  int y=a[x].r; a[x].r=a[y].l; a[y].l=x;  
  update(x); update(y); x=y;  
}  
  
void splay(int &x,int y)  
{  
  if(!x)return;  
  L[0]=R[0]=0;  
  while(1)  
  {  
    spread(x),spread(a[x].l),spread(a[x].r);  
    int temp=a[a[x].l].size+1;  
    if(y==temp||(y<temp&&!a[x].l)||(y>temp&&!a[x].r)) break;  
    if(y<temp)  
    {  
      if(a[a[x].l].l&&y<=a[a[a[x].l].l].size) {zig(x); if(!a[x].l)break;}  
      R[++R[0]]=x; x=a[x].l;  
    }  
    else{  
      y-=temp;  
      int temp=a[a[a[x].r].l].size+1;  
      if(a[a[x].r].r&&y>temp) {y-=temp; zag(x); if(!a[x].r)break;}  
      L[++L[0]]=x; x=a[x].r;  
    }  
  }  
  L[L[0]+1]=a[x].l; R[R[0]+1]=a[x].r;  
  for(int i=L[0];i>0;i--) {a[L[i]].r=L[i+1]; update(L[i]);}  
  for(int i=R[0];i>0;i--) {a[R[i]].l=R[i+1]; update(R[i]);}  
  a[x].l=L[1]; a[x].r=R[1]; update(x);  
}  
  
int build(int l,int r) 
{ 
  if(l>r)return 0; 
  int mid=(l+r)/2; 
  a[q[mid]].l=build(l,mid-1); 
  a[q[mid]].r=build(mid+1,r); 
  update(q[mid]); 
  return q[mid]; 
} 
  
void INSERT(int pos,int m,int dt[])  
{ 
  int i;  
  //scanf("%d%d",&pos,&m);  
  ++pos;  
  splay(root,pos);  
  splay(a[root].r,1);  
  for(i=0;i<m;i++)  
  {  
    a[q[l+i]].val=dt[i];  
    a[q[l+i]].l=a[q[l+i]].r=a[q[l+i]].rev=0; 
  } 
  a[a[root].r].l=build(l,l+m-1); 
  l+=m; 
  update(a[root].r); update(root);  
  splay(root,pos+m);  
}  
      
void release(int x)  
{  
  if(!x)return;  
  q[++r]=x;  
  release(a[x].l);  
  release(a[x].r);  
}  
      
void DELETE(int pos,int m)  
{  
  //    scanf("%d%d",&pos,&m);  
  ++pos;  
  splay(root,pos+m);  
  splay(a[root].l,pos-1);  
  release(a[a[root].l].r);  
  a[a[root].l].r=0;  
  update(a[root].l);  
  update(root);  
}  
      
void REVERSE(int x,int y)  
{  
  //scanf("%d%d",&x,&y);  
  ++x;  
  splay(root,x+y);  
  splay(a[root].l,x-1);  
  a[y=a[a[root].l].r].rev^=1;  
  swap(a[y].l,a[y].r);  
  //swap(a[y].lmax,a[y].rmax);  
  update(a[root].l);  
  update(root);  
}  
      
bool fl;
void ITERATE(int x)
{
  if (!x)
    return;
  spread(x);
  ITERATE(a[x].l);
  if (a[x].val!=inf)
  {
    if (fl)
      pf(" ");
    else
      fl=true;
    pf("%d",a[x].val);
  }
  ITERATE(a[x].r);
}

int in1,in2,idt[5],in3;
int zz,zu,PL,PR;

int main()  
{
  //freopen("ti.in","r",stdin);
  cin>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(a,0,sizeof(a));
    cin>>n;  
    a[1].size=1;
    a[1].val=a[n+2].val=inf;  
    for(i=2;i<=n+1;i++) 
    {scanf("%d",&a[i].val); }  
    l=1; r=1100000;  //r max big enough
    for(i=l;i<=r;i++) q[i]=i; 
    root=build(1,n+2); l=n+3;
    cin>>PL>>PR>>m;
    for(i=0;i<m;i++)  
    {  
      scanf("%s",str);  
      if(str[0]=='I')
      {
        sf("%s",str);
        sf("%d",&idt[0]);
        if (str[0]=='L')
        {
          INSERT(PL-1,1,idt);
          if (PR>=PL)
            PR++;
        }
        else
        {
          INSERT(PR,1,idt);
          PR++;
        }
      }
      else if(str[0]=='D')
      {
        sf("%s",str);
        if (str[0]=='L')
        {
          DELETE(PL,1);
          if (PR>=PL)
            PR--;
        }
        else
        {
          DELETE(PR,1);
          PR--;
        }
      }
      else if(str[0]=='R')
      {
        REVERSE(PL,PR-PL+1);
      }
      else if(str[0]=='M')
      {
        int tp;
        if (str[4]=='L')
          tp=-1;
        else
          tp=1;
        sf("%s",str);
        if (str[0]=='L')
          PL+=tp;
        else
          PR+=tp;
      }  
    }
    fl=false;
    ITERATE(root);
    pf("\n");
  }
  return 0;  
}
