#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

string s;
int ans = 0;
vector<bool> vis;
int n;

int dfs(vector<vector<int>> &adj, int cur, int par, int flag){
	int cnt = 1;
	for(auto x : adj[cur]){
		if(x != par){
			int p = dfs(adj,x,cur,flag);
			if(flag && !(s[cur] == '*' && s[x] == '*'))
				ans += p * (n - p); 
			cnt += p;
		}
	}
	return cnt;
}

int cur_size = 0;


void dfs2(vector<vector<int>> &adj, int cur, int par){
	vis[cur] = 1;
	for(auto x : adj[cur]){
		if(!vis[x] && s[x] == '*'){
			dfs2(adj,x,cur);
		}
	}
}

vector<pair<int,int>> cntComponents(vector<vector<int>> &adj){
	vis.assign(n+1,false);
	map<int,int> m;
	for(int i = 1; i <= n; i++){
		if(!vis[i] && s[i] == '*'){
			dfs2(adj,i,-1);
			m[cur_size]++;
		}
	}
	vector<pair<int,int>> v;
	for(auto x : m){
		v.push_back({x.second,x.first});
	}
	sort(v.rbegin(),v.rend());
	vector<pair<int,int>> res;
	for(int i = 0; i < min((int)v.size(),2LL); i++){
		res.push_back(v[i]);
	}
	return res;
}

vector<int> current;

int dfs3(vector<vector<int>> &adj, int cur, int par){
	vis[cur] = 1;
	current.push_back(cur);
	for(auto x : adj[cur]){
		if(x != par && s[x] == '*'){
			dfs3(adj,x,cur);
		}
	}
}

int timer;
unordered_map<int,int> new_val;

void pre(vector<vector<int>> &adj, int sz){
	vis.assign(n+1,false);
	timer = n + 1;
	for(int i = 1; i <= n; i++){
		if(!vis[i] && s[i] == '*'){
			current.clear();
			dfs3(adj,i,-1);
			if(current.size() == sz){
				for(auto x : current){
					new_val[x] = timer;
				}
				timer++;
			}
		}
	}
}

void dfs





void solve(){
	int k;
	cin >> n >> k;
	cin >> s;
	s = " " + s;
	int e[n+1];
	for(int i = 2; i <= k+1; i++){
		cin >> e[i];
	}
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = k+2; i <= n; i++){
		e[i] = (a * e[i-2] + b * e[i-1] + c) % (i-1) + 1;
	}
	int inf = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '#')
			inf++;
	}
	
	vector<vector<int>> adj;
	adj.assign(n+1,{});
	
	for(int i = 2; i <= n; i++){
		adj[i].push_back(e[i]);
		adj[e[i]].push_back(i);
	}
	
	
	if(inf == n || inf == 0){	// all nodes are infected
		// root at 1 and calculate subtree size for each node
		ans = 0;
		dfs(adj,1,-1,0);
		cout << 0 << " " << ans << endl;
		return;
	}
	vector<pair<int,int>> pp = cntComponents(adj);
	
	if(pp.size() == 1 && pp[0].first == 1){
		int st = -1;
		vector<vector<int>> adj2;
		adj2.resize(n+1,{});
		int tot = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '*'){
				tot++;
				st = i;
				for(auto x : adj[i]){
					if(s[x] == '*'){
						adj2[i].push_back(x);
					}
				}
			}
		}
		ans = 0;
		dfs(adj2,st,-1,0);
		dfs(adj,st,-1,1);
		cout << tot << " " << ans << endl;
		return;
	}
	else{
		if(pp[0].first > 1){	// 4 4 4 4 ..
			int sz = pp[0].second;
			pre(adj,sz);
			
			for(int i = 1; i <= n; i++){
				if(new_node.count(i) == 0){
					new_node[i] = i;
				}
			}
			
			vector<vector<int>> adj3;
			adj3.resize(timer+10,{});
			for(int i = 1; i <= n; i++){
				for(auto x : adj[i]){
					if(new_node[i] != new_node[x]){
						adj3[new_node[i]].push_back(new_node[x]);
					}
				}
			}
		}
		else{		// 4 3 3 and so on
			
		}
		
	}
	
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
