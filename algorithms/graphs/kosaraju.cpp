#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

// Strongly Connected Component - Kosaraju Algo
const int N = 1e5;

vector<int> g[N+2], gr[N+2];		// adj2 stores transpose graph
vector<int> order;					// order of edges - increasing order of exit time
int vis[N+2];

void dfs(int cur){
	vis[cur] = 1;
	for(auto x : g[cur]){
		if(!vis[x])
			dfs(x);
	}
	order.push_back(cur);
}

vector<int> component;

void dfs2(int cur){
	vis[cur] = 1;
	for(auto x : gr[cur]){
		if(!vis[x])
			dfs2(x);
	}
	component.push_back(cur);
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		gr[y].push_back(x);				// transpose edges
	}
	memset(vis,0,sizeof vis);
	
	for(int i = 1; i <= n; i++){
		if(!vis[i])
			dfs(i);
	}
	memset(vis,0,sizeof vis);
	for(int i = 0; i < n; i++){
		int cur = order[n-1-i];
		if(!vis[cur]){
			dfs2(cur);
			for(auto x : component)
				cout << x << " ";
			cout << endl;
			component.clear();
		}
	}
	return 0;
}


//6 13
//4 5
//5 4
//5 6
//6 5
//6 4
//4 6
//1 2
//2 1
//1 3
//3 1
//2 3
//3 2
//5 1

