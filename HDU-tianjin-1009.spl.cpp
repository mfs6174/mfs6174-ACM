#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int IN[500010];
const int INF=1<<28;
 
struct Node
{
    Node *pre,*ch[2];
    bool rev,same;
    int sz,val,sum,MaxM,MaxL,MaxR;
}*root,buf[500010],*null;
 
Node *stack[500010];
int idx,N,M,top;
 
Node *addNode(int val)
{
    Node *p;
    if(top)p=stack[--top];
    else p=&buf[idx++];
    p->rev=p->same=false;
    p->sz=1;
    p->sum=p->val=p->MaxM=p->MaxL=p->MaxR=val;
    p->ch[0]=p->ch[1]=p->pre=null;
    return p;
}
 
inline void PushDown(Node *p)
{
    if(p==null||!p)return;
    if(p->rev)
    {
        swap(p->ch[0],p->ch[1]);
        if(p->ch[0]!=null)p->ch[0]->rev=!p->ch[0]->rev;
        if(p->ch[1]!=null)p->ch[1]->rev=!p->ch[1]->rev;
        swap(p->MaxL,p->MaxR);
        p->rev=false;
    }
    if(p->same)
    {
        p->sum=p->sz*p->val;
        p->MaxM=p->MaxL=p->MaxR=max(p->val,p->sum);
        if(p->ch[0]!=null)
        {
            p->ch[0]->val=p->val;
            p->ch[0]->same=true;
        }
        if(p->ch[1]!=null)
        {
            p->ch[1]->val=p->val;
            p->ch[1]->same=true;
        }
        p->same=false;
    }
}
 
inline void Update(Node *p)
{
    if(p==null)return;
    PushDown(p);
    PushDown(p->ch[0]);
    PushDown(p->ch[1]);
    p->sz=p->ch[0]->sz+p->ch[1]->sz+1;
    p->sum=p->val+p->ch[0]->sum+p->ch[1]->sum;
    p->MaxL=max(p->ch[0]->MaxL,p->ch[0]->sum+p->val+max(0,p->ch[1]->MaxL));
    p->MaxR=max(p->ch[1]->MaxR,p->ch[1]->sum+p->val+max(0,p->ch[0]->MaxR));
    p->MaxM=max(max(p->ch[1]->MaxL,0)+p->val+max(p->ch[0]->MaxR,0),max(p->ch[0]->MaxM,p->ch[1]->MaxM));
}
 
void Init()
{
    idx=top=0;
    null=addNode(-INF);
    null->sz=null->sum=0;
    root=addNode(-INF);
    root->sum=0;
    Node *p;
    p=addNode(-INF);
    root->ch[1]=p;
    p->pre=root;
    p->sum=0;
    Update(root->ch[1]);
    Update(root);
}
 
void Rotate(Node *x,int c)
{
    Node *y=x->pre;
    PushDown(y);PushDown(x);
    y->ch[!c]=x->ch1;
    if(x->ch1!=null)
        x->ch1->pre=y;
    x->pre=y->pre;
    if(y->pre!=null)
        if(y->pre->ch[0]==y)
            y->pre->ch[0]=x;
        else
            y->pre->ch[1]=x;
    x->ch1=y;y->pre=x;
    if(y==root)root=x;
    Update(y);
}
 
void Splay(Node *x,Node *f)
{
    PushDown(x);
    while(x->pre!=f)
    {
        Node *y=x->pre,*z=y->pre;
        if(x->pre->pre==f)
            Rotate(x,x->pre->ch[0]==x);
        else
        {
            if(z->ch[0]==y)
                if(y->ch[0]==x)
                    Rotate(y,1),Rotate(x,1);
                else
                    Rotate(x,0),Rotate(x,1);
            else
                if(y->ch[1]==x)
                    Rotate(y,0),Rotate(x,0);
                else
                    Rotate(x,1),Rotate(x,0);
        }
    }
    Update(x);
}
 
Node* Select(int kth)
{
    int tmp;
    Node *t=root;
    while(1)
    {
        PushDown(t);
        tmp=t->ch[0]->sz;
        if(tmp+1==kth)break;
        if(kth<=tmp)
            t=t->ch[0];
        else
        {
            kth-=tmp+1;
            t=t->ch[1];
        }
    }
    return t;
}
 
Node * Build(int l,int r)
{
    if(l>r)return null;
    int mid=(l+r)>>1;
    Node *p=addNode(IN[mid]);
    p->ch[0]=Build(l,mid-1);
    if(p->ch[0]!=null)
        p->ch[0]->pre=p;
    p->ch[1]=Build(mid+1,r);
    if(p->ch[1]!=null)
        p->ch[1]->pre=p;
    Update(p);
    return p;
}
 
void Recycle(Node *p)
{
    if(p->ch[0]!=null)Recycle(p->ch[0]);
    if(p->ch[1]!=null)Recycle(p->ch[1]);
    stack[top++]=p;
}
 
void Delete(int pos,int tot)
{
    Splay(Select(pos-1),null);
    Splay(Select(pos+tot),root);
    if(root->ch[1]->ch[0]!=null)
    {
        Recycle(root->ch[1]->ch[0]);
        root->ch[1]->ch[0]=null;
    }
    Update(root->ch[1]);Update(root);
    Splay(root->ch[1],null);
}
 
void Insert(int pos,int tot)
{
    for(int i=1;i<=tot;i++)
        scanf("%d",IN+i);
    Node *troot=Build(1,tot);
    Splay(Select(pos),null);
    Splay(Select(pos+1),root);
    root->ch[1]->ch[0]=troot;
    troot->pre=root->ch[1];
    Update(root->ch[1]);Update(root);
    Splay(troot,null);
}
 
void Reverse(int pos,int tot)
{
    Splay(Select(pos-1),null);
    Splay(Select(pos+tot),root);
    if(root->ch[1]->ch[0]!=null)
    {
        root->ch[1]->ch[0]->rev=!root->ch[1]->ch[0]->rev;
        Splay(root->ch[1]->ch[0],null);
    }
}
 
void GetSum(int pos,int tot)
{
    Splay(Select(pos-1),null);
    Splay(Select(pos+tot),root);
    printf("%d\n",root->ch[1]->ch[0]->sum);
}
 
void MakeSame(int pos,int tot)
{
    int c;
    scanf("%d",&c);
    Splay(Select(pos-1),null);
    Splay(Select(pos+tot),root);
    root->ch[1]->ch[0]->val=c;
    root->ch[1]->ch[0]->same=true;
    Splay(root->ch[1]->ch[0],null);
}
 
void MaxSum()
{
    Splay(Select(1),null);
    Splay(Select(root->sz),root);
    printf("%d\n",root->ch[1]->ch[0]->MaxM);
}
 
void T(Node *p)
{
    if(p->ch[0]!=null)T(p->ch[0]);
    printf("%d ",p->val);
    if(p->ch[1]!=null)T(p->ch[1]);
}
 
int main()
{
    scanf("%d%d",&N,&M);
    Init();
    for(int i=1;i<=N;i++)
        scanf("%d",IN+i);
    Node *troot=Build(1,N);
    root->ch[1]->ch[0]=troot;
    troot->pre=root->ch[1];
    Update(root->ch[1]);
    Update(root);
    while(M--)
    {
        char com[20];
        scanf("%s",com);
        int a,b;
        if(com[2]!='X')
            scanf("%d%d",&a,&b);
        switch(com[2])
        {
            case 'S':Insert(a+1,b);break;
            case 'L':Delete(a+1,b);break;
            case 'V':Reverse(a+1,b);break;
            case 'K':MakeSame(a+1,b);break;
            case 'T':GetSum(a+1,b);break;
            case 'X':MaxSum();break;
        }
    }
    return 0;
}
