const int maxlongint=2147483646;
const int maxn=100;

int quan[maxn][maxn],qian[maxn];
    
void floyd()
{
    int i,j,k,t;
    for (k=1;k<=n;k++)
    	for (i=1;i<=n;i++)
    		for (i=1;i<=n;i++)
    			if ((quan[i][k]!=maxlongint)&&(quan[k][j]!=maxlongint))
    			{
					t=quan[i][k]+quan[k][j];
					if (t<quan[i][j])
					{
						qian[j]=k;
						qian[k]=i;
						quan[i][j]=t;
				}
}
