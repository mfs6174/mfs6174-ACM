#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include<cstring>

using namespace std;

const int maxlongint=2147483647;
#define sf scanf

int i,j,k,t,n,m,zz,zu,dou,tri;
int heng[1200],shu[1200],jiao[1100][1100];
char tc,ttc;
int yz[1100][3],xy[1100][3],xz[1100][3];
int cyz,cxy,cxz;

void go(int &x,int &y,int &z,char s[])
{
    switch(s[0]){
        case 'X':
            x=atoi(s+2);
            return;
        case 'Y':
            y=atoi(s+2);
            return ;
        case 'Z':
            z=atoi(s+2);
            return;
    }
}

int main()
{
	sf("%d",&zu);
	for (zz=1;zz<=zu;zz++)
	{
		memset(heng,0,sizeof(heng));
		memset(shu,0,sizeof(shu));
		memset(jiao,0,sizeof(jiao));
		scanf("%d%d",&n,&m);
		cxy=cyz=cxz=0;
		for (i=1;i<=m;i++)
		{
			char s[123],*q;
     scanf("%s",s);q=s;
     while(*q!=',')q++;
     *q=0;q++;
     int x,y,z;
     z=y=x=-1;
     go(x,y,z,s);
     go(x,y,z,q);
			if (x==-1)
			{
				  cyz++;
				   yz[cyz][1]=y;
				   yz[cyz][2]=z;
			}
			if (y==-1)
			{
				cxz++;
				xz[cxz][1]=x;
				xz[cxz][2]=z;
			}
			if (z==-1)
			{
				cxy++;
				xy[cxy][1]=x;
				xy[cxy][2]=y;
			}
		}
		dou=tri=0;
		for (i=1;i<=cxz;i++)
		{
			heng[xz[i][1]]++;
			for (j=1;j<=cyz;j++)
				if (xz[i][2]==yz[j][2])
				{	
					dou++;
					jiao[xz[i][1]][yz[j][1]]++;
				}
		}
		for (i=1;i<=cyz;i++)
			shu[yz[i][1]]++;
		for (i=1;i<=cxy;i++)
		{
			tri+=jiao[xy[i][1]][xy[i][2]];
			dou+=heng[xy[i][1]]+shu[xy[i][2]];
		}
				  
				    	
			
