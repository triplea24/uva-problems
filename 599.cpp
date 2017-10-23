#include <bits/stdc++.h>
using namespace std;
#define SIZE 26
#define D 0
bool mat[SIZE][SIZE];
bitset<SIZE> mark;
void dfs(int v,int &numOfEdges,int &numOfVertices){
	if(!mark[v])numOfVertices++;
	mark.set(v);
	for(int u = 0 ; u < SIZE ; u++){
		if(mat[v][u]){
			mat[v][u] = mat[u][v] = false;
			numOfEdges++;
			dfs(u,numOfEdges,numOfVertices);
		}
	}
}
int main(){
	int tc,u,v,edges,vertices,tree,acron;
	string line;
	for(cin >> tc ,getline(cin,line); tc--; ){
		memset(mat,0,sizeof(mat));
		mark.reset();
		while(getline(cin,line),line[0]!='*'){
			if(D)cout << "Edge : " << line << endl;
			v = line[1]-'A';
			u = line[3]-'A';
			mat[u][v]=mat[v][u] = true;
		}
		getline(cin,line);
		tree = 0,acron = 0;
		for(int i = 0 ; i < line.size() ; i++){
			if(isalpha(line[i])){
				v = line[i]-'A';
				if(mark[v])continue;
				edges = 0;
				vertices = 0;
				dfs(v,edges,vertices);
				if(vertices == 1)
					acron++;
				else if(edges == (vertices-1))
					tree++;
			}
		}
		cout << "There are " << tree << " tree(s) and " << acron << " acorn(s)." << endl;
	}
	return 0;
}
