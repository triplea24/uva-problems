#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define D 0
int main(){
	string line;
	int tc,n,cnt,tmp;
	for(cin >> tc ; tc-- ; ){
		cin >> n;
		if(D)cout << "Size : " << n << endl;
		getline(cin,line);
		vector< PII > res;
		for(int i = 0;  i < n ; i++){
			cnt = 0;
			getline(cin,line);
			if(D)cout << "Line : " << line << endl;
			istringstream sin(line);
			while(sin >> tmp)cnt++;
			if(D)cout << (i+1) << " : " << cnt << endl;
			res.push_back(PII(cnt,i+1));
		}
		sort(res.begin(),res.end());
		int minCnt = res[0].first;
		cout << res[0].second;
		for(int i = 1 ; i < res.size() ; i++){
			if(res[i].first !=minCnt)break;
			cout << " " << res[i].second;
		}
		cout << endl;
		if(tc)getline(cin,line);
		if(D)cout << "***" << endl;
	}
	return 0;
}
