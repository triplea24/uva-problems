#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc,v,e,tmp;
	for(cin >> tc; tc-- ; ){
		cin >> v >> e;
		vector< vector<bool> > mat(v,vector<bool>(v,false));
		unordered_map<int,int> edges;
		unordered_map<int,int> cnt;
		bool valid = true;
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < e ; j++){
				cin >> tmp;
				if(tmp){
					if(edges.find(j)!=edges.end()){
						int last = edges.at(j);
						if(mat[last][i] || mat[i][last] || cnt.at(j)>1)valid = false;
						mat[last][i] = mat[i][last] = true;
						cnt.at(j)++;
					}else{
						edges.insert(pair<int,int>(j,i));
						cnt.insert(pair<int,int>(j,1));
					}
				}
			}
		}
		for(int i = 0 ; i < e ; i++)
			if(cnt.find(i)==cnt.end() || cnt.at(i)!=2)valid = false;
		cout << (valid ? "Yes" : "No") << endl;	
	}
	return 0;
}
