#include <bits/stdc++.h>
using namespace std;
class UnionFind{
	private:
		vector<int> p,rank;
		int cnt;
	public:
		UnionFind(int N){
			rank.assign(N,0);
			p.assign(N,0);
			for(int i = 0 ; i < N ; i++)p[i]=i;
			cnt = N;
		}
		int findSet(int i){return (p[i]==i) ? i : p[i]=findSet(p[i]);}
		bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
		void unionSet(int i , int j){
			if(!isSameSet(i,j)){
				cnt--;
				int x=findSet(i),y=findSet(j);
				if(rank[x]>rank[y])p[y]=x;
				else{
					p[x]=y;
					if(rank[x]==rank[y])rank[y]++;
				}
			}
		}
		int count(){return cnt;}
		
		
};
int main(){
	int n,m;
	int x,y;
	for(int tc = 1 ; cin >> n >> m , n , m ; tc++){
		UnionFind ds(n);
		for(int i = 0 ; i < m ; i++){
			cin >> x >> y;
			ds.unionSet(x-1,y-1);
		}
		printf("Case %d: %d\n",tc,ds.count());
	}
	return 0;
}
