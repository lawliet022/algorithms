#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
vector<int> adj[N];
int vis[N];

void dfs(int cur){
	vis[cur] = 1;
	for(auto x : adj[cur]){
		if(!vis[x]){
			dfs(x);
		}
	}
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	vector<int> leader;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ans++;
			dfs(i);
			leader.push_back(i);
		}
	}
	cout << ans - 1 << endl;
	for(int i = 0; i < (int)leader.size() - 1; i++){
		cout << leader[i] << " " << leader[i+1] << endl;
	}
	
	return 0;
}
