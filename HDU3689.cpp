#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

#define NODE 500
#define CH 28
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
const long long maxlongint =2147483647;
class ZHEN
{
public:
    double z[300][300];
    long long dx,dy;
    ZHEN operator *(const ZHEN &x)
    {
        ZHEN r;
        r.dx=dx;r.dy=dy;
        long long i,j,k;
        for(i=1;i<=r.dx;i++)
            for(j=1;j<=r.dy;j++)
            {
                r.z[i][j]=0;
                for(k=1;k<=x.dx;k++)
                    r.z[i][j]=(r.z[i][j]+(z[i][k]*x.z[k][j]));
            }
        return r;
    }
    void E(long long x,long long y)
    {
        dx=x;dy=y;
        long long i,j;
        for(i=1;i<=dx;i++)
            z[i][i]=1;
    }
    ZHEN power(long long e)
    {
        ZHEN tmp=(*this),rr;
        if(e==1) return *this;
        memset(rr.z,0,sizeof(rr.z));
        rr.E(dx,dy);
        while(e)
        {
            if(e&1)
                rr=rr*tmp;
            tmp=tmp*tmp;
            e=e>>1;
        }
        return rr;
    }
};

long long i,j,k,n,t,m;
long long c,cc;
long long zh[NODE][CH+5];
long long shu[NODE],fail[NODE],sn[300],q[NODE];

char ss[1000],ke[30];
ZHEN mm,rr;
bool ff[300];
double res;
double gai[1000];
void init()
{
    fail[0]=0;
    memset(zh[0],0,sizeof(zh[0]));
    cc=0;
    res=0;
}

void ins(const char *s,long long d)
{
    long long p=0;
    for(;*s;s++)
    {
        long long t=sn[*s];
        if(!zh[p][t])
        {
            cc++;
            memset(zh[cc],0,sizeof(zh[cc]));
            shu[cc]=0;
            zh[p][t]=cc;
        }
        p=zh[p][t];
    }
    shu[p]=d;
}

void acinit()
{
    long long *s=q,*e=q,i;
    for(i=0;i<=CH;i++)
        if(zh[0][i])
        {
            fail[zh[0][i]]=0;
            *e++=zh[0][i];
        }
    while(s!=e)
    {
        long long p=*s++;
        for(i=0;i<=CH;i++)
        {
            if(zh[p][i])
            {
                long long v=zh[p][i];
                *e++=v;
                fail[v]=zh[fail[p]][i];
            }
            else
                zh[p][i]=zh[fail[p]][i];
        }
    }
}

void make(long long p)
{
    if(ff[p])
        return ;
    ff[p]=true;
    char*s=ke;
    long long tt;
    for(;*s;s++)
    {
        tt=zh[p][sn[*s]];
        bool fl=false;
        long long t=tt;
        while(t)
        {
            if(fl)
                break;
            if(shu[t])
                fl=true;
            t=fail[t];
        }
        if(!fl)
        {
            mm.z[p+1][tt+1]+=gai[sn[*s]];
            make(tt);
        }
    }
}
ZHEN tmp;

int main()
{
   freopen("ti.in","r",stdin);
   while (scanf("%lld%lld",&n,&m)!=EOF&&(n||m))
   {
       init();
       ke[n]=0;
       getchar();
        for (i=1;i<=n;i++)
        {
            scanf("%c%lf",&ke[i-1],&gai[i]);
            sn[ke[i-1]]=i;
            getchar();
        }
        scanf("%s",ss);
        ins(ss,1);
        acinit();
        memset(ff,0,sizeof(ff));
        mm=tmp;
        make(0);
        mm.dx=mm.dy=cc+1;
        rr=mm.power(m);
        for (i=1;i<=cc;i++)
            if (ff[i])
                res+=rr.z[1][i+1];
        res+=rr.z[1][1];res=1.0-res;
        res*=100;
        printf("%.2lf%%\n",res);
   }
   return 0;
}
