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

vector<int> adj[100005];

int dp[100005];

int solve(int cur){
	if(dp[cur] != -1)
		return dp[cur];
	dp[cur] = 0;
	
	for(auto x : adj[cur]){
		solve(x);
		dp[cur] = max(dp[cur],dp[x] + 1);
	}
	return dp[cur];
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	
	memset(dp,-1,sizeof dp);
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		ans = max(ans,solve(i));
	}
	
	cout << ans << endl;

	return 0;
}

