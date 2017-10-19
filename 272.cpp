#include <bits/stdc++.h>
using namespace std;
#define D 0
int main(){
	int cnt = 0;
	bool found = false;
	string line,lines= "",res;
	while(getline(cin,line)){
		if(cnt++)lines +="\n";
		lines += line;
	}
	res = "";
	for(int i = 0 ; i < lines.size() ; i++){
		char ch = lines[i];
		if(ch == '"'){
			if(found)
				res+="''";
			else
				res+="``";
			found = !found;
		}else
			res+=ch;
	}
	cout << res << endl;
	return 0;
}
