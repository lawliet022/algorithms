#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 5e5 + 100;
vector<int> adj[N];
int parent[N][20];
int depth[N];

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
	for(int lev = 1; lev < 20; lev++){
		for(int i = 1; i <= n; i++){
			if(parent[i][lev-1] != -1){
				parent[i][lev] = parent[parent[i][lev-1]][lev-1];
			}
		}
	}
}


int getKthParent(int cur, int k){
	for(int i = 19; i >= 0; i--){
		if(k&(1<<i)){
			cur = parent[cur][i];
		}
		if(cur == -1)
			return -1;
	}
	return cur;
}

int dp[N][2];

void dfs2(int cur, int par, int a, int b){
	dp[cur][0] = dp[cur][1] = 1;
	for(auto x : adj[cur]){
		if(x != par){
			dfs2(x,cur,a,b);
		}
	}
	int p = getKthParent(cur,a);
	if(p != -1)
		dp[p][0] += dp[cur][0];
	
	int q = getKthParent(cur,b);
	if(q != -1)
		dp[q][1] += dp[cur][1];
	
}

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 0; i <= n; i++){
		adj[i].clear();
		depth[i] = 0;
	}
	
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 20; j++)
			parent[i][j] = -1;
	
	depth[1] = 0;	
	dfs(1,0);
	
	precompute(n);
	
	dfs2(1,0,a,b);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[i][0] * (n - dp[i][1]);
	}
	for(int i = 1; i <= n; i++){
		ans += (n - dp[i][0]) * dp[i][1];
	}
	for(int i = 1; i <= n; i++){
		ans += dp[i][0] * dp[i][1];
	}
	
	cout << fixed << setprecision(6) << 1.0 * ans / (n * n) << endl;
}

int32_t main(){
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		cout << "Case #" << test++ << ": ";
		solve();
	}
	
	return 0;
}
