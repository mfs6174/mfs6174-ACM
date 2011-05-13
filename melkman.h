int cha(DIAN a,DIAN b,DIAN c)
{
double x1,x2,y1,y2;
x1=b.x-a.x;
y1=b.y-a.y;
x2=c.x-b.x;
y2=c.y-b.y;
return x1*y2-x2*y1;
}

int melkman()
{
int bot=n-1,top=n,i,j,cnt;
int t;
int dui[21000];
dui[top++]=0;
dui[top++]=1;
for(i=2;i<N;i++)
{
   if(cha(point[dui[top-2]],point[dui[top-1]],point[i])!=0)
   {
    break;
   }
   dui[top-1]=i;
}
dui[bot--]=i;
dui[top++]=i;
if(cha(point[dui[N]],point[dui[N+1]],point[dui[N+2]])<0)
{
   t=dui[N];
   dui[N]=dui[N+1];
   dui[N+1]=t;
}
for(i++;i<N;i++)
{
   if(cha(point[dui[bot+1]],point[dui[bot+2]],point[i])>0&&cha(point[dui[top-2]],point[dui[top-1]],point[i])>0)
   {
    continue;
   }
   while(cha(point[dui[bot+1]],point[dui[bot+2]],point[i])<=0)
   {
    bot++;
   }
   dui[bot--]=i;
   while(cha(point[dui[top-2]],point[dui[top-1]],point[i])<=0)
   {
    top--;
   }
   dui[top++]=i;
  
}
cnt=0;
for(i=bot+1;i<top;i++)
{
   ans[cnt++]=dui[i];
}
return cnt;
}
