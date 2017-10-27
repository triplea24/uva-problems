#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
private:
	std::vector<int> st,A;
	int n;
	int left(int p){return p<<1;}
	int right(int p){return (p<<1) + 1;}
	void build(int p,int L,int R){
		if(L==R){
			st[p] = A[L];
		}else{
			build(left(p),L,(L+R)>>1);
			build(right(p),((L+R)>>1)+1,R);
			int p1 = st[left(p)],p2 = st[right(p)];
			st[p] = p1*p2;
		}
	}
	int rsq(int p,int L,int R, int i , int j){
		if(j<L || i>R)return 1;
		if(i <= L && R <= j)return st[p];
		int p1 = rsq(left(p),L,(L+R)>>1,i,j);
		int p2 = rsq(right(p),((L+R)>>1)+1,R,i,j);
		return p1*p2;
	}
	int update(int p,int L,int R, int i , int x){
		if(i>R || i<L)return st[p];
		if(i==L && i==R)
			return st[p] = A[i] = x;
		int p1 = update(left(p),L,(L+R)>>1,i,x);
		int p2 = update(right(p),((L+R)>>1)+1,R,i,x);
		return st[p]=p1*p2;
	}
public:
	SegmentTree(std::vector<int> & _A){
		A = _A;
		n = (int)A.size();
		st.assign(4*n,0);
		build(1,0,n-1);
	}
	int rsq(int i,int j){return rsq(1,0,n-1,i,j);}
	void update(int i , int x){
		update(1,0,n-1,i,x);
	}
};
inline int norm(int x){
	return x>0 ? 1 : x<0 ? -1 : 0;
}
int main(){
	int n,k,x,y;
	char c;
	while(cin >> n >> k){
		std::vector<int> v(n,0);
		for(int i = 0 ; i < n  ; i++){
			cin >> v[i];
			v[i] = norm(v[i]);
		}
		SegmentTree st(v);
		// string res = "";
		ostringstream sout;
		while(k--){
			cin >> c >> x >> y;
			if(c == 'C'){
				st.update(x-1,norm(y));
			}else{
				int tmp = st.rsq(x-1,y-1);
				if(tmp > 0)
					sout << '+';
				else if(tmp == 0)
					sout << '0';
				else
					sout << '-';
			}
		}
		cout << sout.str() << endl;
	}
	return 0;
}