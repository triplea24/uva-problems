#include <bits/stdc++.h>
using namespace std;
int main(){
	int S,B,L,R;
	while(cin >> S >> B , S , B){
		int left[S+1],right[S+1];
		for(int i = 0 ; i < S + 1 ; i++)
			left[i] = i - 1, right[i] = i+1; 
		while(B--){
			cin >> L >> R;
			if(left[L]>0)cout << left[L] << " ";
			else cout << "* ";
			if(right[R]<=S)cout << right[R] << endl;
			else cout << "*" << endl;
			left[right[R]] = left[L];
			right[left[L]] = right[R];
		}
		cout << "-" << endl;
	}
}
