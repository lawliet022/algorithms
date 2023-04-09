#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int dp[N][2];		// 0 - include, 1 - exclude
vector<int> adj[N];

void dfs(int cur, int par){
	int take_child = 0, not_take = 0, maxi = 0;
	for(auto x : adj[cur]){
		if(x != par){
			dfs(x,cur);
			take_child += dp[x][0];
			not_take += dp[x][1];
			maxi += max(dp[x][0],dp[x][1]);
		}
	}
	dp[cur][0] = 0;
	for(auto x : adj[cur]){
		if(x != par){
			dp[cur][0] = max(dp[cur][0],1 + dp[x][1] + take_child - dp[x][0]);
		}
	}
	dp[cur][1] = maxi;
}


int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1);
	
	
	cout << max(dp[1][0],dp[1][1]);
	
	
	return 0;
}
