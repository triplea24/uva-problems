#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> nums;
	int n,median;
	while(cin >> n){
		nums.push_back(n);
		if(nums.size()%2){
			nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
			median = nums[nums.size()/2];
		}else{
			int midR = nums.size() / 2;
			int midL = midR-1;
			nth_element(nums.begin(),nums.begin()+midR,nums.end());
			midR = nums[midR];
			nth_element(nums.begin(),nums.begin()+midL,nums.end());
			midL = nums[midL];
			median = (midR+midL) >> 1;
		}
		cout << median << endl;
	}
	return 0;
}
