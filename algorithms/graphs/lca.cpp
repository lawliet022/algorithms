#include<bits/stdc++.h>
using namespace std;

const int n = 9;
vector<int> adj[n+1];

const int LOG = ceil(log(n));

int parent[n+1][LOG+1];
int depth[n+1];

void dfs(int cur, int par){
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		depth[x] = depth[cur]+1;
		parent[x][0] = cur;
		dfs(x,cur);
		
	}
}


void precompute(){
	for(int lev = 1; lev <= LOG; lev++){
		for(int i = 1; i <= n; i++){
			if(parent[i][lev-1] != -1){
				parent[i][lev] = parent[parent[i][lev-1]][lev-1];
			}
		}
	}
}

int lca(int a, int b){
	if(depth[a] > depth[b])
		swap(a,b);
	
	int diff = depth[b] - depth[a];
	for(int i = 0; i <= LOG; i++){
		if(diff&(1<<i))
			b = parent[b][i];
	}
	if(a == b)
		return a;
	for(int i = LOG; i >= 0; i--){
		if(parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int getKthParent(int a, int k){
	for(int i = LOG; i >= 0; i--){
		if(k&(1<<i)){
			a = parent[a][i];
		}
		if(a == -1){
			return -1;
		}
	}
	return a;
}


void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}


int32_t main(){
	addEdge(1,2);
	addEdge(1,3);
	addEdge(3,8);
	addEdge(3,7);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(2,6);
	addEdge(4,9);
	
	
	int a = 6, b = 9;
	
	// Initialise to -1 
	memset(parent,-1,sizeof parent);
		
	depth[1] = 0;	
	dfs(1,0);
	
	precompute();
	
	cout << lca(a, b) << endl;

	return 0;
}

