//copy from http://www.acmdiy.net/Code/u/gaewah/HUST/1242
#define maxn 100100+1 
#define Iter map<int,int>::iterator 
#include <iostream> 
#include <map> 
using namespace std; 
int G[maxn],B[maxn],Y[maxn]; 
int SumG[maxn],SumB[maxn],SumY[maxn]; 
int F[maxn], PG[maxn], PB[maxn]; 
int n; 
map<int,int> list1,list2; 
int min(int a,int b){ 
	if (a<b) return a; 
	return b; 
} 
void init(){ 
	scanf("%d",&n); 
	for (int i=1;i<=n;i++) scanf("%d",&G[i]); 
	for (int i=1;i<=n;i++) scanf("%d",&B[i]); 
	for (int i=1;i<=n;i++) scanf("%d",&Y[i]); 
} 
void prepare(){ 
	list1.clear(); 
	list2.clear(); 
	memset(F, 0, sizeof F); 
	memset(SumG, 0, sizeof SumG); 
	memset(SumB, 0, sizeof SumB); 
	memset(SumY, 0, sizeof SumY); 
	for (int i=1;i<=n;i++){ 
		SumG[i] = SumG[i-1] + G[i]; 
		SumB[i] = SumB[i-1] + B[i]; 
		SumY[i] = SumY[i-1] + Y[i]; 
		PG[i] = - SumY[i] - SumG[i] - i * Y[i]; 
		PB[i] = - SumY[i] - SumB[i] - i * Y[i]; 
	} 
} 
 
 
int GetMin(map<int,int> &list,int i){ 
	Iter iter1,iter2; 
	iter1=list.end();iter1--; 
	iter2=iter1; 
	while (iter2!=list.begin()){ 
		iter2--; 
		if (i * iter1->first + iter1->second < i * iter2->first + iter2->second ) break; 
		iter1=iter2; 
	} 
	iter2=list.end(); 
	if (iter1!=list.end()) iter1++; 
	iter1--; 
	return (iter1->second + i * iter1->first); 
} 
 
bool check(Iter I1,Iter I2,Iter I3){ 
	return ((I2->first-I3->first) * (long long)(I1->second-I3->second) < (I1->first-I3->first) * (long long)(I2->second-I3->second));  
} 
 
void InsToList(map<int,int> &list,pair<int,int> tmp,int i){ 
	Iter it; Iter it2; Iter it3; 
	it=list.lower_bound(tmp.first); 
	if (it==list.end()) list.insert(tmp); 
	else{ 
		if (tmp.first == it->first){ 
			if (tmp.second+i*tmp.first >= it->second+i*it->first ) return; 
			list[tmp.first] = tmp.second; 
		} else { 
			if (it!=list.begin()){ 
				it--; 
				if (it->second+i*it->first<= tmp.second+i*tmp.first) return; 
				it++; 
			} 
			list.insert(tmp); 
		} 
	} 
 
	it=list.lower_bound(tmp.first); 
	if (it!=list.end()){ 
		it++; 
		for (it2=it;it2!=list.end();it2++) 
			if (it2->second < tmp.second) break; 
		list.erase(it,it2); 
	} 
	 
	it2=list.lower_bound(tmp.first); 
	Iter Itmp=list.end();Itmp--; 
	if (it2!=list.begin() && it2!=Itmp){ 
		it=it2;it--; 
		it3=it2;it3++; 
		if (!check(it,it2,it3)) { 
			list.erase(it2); 
			return; 
		} 
	} 
	 
	if (it2!=list.begin()){ 
		it3=it2; 
		it=--it2; 
		while (it!=list.begin()){ 
			it--; 
			if (check(it,it2,it3)) break; 
			it2=it; 
		} 
		if (it2!=list.end() && it2!=it3){ 
			it2++; 
			list.erase(it2,it3); 
		} 
		it2=list.lower_bound(tmp.first); 
	} 
	Itmp=list.end();Itmp--; 
	if (it2!=Itmp){ 
		it=it2; it2++; it3=it2; 
		while (++it3!=list.end()){ 
			if (check(it,it2,it3)) break; 
			it2=it3; 
		} 
		if (it!=list.end() && it!=it2) { 
			it++; 
			list.erase(it,it2); 
		} 
	} 
} 
 
void process(){ 
	pair<int,int> tmp (0,0); 
	list1.insert( pair<int,int>(0,0) ); 
	list2.insert( pair<int,int>(0,0) ); 
	for (int i=1;i<=n;i++){ 
		int tmp1=GetMin(list1,i); 
		int tmp2=GetMin(list2,i); 
		F[i]=min(tmp1 + SumG[i] , tmp2 + SumB[i]) + SumY[i]; 
		PG[i]+=F[i]; 
		PB[i]+=F[i]; 
		tmp=make_pair(Y[i],PG[i]); InsToList(list1,tmp,i); 
		tmp=make_pair(Y[i],PB[i]); InsToList(list2,tmp,i); 
	} 
}		 
 
void print(){ 
	printf("%d\n",F[n]); 
} 
 
int main(){ 
	int t; 
	scanf("%d",&t); 
	for (;t>0;t--){ 
		init(); 
		prepare(); 
		process(); 
		print(); 
	} 
	return 0; 
}
