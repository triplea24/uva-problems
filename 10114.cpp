#include <bits/stdc++.h>
using namespace std;
#define D 0
int main(){
	int months,depNum;
	long double down,monthly,carVal,loanVal;
	while(cin >> months >> down >> loanVal >> depNum && months > 0){
		unordered_map<int,long double> deps;
		for(int i = 0; i < depNum ; i++){
			int key;
			long double val;
			cin >> key >> val;
			deps.insert(make_pair(key,val));
		}
		carVal = (down + loanVal)*(1-deps.at(0));
		monthly = loanVal / months;
		int now = 0;
		double lastP = deps.at(0);
		while(carVal < loanVal){
			now++;
			double p = deps.find(now)!=deps.end() ? deps.at(now) : lastP;
			lastP = p;
			loanVal -= monthly;
			carVal *= (1-p);
		}
		cout << now << " month" << (now!=1 ? "s" : "") << endl;
		
	}
	return 0;
}
