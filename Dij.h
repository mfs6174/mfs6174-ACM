const int maxlongint=2147483646;

int quan[101][101],duan[101];
    
void dijie(int x)
{
    int i,j,k,mm;
    bool f[101]={false};
    for (i=1;i<=n;i++)
        duan[i]=quan[x][i];
    duan[x]=0;
    f[x]=true;
    for (i=1;i<n;i++)
    {
        mm=maxlongint;
        for (j=1;j<=n;j++)
            if ((!f[j])&&(duan[j]<mm))
            {
                k=j;
                mm=duan[j];
            }
        f[k]=true;
        for (j=1;j<=n;j++)
            if ((quan[k][j]!=maxlongint)&&(duan[k]+quan[k][j]<duan[j]))
                duan[j]=quan[k][j]+duan[k];
    }
}
