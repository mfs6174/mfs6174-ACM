
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXL=2100000;
const int MOD=9875321;

struct node
{
    node *c[2],*f;
    int dat,size,hash;
}*root,SC[MAXL],*null;
char s[MAXL];
int m,SS;
int d[MAXL];
int n1,n2;

void Debug(node *v)
{
    if (v==null) return;
    Debug(v->c[0]);
    printf("%d ",v->dat);
    Debug(v->c[1]);
}

node *New(int d,int h,node *fa)
{
    node *e=SC+ ++SS;
    e->size=1,e->f=fa;
    e->c[1]=e->c[0]=null;
    e->dat=d,e->hash=h;
    return e;
}

void Update(node *v)
{
    if (v==null) return;
    v->size=v->c[0]->size+v->c[1]->size+1;
    v->hash=(long long)(v->c[0]->hash+(long long)v->dat*d[(v->c[0]->size+1)]+(long long)v->c[1]->hash*d[(v->c[0]->size+2)])%MOD;
}

void Prepare()
{
    SS=-1;
    null=NULL;
    null=New(0,0,NULL);
    null->size=0;
    root=New(0,0,null);
    root->c[1]=New(0,0,root);
    Update(root);
}

void Rotate(node *x,int o)
{
    node *y=x->f;
    y->c[o]=x->c[!o];
    y->c[o]->f=y;
    x->f=y->f;
    if (y->f->c[0]==y)
        y->f->c[0]=x;
    else
        y->f->c[1]=x;
    x->c[!o]=y;
    y->f=x;
    if (y==root) root=x;
    Update(y);
}

void Splay(node *x,node *fa)
{
    while (x->f!=fa)
        if (x->f->f==fa)
            if (x->f->c[0]==x)
                Rotate(x,0);
            else
                Rotate(x,1);
        else
            if (x->f->f->c[0]==x->f)
                if (x->f->c[0]==x)
                    Rotate(x->f,0),Rotate(x,0);
                else
                    Rotate(x,1),Rotate(x,0);
            else    
                if (x->f->c[1]==x)
                    Rotate(x->f,1),Rotate(x,1);
                else
                    Rotate(x,0),Rotate(x,1);
    Update(x);
}

void Select(int k,node *fa)
{
    node *t=root;
    while (1)
    {
        if (k==t->c[0]->size+1) break;
        if (k<t->c[0]->size+1) t=t->c[0];
        if (k>t->c[0]->size+1) k-=t->c[0]->size+1,t=t->c[1];
    }
    Splay(t,fa);
}

int Hash(int x,int y)
{
    Select(x,null),Select(y+2,root);
    return root->c[1]->c[0]->hash;
}

void Ask(int x,int y)
{
  if (s[x-1]!=s[y-1])
  {
    printf("%d\n",0);
    return;
  }
  if (s[x]!=s[y])
  {
    printf("%d\n",1);
    return;
  }
    int ans=0,n=root->size-2;
    for (int i=1<<20;i;i>>=1)
        if (x+i-1<=n && y+i-1<=n && Hash(x,x+i-1)==Hash(y,y+i-1))
            ans+=i,x+=i,y+=i;
    printf("%d\n",ans);
}

void Ins(int x,char ch)
{
    Select(x+1,null),Select(x+2,root);
    root->c[1]->c[0]=New(ch-'a',ch-'a',root->c[1]);
    Splay(root->c[1]->c[0],null);
    //Debug(root),printf("\n");
}

void Rep(int x,char ch)
{
    Select(x,null),Select(x+2,root);
    node *v=root->c[1]->c[0];
    v->dat=ch-'a';
    v->hash=(long long)(v->c[0]->hash+(long long)v->dat*d[(v->c[0]->size+1)]+(long long)v->c[1]->hash*d[(v->c[0]->size+2)])%MOD;
    //Debug(root),printf("\n");
}

void Init()
{
    node *z,*t;
    Prepare();
    scanf("%s",s);
    n1=strlen(s);
    s[n1]='$';
    scanf("%s",s+n1+1);
    int n=strlen(s);
    n2=n-n1-1;
    z=t=New(s[0]-'a',s[0]-'a',null);
    for (int i=1;i<n;++i)
        z=z->c[1]=New(s[i]-'a',s[i]-'a',z);
    root->c[1]->c[0]=t,t->f=root->c[1];
    Splay(z,null);
    //Debug(root),printf("\n");
}

void Solve()
{
    char ch; int x,y;
    int tt;
    scanf("%d",&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d",&tt);
        if (tt==2)
        {
          scanf("%d",&x);
          x++;
          Ask(x,n1+1+x);
        }
        else
        {
          scanf("%d%d %c",&y,&x,&ch);
          x++;
          if (y==1)
            Rep(x,ch);
          else
            Rep(n1+1+x,ch);
        }
    }
}

int zz,zu;

int main()
{
    freopen("ti.in","r",stdin);
    scanf("%d",&zu);
    d[1]=1;
    for (int i=2;i<=2000100;++i)
      d[i]=(d[i-1]*27)%MOD;
    for (zz=1;zz<=zu;zz++)
    {
      printf("Case %d:\n",zz);
      Init();
      Solve();
    }
    return 0;
}
