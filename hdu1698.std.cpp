#include<iostream>

using namespace std;

const int maxsize = 50000;

struct Stree

{

       int left, right, mid;       

       int cover;

};

Stree tree[6*maxsize+1];

int c;

void Creat(int l, int r, int i)

{

     tree[i].left = l;

     tree[i].right = r;

     tree[i].cover = 1;

     tree[i].mid = (l + r) >> 1;

     if (l == r)return ;

     int t = i << 1;

     Creat(l, tree[i].mid, t);

     Creat(tree[i].mid+1, r, t+1);     

}

void Insert(int num, int i, int j)

{

     int a = tree[num].left, b = tree[num].right;

     if (tree[num].cover == c)return ;

     if (i == a && j == b){

        tree[num].cover = c;

        return ;   

     }

     int t = num << 1;     

     if (tree[num].cover != -1){

        tree[t].cover = tree[t+1].cover = tree[num].cover;                          

     }

     tree[num].cover = -1;

     if (j <= tree[num].mid)Insert(t, i, j);

        else if (i > tree[num].mid)Insert(t+1, i, j);

             else {

                  Insert(t, i, tree[num].mid);

                  Insert(t+1, tree[num].mid+1, j);     

             }

}

int counter(int num)

{

    int t = num << 1;

     if (tree[num].cover > 0){return (tree[num].right - tree[num].left+1)*tree[num].cover;}

     return counter(t) + counter(t+1);                 

}

int main()

{

    int t;

    scanf("%d", &t);

    int ss = 0;

    while (t--){

          int n;

          scanf("%d", &n);

          Creat(1, n, 1);

          int nn;

          scanf("%d", &nn);

          for (int i = 1; i <= nn; i ++){

              int a, b;

              scanf("%d %d %d", &a, &b, &c);

              Insert(1, a, b);

            // cout<<"asda"<<endl;     

          }  

          printf("Case %d:",++ss);

          printf(" The total value of the hook is %d.\n",counter(1));    

    }

    return 0;    

}
