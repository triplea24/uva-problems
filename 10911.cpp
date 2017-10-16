#include <bits/stdc++.h>
using namespace std;
int target,N;
double dist[20][20],mem[1<<16];
double matching(int mask){
	if(mem[mask] > -0.5)
		return mem[mask];
	if(mask == target)
		return mem[mask] = 0;
	double res = 2000000000.0;
	int p1,p2;
	for(p1 = 0 ; p1<2*N ; p1++)
		if(!(mask & 1<<p1))
			break;
	for(p2 = p1 + 1; p2 < 2*N ; p2++)
		if(!(mask & 1<<p2))
			res = min(res,dist[p1][p2] + matching(mask | (1<<p1) | (1<<p2)));
	return mem[mask] = res;
}
int main(){
	string name;
	for(int tc = 1 ;  ; tc++){
		cin >> N;
		if(!N)break;
		vector<double> x(2*N,0.0);
		vector<double> y(2*N,0.0);
		for(int i = 0 ; i < 2*N ; i++)
			cin >> name >> x[i] >> y[i];
		for(int i = 0 ; i < 2*N ; i++)
			for(int j = 0 ; j < 2*N ; j++)
				dist[i][j] = hypot(x[i]-x[j],y[i]-y[j]);
		for(int i = 0 ; i < 1<<16 ; i++)mem[i] = -1.0;
		target = (1<<2*N)-1;
		printf("Case %d: %0.2f\n",tc,matching(0));
	}
	return 0;
}
