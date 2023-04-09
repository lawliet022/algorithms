#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
vector<int> adj[N];
bool vis[N];
int par[N];

int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	par[1] = -1;
	
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		for(auto x : adj[cur]){
			if(!vis[x]){
				par[x] = cur;
				vis[x] = 1;
				q.push(x);
			}
		}
	}
	
	if(!vis[n]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	vector<int> path;
	int cur = n;
	path.push_back(n);
	while(par[cur] != 1){
		cur = par[cur];
		path.push_back(cur);
	}
	path.push_back(1);
	reverse(path.begin(),path.end());
	
	cout << path.size() << endl;
	for(auto x : path){
		cout << x << " ";
	}
	
	
	return 0;
}
