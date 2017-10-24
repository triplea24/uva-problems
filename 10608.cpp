#include <bits/stdc++.h>
using namespace std;
class UnionFind{
	private:
		vector<int> p,rank,sz;
		int cnt,mxSetSize;
	public:
		UnionFind(int N){
			rank.assign(N,0);
			p.assign(N,0);
			sz.assign(N,0);
			for(int i = 0 ; i < N ; i++)p[i]=i,sz[i]=1;
			cnt = N;
			mxSetSize = 1;
		}
		~UnionFind(){rank.clear(),p.clear(),sz.clear();}
		int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
		bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
		void unionSet(int i , int j){
			if(!isSameSet(i,j)){
				cnt--;
				int x=findSet(i),y=findSet(j);
				if(rank[x]>rank[y]){
					p[y]=x;
					sz[x]+=sz[y];
					mxSetSize=max(mxSetSize,sz[x]);
				}else{
					p[x]=y;
					sz[y]+=sz[x];
					mxSetSize=max(mxSetSize,sz[y]);
					if(rank[x]==rank[y])rank[y]++;
				}
			}
		}
		int count(){return cnt;}
		int maxSetSize(){return mxSetSize;}
		
};
int main(){
	int tc,n,m,x,y;
	for(cin >> tc ; tc-- ; ){
		cin >> n >> m;
		UnionFind ds(n);
		for(int i = 0 ; i < m ; i++){
			cin >> x >> y;
			ds.unionSet(x-1,y-1);
		}
		cout << ds.maxSetSize() << endl;
	}
	return 0;
}
