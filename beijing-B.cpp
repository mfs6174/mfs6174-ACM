#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
string s,chuan;
char c[1100000];
string ss[60000];
int i,j,k,t,n,m,st,zz,zu;
int a[150000],b[150000];
int pos,num;
void build(int u)
{
  int no;
  string s="";
  while(pos<chuan.size())
  {
    if(chuan[pos]=='(')
    {
      num++;
      ss[num]=s;
      pos++;
      if (u)
      {
        st++;
        a[st]=u;b[st]=num;
      }
      no=num;
      build(num);
      s="";
    }
    else if(chuan[pos]==')')
    {
      if (s!="")
      {
        num++;
        ss[num]=s;
        no=num;
        st++;a[st]=u;b[st]=no;
      }
      pos++;
      if (u)
      {
        st++;a[st]=no;b[st]=u;
      }
      return;
    }
    else if(chuan[pos]==',')
    {
      if (s!="")
      {
        num++;
        ss[num]=s;
        no=num;
        st++;a[st]=u;b[st]=no;
      }
      pos++;
      s="";
      if (u)
      {
        st++;a[st]=no;b[st]=u;
      }
    }
    else s+=chuan[pos++];
  }
}

int main()
{
  freopen("ti.in","r",stdin);
  scanf("%d",&zu);
  for (zz=1;zz<=zu;zz++)
  {
    scanf("%s",c);
    if ((c[strlen(c)-1])!=')')
    {
      cout<<1<<endl;
      cout<<c<<endl;
      cout<<endl;
      continue;
    }
    chuan=c;
    st=0;
    pos=0;num=0;
    build(0);
    cout<<num<<endl;
    for (i=1;i<=num;i++)
      printf("%s\n",ss[i].c_str());
    for (i=1;i<=st;i++)
      printf("%d %d\n",a[i],b[i]);
    cout<<endl;
  }
  return 0;
}

