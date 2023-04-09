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
const int N = 1e5 + 100;

vector<int> g[N+2], gr[N+2], adj[N];		// adj2 stores transpose graph
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

stack<int> s;
void topological_sort(int cur){
	vis[cur] = true;
	for(auto x : adj[cur]){
		if(vis[x])
			continue;
		topological_sort(x);
	}
	s.push(cur);
}

int dp[N];

void solve(int cur){
	vis[cur] = 1;
	dp[cur] = 1;
	for(auto x : adj[cur]){
		if(vis[x]){
			dp[cur] += dp[x]; 
		}
		else{
			solve(x);
			dp[cur] += dp[x];
		}
	}
}


void dfs3(int cur){
	vis[cur] = 1;
	for(auto x : adj[cur]){
		if(!vis[x])
			dfs3(x);
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int i = 0; i <= n; i++){
			g[i].clear();
			gr[i].clear();
			adj[i].clear();
			vis[i] = 0;
			dp[i] = 0;
		}
		order.clear();
		s = {};
		
		vector<pair<int,int>> edges;
		
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
			g[x].push_back(y);
			gr[y].push_back(x);				// transpose edges
		}
		memset(vis,0,sizeof vis);
		
		for(int i = 1; i <= n; i++){
			if(!vis[i])
				dfs(i);
		}
		memset(vis,0,sizeof vis);
		
		map<int,int> change;
		int node = 1;
		
		for(int i = 0; i < n; i++){
			int cur = order[n-1-i];
			if(!vis[cur]){
				dfs2(cur);
				for(auto x : component){
					change[x] = node;
				}
				node++;
				component.clear();
			}
		}
		
		for(auto x : edges){
			if(change[x.first] != change[x.second]){
				adj[change[x.first]].push_back(change[x.second]);
			}
		}
		node--;
		n = node;
		memset(vis,0,sizeof vis);    
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				topological_sort(i);
			}
		}
		
		vector<int> res;
		while(!s.empty()){
			res.push_back(s.top());
			s.pop();
		}
		
		memset(vis,0,sizeof vis);
		for(auto x : res){
			if(!vis[x]){
				solve(x);
			}
		} 
		vector<pair<int,int>> pp;
		for(int i = 1; i <= n; i++){
			pp.push_back({dp[i],i});
		}
		sort(pp.rbegin(),pp.rend());
		
		int ans = 0;
		memset(vis,0,sizeof vis);
		for(auto x : pp){
			if(!vis[x.second]){
				ans++;
				dfs3(x.second);
			}
		}
		cout << ans << endl;
		
		
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

