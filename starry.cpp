/*
ID: mfs.dev2
PROG: starry
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

struct Kuai
{
	string s;
	int a,b,c,d,n,m,h;
};

ifstream inf("starry.in");
ofstream ouf("starry.out");
int i,j,k,t,m,n,cc,o,p,rr,dang;
char rc='a',fu[30],tu[110][110];
bool ff,ha[110][110];
int fl[110][110];
Kuai kuai[501];
map<string,int> hash;


void floodfill(int x,int y)
{
	int i,j;
	if (fl[x][y]||(tu[x][y]!='1'))
		return;
	if (ff)
	{
		ff=false;
		cc++;
		kuai[cc].a=kuai[cc].c=500;
	}
	fl[x][y]=cc;
	kuai[cc].a=min(x,kuai[cc].a);
	kuai[cc].b=max(kuai[cc].b,x);
	kuai[cc].c=min(y,kuai[cc].c);
	kuai[cc].d=max(y,kuai[cc].d);
	for (i=-1;i<=1;i++)
		for (j=-1;j<=1;j++)
			if ((x+i>0)&&(x+i<=n)&&(y+j>0)&&(y+j<=m))	
				floodfill(x+i,y+j);

}

int main()
{
	inf>>m>>n;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			inf>>tu[i][j];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			ff=true;			
			floodfill(i,j);
		}		
	for (k=1;k<=cc;k++)
	{
		kuai[k].n=kuai[k].b-kuai[k].a;
		kuai[k].m=kuai[k].d-kuai[k].c;
		string s[4]={""};
		if (kuai[k].m>kuai[k].n) //not m,n try not to use same var evenif able 
		{
			for (i=0;i<=kuai[k].n;i++)
              for (j=0;j<=kuai[k].m;j++) //think clear n m i and j
				{
					s[0]=s[0]+((fl[kuai[k].a+i][kuai[k].c+j]==k)?("1"):("0"));
					s[1]=s[1]+((fl[kuai[k].a+i][kuai[k].d-j]==k)?("1"):("0"));
					s[2]=s[2]+((fl[kuai[k].b-i][kuai[k].c+j]==k)?("1"):("0"));
					s[3]=s[3]+((fl[kuai[k].b-i][kuai[k].d-j]==k)?("1"):("0"));
				}
		}
		else
		{
			for (j=0;j<=kuai[k].m;j++)
				for (i=0;i<=kuai[k].n;i++)
				{
					s[0]=s[0]+((fl[kuai[k].a+i][kuai[k].c+j]==k)?("1"):("0"));
					s[1]=s[1]+((fl[kuai[k].a+i][kuai[k].d-j]==k)?("1"):("0"));
					s[2]=s[2]+((fl[kuai[k].b-i][kuai[k].c+j]==k)?("1"):("0"));
					s[3]=s[3]+((fl[kuai[k].b-i][kuai[k].d-j]==k)?("1"):("0"));


				}
		}
		for (i=1;i<4;i++)
			if (s[i]<s[0])
				s[0]=s[i];
        
		if (!ha[max(kuai[k].m,kuai[k].n)][min(kuai[k].m,kuai[k].n)])
		{
			ha[max(kuai[k].m,kuai[k].n)][min(kuai[k].m,kuai[k].n)]=true;
			hash[s[0]]=++rr;
			kuai[k].h=rr;
		}
		else
		{
			if (!hash.count(s[0]))
			{
				hash[s[0]]=++rr;
				kuai[k].h=rr;
			}
			else
			{
				kuai[k].h=hash[s[0]];
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (tu[i][j]=='0')
			{
				ouf<<0;
				continue;
			}
			if (!fu[kuai[fl[i][j]].h])
			{
				fu[kuai[fl[i][j]].h]=rc;
				ouf<<rc;
				rc++;	
			}
			else
			{
				ouf<<fu[kuai[fl[i][j]].h];
			}
		}
		ouf<<endl;
	}
}



