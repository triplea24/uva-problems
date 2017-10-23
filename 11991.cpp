#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,v;
	while(cin >> n >> m){
		map<int,vector<int> > mp;
		for(int i = 0 ; i < n ; i++){
			cin >> v;
			if(mp.find(v)==mp.end())
				mp[v] = vector<int>();
			mp[v].push_back(i+1);	
		}
		for(int i = 0 ; i < m ; i++){
			cin >> k >> v;
			int idx = 0;
			if(mp.find(v)!=mp.end()){
				if(mp[v].size()>=k)idx=mp[v][k-1];
			}
			cout << idx << endl;
		}
	}
	return 0;
}
