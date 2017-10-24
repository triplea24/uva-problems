#include <bits/stdc++.h>
using namespace std;
#define D 0
int main(){
	int n,m,tc=0;
	string line;
	while(cin >> n){
		if(tc++)getline(cin,line);
		if(!(cin >> m))break;
		bitset<26> awake;
		vector< vector<int> > mat(26,vector<int>());
		cin >> line;
		awake.set(line[0]-'A');
		awake.set(line[1]-'A');
		awake.set(line[2]-'A');
		while(m--){
			cin >> line;
			if(D) cout << "Line : " << line << endl;
			mat[line[0]-'A'].push_back(line[1]-'A');
			mat[line[1]-'A'].push_back(line[0]-'A');
		}
		int prev=0;
		int year = 0;
		queue<int> q;
		while(awake.count()!=n && prev!=awake.count()){
			prev = awake.count();
			for(int i = 0 ; i < 26 ; i++){
				if(!awake[i]){
					int cnt = 0;
					for(int j = 0 ; j < mat[i].size() ; j++)
						if(awake[mat[i][j]])cnt++;
					if(cnt>=3)q.push(i);
				}
			}
			while(!q.empty()){
				int i = q.front();
				q.pop();
				awake.set(i);
			}
			year++;
		}
		if(awake.count()==n){
			cout << "WAKE UP IN, " << year << ", YEARS" << endl;
		}else{
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
	}
	return 0;
}
