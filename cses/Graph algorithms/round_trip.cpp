#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
vector<int> adj[N];
int vis[N];
int found = 0;
vector<int> ans;
void dfs(int cur, int par){
	ans.push_back(cur);
	vis[cur] = 1;
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		if(vis[x]){
			ans.push_back(x);
			found = 1;
			return;
		}
		else{
			dfs(x,cur);
			if(found)
				return;
		}
	}
	ans.pop_back();
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
	for(int i = 1; i <= n; i++){
		if(!found && !vis[i]){
			dfs(i,0);
		}
	}
	
	if(!found){
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	reverse(ans.begin(),ans.end());
	while(ans.back() != ans[0]){
		ans.pop_back();
	}
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
	
	return 0;
}
