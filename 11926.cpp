#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define N 1000001
int main(){
	int n,m,start,end,period;
	while(cin >> n >> m , n||m){
		priority_queue< PII > q;
		while(n--){
			cin >> start >> end;
			q.push(PII(-end,-start));
		}
		while(m--){
			cin >> start >> end >> period;
			for(int r = 0 ; r+start<N ;r+=period)
				q.push(PII(-r-end,-r-start));	
		}
		int bef = -q.top().first;
		q.pop();
		bool conflict = false;
		while(q.size()){
			PII tmp = q.top();
			q.pop();
			start = -tmp.second;
			end = -tmp.first;
			if(start<bef){
				conflict = true;
				break;
			}
			bef = end;
		}
		cout << (conflict ? "CONFLICT" : "NO CONFLICT") << endl;
	}
	return 0;
}
