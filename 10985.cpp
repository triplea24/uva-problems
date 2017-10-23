#include <bits/stdc++.h>
using namespace std;
#define D 0
typedef pair<int,int> PII;
int main(){
	int n,m,r,idx,value;
	string input;
	string firstLine,secondLine;
	while(getline(cin,input)){
		istringstream sin(input);
		sin >> m >> n;		
		vector< vector<PII> > res(n,vector<PII>());
		if(D)cout << "Size : " << m << " , " << n << endl;
		for(int i = 0 ; i < m ; i++){
			getline(cin,firstLine);
			istringstream sin(firstLine);
			getline(cin,secondLine);
			istringstream csin(secondLine);
			sin >> r;
			if(D) cout << "R : " << r << endl;
			if(D) cout << "First : " << sin.str() << endl;
			if(D) cout << "Second : " << csin.str() << endl;
			for(int j = 0 ; j < r ; j++){
				sin >> idx;
				csin >> value;
				if(D) cout << idx << " --> " << value << endl;
				res[idx-1].push_back(PII(i+1,value));
			}
		}
		for(int i = 0 ; i < n ; i++)
			sort(res[i].begin(),res[i].end());
		cout << n << " " << m << endl;
		for(int i = 0 ; i < n ; i++){
			r = res[i].size();
			cout << r;
			if(r)cout << " ";
			ostringstream first(""),second("");
			for(int j = 0 ; j < r ; j++){
				string space = "";
				if(j + 1 < r)space = " ";
				first << res[i][j].first << space;
				second << res[i][j].second << space;
			}
			cout << first.str() << endl << second.str() << endl;
		}
	}
	return 0;
}
