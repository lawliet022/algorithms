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
 
const int MAX = 1005;
const int LOG = 20;
vi adj[MAX+2];
int depth[MAX+2];
int parent[MAX+2][LOG+2];
 
void dfs(int cur, int par){
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		depth[x] = depth[cur]+1;
		parent[x][0] = cur;
		dfs(x,cur);
	}
}
 
void precompute(int n){
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
	for(int i = 0; i < LOG; i++){
		if(diff&(1<<i))
			b = parent[b][i];
	}
	if(a == b)
		return a;
	for(int i = LOG-1; i >= 0; i--){
		if(parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	} 
	return parent[a][0];
}
 
 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		for(int i = 0; i <= 1002; i++){
			adj[i].resize(0);
			adj[i].clear();
		}
		
		memset(depth,0,sizeof depth);
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			for(int j = 0; j < x; j++){
				int y;
				cin >> y;
				adj[i].PB(y);
				adj[y].PB(i);
			}
		}
		for(int i = 0; i <= MAX; i++)
			for(int j = 0; j <= LOG; j++)
				parent[i][j] = -1;
		
		dfs(1,0);
		
		precompute(n);
		
		int q;
		cin >> q;
		vi v;
		while(q--){
			int a, b;
			cin >> a >> b;
			v.PB(lca(a,b));
		}
		cout << "Case " << test++ << ":\n";
		for(auto x : v)
			cout << x << endl;
	}
 
	return 0;
}
