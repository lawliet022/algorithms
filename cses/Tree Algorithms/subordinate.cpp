#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int ans[N];
vector<int> adj[N];

int dfs(int cur){
	ans[cur] = 0;
	for(auto x : adj[cur]){
		ans[cur] += dfs(x);
	}
	return ans[cur] + 1;
}

int32_t main(){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int par;
		cin >> par;
		adj[par].push_back(i);
	}
	
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	
	
	return 0;
}
