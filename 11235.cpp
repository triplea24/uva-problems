#include <bits/stdc++.h>
using namespace std;
#define D 0
class SegmentTree{
	private:
		vector<int> st,A;
		int n;
		int left(int p){return p << 1;}
		int right(int p){return (p << 1) + 1;}
		void build(int p,int L , int R){
			if(L==R){
				st[p] = L;
			}else{
				build(left(p),L,(L+R)>>1);
				build(right(p),((L+R)>>1)+1,R);
				int p1 = st[left(p)],p2 = st[right(p)];
				st[p] = (A[p1]>=A[p2]) ? p1 : p2;
			}

		}
		int rmq(int p , int L , int R , int i , int j){
			if(i>R || j<L)return -1;
			if(L >= i && R <= j)return st[p];
			int p1 = rmq(left(p),L,(L+R)>>1,i,j);
			int p2 = rmq(right(p),((L+R)>>1)+1,R,i,j);
			if(p1 == -1)return p2;
			if(p2 == -1)return p1;
			return (A[p1]>=A[p2]) ? p1 : p2;
		}
	public:
		SegmentTree(const vector<int> & _A){
			A = _A;
			n = (int)A.size();
			st.assign(4*n,0);
			build(1,0,n-1);
		}
		int rmq(int i,int j){return i<=j ? rmq(1,0,n-1,i,j) : -1;}
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
		vector<int> A(count,count+n);
		SegmentTree st(A);
		for(int i = 0 ; i < q ; i++){
			cin >> left >> right;
			int res = right - left + 1;
			if(a[left-1]!=a[right-1]){
				int cnt1 = end[left-1]-left + 2;
				int cnt2 = right - start[right-1];
				int cnt3 = st.rmq(end[left-1]+1,start[right-1]-1);
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
