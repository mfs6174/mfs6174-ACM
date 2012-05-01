/*
ID: mfs.dev2
PROG: prime3
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
ifstream inf("prime3.in");
ofstream ouf("prime3.out");
const int maxlongint=2147483647;

struct trie
{
  int xia[10],data,a;
} dian[30000];
int ct;

void zao(string &x,int d,int a)
{
  int t=a,l=x.size(),i,tt;
  for (i=0;i<l;i++)
  {
    tt=t;
    t=dian[t].xia[x[i]-48];
    if (!t)
    {
      ct++;
      dian[ct].a=ct;
      dian[tt].xia[x[i]-48]=ct;
      t=ct;
    }
  }
  dian[t].data=d;
}
  
void bian(int r[],int a)
{
  int i;
  if (dian[a].data)
    r[++(r[0])]=dian[a].data;
  for (i=0;i<=9;i++)
    if (dian[a].xia[i])
      bian(r,dian[a].xia[i]);
}
  
void qian(int x[],int r[],int a)
{
  int i,t=a;
  r[0]=0;
  for (i=1;i<=x[0];i++)
  {
    t=dian[t].xia[x[i]];
    if (!t)
      break;
  }
  if (i<=x[0])
    return;
  bian(r,t);
}

bool fl,f[101000]={false};
int pp[4000],jie[1000][6][6],tt[300],ttt[300],tttt[300],st[6],qu[6]={0,10000,1000,100,10,1};
int q[300],qq[300],qqq[300],qqqq[300],dan[6][6],qua[1000][4],ji[1000];
int i,j,k,n,g,cc=1,c,it,h,l,w,a,e,u,o;
string p[4000];
bool _15[10][10],_135[10][10][10],_124[10][10][10],_125[10][10][10],_13[10][10],_14[10][10];

string str(int x)
{
    ostringstream t;
    t<<x;
    return t.str();
}


void shai(int x,int &c)
{
  int i,j,t,ss;
  string s;
  t=(int)(sqrt(x));
  c=0;
  for (i=2;i<=t;i++)
    if (!f[i])
      for (j=2;j<=x/i;j++)
        f[i*j]=true;
  t=0;
  for (i=10000;i<=x;i++)
    if (!f[i])
    {
      s=str(i);
      ss=0;
      for (j=0;j<5;j++)
        ss+=s[j]-48;
      if (ss!=n)
        continue;
      c++;
      pp[c]=i;
      p[c]=s;
      f[i]=true;
      zao(s,c,0);
      _15[s[0]-48][s[4]-48]=true;
      _13[s[0]-48][s[2]-48]=true;
      _14[s[0]-48][s[3]-48]=true;
      _135[s[0]-48][s[2]-48][s[4]-48]=true;
      _125[s[0]-48][s[1]-48][s[4]-48]=true;
      _124[s[0]-48][s[1]-48][s[3]-48]=true;
    }
    else
      f[i]=false;
}

int main()
{
  dian[0].a=0;
  inf>>n>>g;
  shai(100000,c);
  st[0]=1;st[1]=g;
  qian(st,tt,0);
  dan[1][1]=g;
  for (i=1;i<=tt[0];i++)
  {
    for (it=2;it<=5;it++)
      if (!(dan[1][it]=p[tt[i]][it-1]-48))
        break;
    if (it<=5)
      continue;
    for (k=1;k<=tt[0];k++)
    {
      if (!_15[dan[1][5]][p[tt[k]][4]-48])
        continue;
      if (!_13[dan[1][3]][p[tt[k]][2]-48])
        continue;
      if (!_14[dan[1][4]][p[tt[k]][3]-48])
        continue;
      for (it=2;it<=5;it++)
        dan[it][it]=p[tt[k]][it-1]-48;
      for (j=1;j<=tt[0];j++)
      {
        if (!_15[p[tt[j]][4]-48][dan[5][5]])
          continue;
        if (!_13[p[tt[j]][2]-48][dan[3][3]])
          continue;
        if (!_14[p[tt[j]][3]-48][dan[4][4]])
          continue;
        if (!_135[p[tt[j]][4]-48][dan[3][3]][dan[1][5]])
          continue;
        for (it=2;it<=5;it++)
          if (!(dan[it][1]=p[tt[j]][it-1]-48))
            break;
        if (it<6)
          continue;
        st[0]=2;
        st[1]=dan[2][1];st[2]=dan[2][2];
        qian(st,ttt,0);
        st[1]=dan[1][2];
        qian(st,tttt,0);
        for (h=1;h<=ttt[0];h++)
        {
          if (!_124[dan[1][4]][p[ttt[h]][3]-48][dan[4][4]])
            continue;
          if (!_125[dan[1][5]][p[ttt[h]][4]-48][dan[5][5]])
            continue;
          for (it=3;it<=5;it++)
            dan[2][it]=p[ttt[h]][it-1]-48;
          for (l=1;l<=tttt[0];l++)
          {
            if (!_124[dan[4][1]][p[tttt[l]][3]-48][dan[4][4]])
              continue;
            if (!_125[dan[5][1]][p[tttt[l]][4]-48][dan[5][5]])
              continue;
            for (it=2;it<=5;it++)
              dan[it][2]=p[tttt[l]][it-1]-48;
            w=0;
            for (it=5;it>=1;it--)
              w+=dan[it][6-it]*qu[6-it];
            if ((!f[w]))
              continue;
            st[0]=3;
            st[1]=dan[3][1];st[2]=dan[3][2];st[3]=dan[3][3];
            qian(st,q,0);
            st[1]=dan[1][3];st[2]=dan[2][3];
            qian(st,qq,0);
            for (a=1;a<=q[0];a++)
            {
              for (it=4;it<=5;it++)
                dan[3][it]=p[q[a]][it-1]-48;
              for (e=1;e<=qq[0];e++)
              {
                for (it=4;it<=5;it++)
                  dan[it][3]=p[qq[e]][it-1]-48;
                st[0]=4;
                st[1]=dan[4][1];st[2]=dan[4][2];st[3]=dan[4][3];st[4]=dan[4][4];
                qian(st,qqq,0);
                st[1]=dan[1][4];st[2]=dan[2][4];st[3]=dan[3][4];
                qian(st,qqqq,0);
                for (u=1;u<=qqq[0];u++)
                {
                  dan[4][5]=p[qqq[u]][4]-48;
                  for (o=1;o<=qqqq[0];o++)
                  {
                     dan[5][4]=p[qqqq[o]][4]-48;
                     w=0;
                     for (it=1;it<=5;it++)
                       w+=dan[it][5]*qu[it];
                     if (!f[w])
                       continue;
                     w=0;
                     for (it=5;it>=1;it--)
                       w+=dan[5][6-it]*qu[6-it];
                     if (!f[w])
                       continue;
                     for (w=1;w<=5;w++)
                       for (it=1;it<=5;it++)
                         jie[cc][w][it]=dan[w][it];
                     cc++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (cc<2)
  {
    ouf<<"NONE"<<endl;
    return 0;
  }
  cc--;
  for (i=1;i<=cc;i++)
  {
    ji[i]=i;
    for (j=1;j<=3;j++)
      for (k=1;k<=5;k++)
        qua[i][j]+=jie[i][j][k]*qu[k];
  }
  for (i=1;i<cc;i++)
    for (j=i+1;j<=cc;j++)
    {
      fl=false;
      for (k=1;k<=3;k++)
        if (qua[ji[j]][k]<qua[ji[i]][k])
        {
          fl=true;
          break;
        }
        else
          if (qua[ji[j]][k]!=qua[ji[i]][k])
            break;
      if (fl)
      {
        it=ji[i];
        ji[i]=ji[j];
        ji[j]=it;
      }
    }
  for (k=1;k<=cc;k++)
  {
    for (i=1;i<=5;i++)
    {
      for (j=1;j<=5;j++)
        ouf<<jie[ji[k]][i][j];
      ouf<<endl;
    }
    if (k!=cc)
      ouf<<endl;
  }
}
