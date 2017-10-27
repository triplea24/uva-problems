#include <bits/stdc++.h>
using namespace std;
inline int LSOne(int b){
	return (b&(-b));
}
class Fenwick{
private:
	std::vector<int> ft;
public:
	Fenwick(int n){ft.assign(n+1,0);}
	int rsq(int b){
		int sum = 0;
		for(; b ; b-=LSOne(b))sum+=ft[b];
		return sum;
	}
	int rsq(int a, int b){
		return rsq(b)-(a == 1 ? 0 : rsq(a-1));
	}
	void adjust(int k , int x){
		for(;k<(int)ft.size() ; k+=LSOne(k))ft[k]+=x;
	}
};
int main(){
	int n,k,x,y;
	char c;
	while(cin >> n >> k){
		Fenwick ft(n);
		Fenwick nft(n);
		std::vector<int> v(n+1,0);
		for(int i = 1 ; i < n + 1 ; i++){
			cin >> v[i];
			if(v[i]<0)
				ft.adjust(i,1);
			if(!v[i])
				nft.adjust(i,1);
				// st.insert(i);
		}
		ostringstream sout;
		while(k--){
			cin >> c >> x >> y;
			if(c == 'C'){
				int prev = v[x];
				if(y<0){
					if(prev>=0)ft.adjust(x,1);
					if(!prev)nft.adjust(x,-1);
				}else if(y>0){
					if(prev<0)ft.adjust(x,-1);
					if(!prev)nft.adjust(x,-1);
				}else{
					if(prev<0)ft.adjust(x,-1);
					nft.adjust(x,1);
				}
				v[x] = y;
			}else{
				c = '+';
				bool hasZero = nft.rsq(x,y) > 0;
				int cnt2 = ft.rsq(x,y);
				if(hasZero)c ='0';
				else if(cnt2%2)c='-';
				sout << c;
			}
		}
		cout << sout.str() << endl;
	}
	return 0;
}