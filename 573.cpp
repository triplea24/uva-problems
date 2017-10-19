#include <bits/stdc++.h>
using namespace std;
int main(){
	int H,U,D,F;
	double fatigue,up,down;
	while(cin >> H >> U >> D >> F && H){
		up = U;
		fatigue = up * F / 100.0;
		down = D;
		int day = 1;
		double curH = 0;
		for(curH = 0.0 ; curH >= 0 && curH <= H ; day++){
			curH += up;
			if(curH>H)break;
			curH -= down;
			if(curH<0)break;
			up -= fatigue;
			if(up<0)up = 0;
		}
		string res = (curH < 0.0 ? "failure" : "success");
		cout << res << " on day " << day << endl;
	}
	return 0;
}
