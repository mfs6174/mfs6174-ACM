#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;
ifstream cin ("ti.in");
ofstream cout ("j.out");

int getRound(double lb, double ub, double val){
	double lb2 = (2*lb + ub)/3.0;
	double ub2 = (lb +2*ub)/3.0;
	if((lb2<=val)&&(val<=ub2)) return 1;
	else if (val<lb2){
		return 1+getRound(lb,lb2,val);
	}
	else return getRound(ub2,ub,val)+1;
}

int main(){
	int T;
	cin >> T;
	int N;
	for(int i=0;i<T;i++){
		cin >> N;

		vector <pair<int,double> > vp;
		for(int j=0;j<N;j++){			
			double x;
			cin >> x;
			int r = getRound(0,1.0,x);
			if(r>25) r = 25;
			pair <int,double> pid;
			pid.first = r;
			pid.second = x;
			vp.push_back(pid);
		}
		cout << "Case #" << i + 1 << ":" << endl;
		sort(vp.begin(),vp.end());
		for(int j=0;j<vp.size();j++){
			cout << vp[j].second << endl;
		}
	}
	
	return 0;
}
