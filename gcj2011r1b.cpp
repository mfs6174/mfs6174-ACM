/*
ID: mfs6174
PROG: b
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

using namespace std;
ifstream inf("ti.in");
ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,k,j,t,zz,zu,n,m,mm,tt,c,o,cc;
int shu[300];
vector<string> d,dang,r;
string ss,s;
char sss[15],tc;

int main()
{
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    memset(shu,0,sizeof(shu));
    d.clear();
    dang.clear();
    r.clear();
    inf>>n>>m;
    for (i=1;i<=n;i++)
    {
      inf>>s;
      d.push_back(s);
    }
    for (k=1;k<=m;k++)
    {
      inf>>s;
      mm=-1;
      c=0;
      for (i=1;i<=n;i++)
      {
        c=0;
        dang.clear();
        memset(sss,0,sizeof(sss));
        memset(shu,0,sizeof(shu));
        ss=d[i-1];
        for (j=0;j<n;j++)
          if (d[j].size()==ss.size())
          {
            dang.push_back(d[j]);
            for (o=0;o<ss.size();o++)
              shu[d[j][o]]++;
          }
        for (j=0;j<26;j++)
        {
          tc=s[j];
          if (shu[tc]>0)
          {
            bool fl=false;
            for (o=0;o<ss.size();o++)
              if (ss[o]==tc)
              {
                fl=true;
                sss[o]=tc;
              }
            if (fl)
            {
              if (cc>=ss.size())
                break;
              for (vector<string>::iterator it=dang.begin();it!=dang.end();it++)
              {
                int p;
                bool ff=false;
                for (p=0;p<ss.size();p++)
                  if (((*it)[p]!=sss[p])&&(sss[p]!=0))
                  {
                    ff=true;
                    break;
                  }
                if (ff)
                {
                  for (p=0;p<ss.size();p++)
                    shu[(*it)[p]]--;
                  it=dang.erase(it);
                  it--;
                }
              }
            }
            else
              c++;
          }
          else
            continue;
        }
        if (c>mm)
        {
          mm=c;
          tt=i;
        }
      }
      r.push_back(d[tt-1]);
    }
    ouf<<"Case #"<<zz<<':';
    for (i=1;i<=m;i++)
      ouf<<' '<<r[i-1];
    ouf<<endl;
  }
}

  
    
          
      
