#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

string h[5]={"","HongTao","HeiTao","FangPian","MeiHua"};
string d[14]={"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
ofstream outf("out.out");

struct pai{
            int hua,dian;
        };
class puke{
            public:
                void xin()
                {
                    int i,j;
                    pai t;
                    for (i=1;i<=4;i++)
                        for (j=1;j<=13;j++)
                        {
                            t.hua=i;
                            t.dian=j;
                            a.push_back(t);
                        }
                    t.hua=0;t.dian=0;
                    a.push_back(t);
                    t.dian=1;
                    a.push_back(t);
                }
                void xipai()
                {
                    int i,j,n,k;
                    pai t;
                    n=a.size();
                    srand(time(NULL));
                    for (k=1;k<=100;k++)
                    {
                        i=rand()%n;
                        j=rand()%n;
                        t=a[i];
                        a[i]=a[j];
                        a[j]=t;
                    }
                }
                void dayin()
                {
                    vector<pai>::iterator i;
                    for (i=a.begin();i!=a.end();i++)
                    {
                        if (!(*i).hua)
                            (*i).dian?(outf<<"DaHu "):(outf<<"XiaoHu ");
                        else
                            outf<<h[(*i).hua]<<' '<<d[(*i).dian]<<' ';
                    }
                    outf<<endl;
                }
                void fapai(puke &x,puke &y)
                {
                    int i;
                    for (i=1;i<=27;i++)
                    {
                        x.a.push_back(*(a.end()-1));
                        a.erase(a.end()-1);
                        y.a.push_back(*(a.end()-1));
                        a.erase(a.end()-1);
                    }
                }
                vector<pai> a;     
        };
        
int main()
{
    puke yifu,jia,yi;
    yifu.xin();
    yifu.xipai();
    yifu.fapai(jia,yi);
    outf<<"P1's card is"<<endl;
    jia.dayin();
    outf<<"P2's cards is"<<endl;
    yi.dayin();
}
        
