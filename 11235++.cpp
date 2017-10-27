#include <bits/stdc++.h>
using namespace std;
#define D 0
inline int LSOne(int x){
	return (x&(-x));
}
class FenwickTree{
private:
	std::vector<int> val,ft;
public:
	FenwickTree(int n){val.assign(n+1,0);ft.assign(n+1,0);}
	~FenwickTree(){ft.clear();val.clear();}
	int assign(int k,int x){
		val[k] = x;
		for(;k<(int)ft.size() ; k+=LSOne(k))
			ft[k]=max(ft[k],x);
	}
	int rmq(int b){
		int res = -1;
		for(;b ; b-= LSOne(b))res = max(res,ft[b]);
		return res;
	}
	int rmq(int a,int b){
		if(b<a)return -1;
		int res = val[a];
		for(; b && (b-LSOne(b) > a) ; b-=LSOne(b))res = max(res,ft[b]);
		if(b!=a)res = max(res,rmq(a+1,b-1));
		return res;
	}
	/* data */
};
int main(){
	int n,q,left,right;
	while(cin >> n , n){
		cin >> q;
		int a[n],count[n],start[n],end[n];
		unordered_map<int,int> mp;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if(mp.find(a[i])==mp.end())mp.insert(pair<int,int>(a[i],0));
			mp.at(a[i])++;
		}
		if(D)cout << "Got input" << endl;
		int last = 0;
		start[last] = last;
		count[last] = mp.at(a[last]);
		for(int i = 1 ; i < n ; i++){
			count[i] = mp.at(a[i]);
			if(a[i]==a[last]){
				start[i] = last;
			}else{
				start[i] = i;
				last = i;
			}
		}
		last = n-1;
		end[last] = last;
		for(int i = n - 2 ; i >= 0 ; i--){
			if(a[i]==a[last]){
				end[i] = last;
			}else{
				end[i] = i;
				last = i;
			}
		}
		FenwickTree ft(n);
		for(int i = 0 ; i < n ; i++)ft.assign(i+1,count[i]);
		for(int i = 0 ; i < q ; i++){
			cin >> left >> right;
			int res = right - left + 1;
			if(a[left-1]!=a[right-1]){
				int cnt1 = end[left-1]-left + 2;
				int cnt2 = right - start[right-1];
				int cnt3 = ft.rmq(end[left-1]+2,start[right-1]);
				if(cnt3!=-1)cnt3 = count[cnt3];
				if(D)cout << "middle : " << end[left-1]+1 << " , " << start[right-1]-1 << endl;
				if(D)cout << cnt1 << " , " << cnt2 << " , " << cnt3 << endl;
				res = max(cnt1,cnt2);
				res = max(res,cnt3);
			}
			cout << res << endl;
		}
		
	}
	return 0;
}
