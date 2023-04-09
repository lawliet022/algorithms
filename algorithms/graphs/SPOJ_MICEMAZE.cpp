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



int32_t main(){
	int n, e, t;
	cin >> n >> e >> t;
	
	vector<pii> adj[n+1];

	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[y].PB({x,w});
	}
	
	// Dijkstra's
	priority_queue<pair<int,int>> q;
	bool vis[n+1];
	memset(vis, false, sizeof vis);
	
	q.push({0,e});
	vis[e] = true;
	
	int dis[n+1];
	for(int i = 1; i <= n; i++)
		dis[i] = 1e9;
		
	dis[e] = 0;
	
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		for(auto x : adj[p.S]){
			if(vis[x.F])
				continue;
			if(dis[x.F] > dis[p.S] + x.F){
				dis[x.F] = dis[p.S] + x.S;
				q.push({-dis[x.F],x.F});
				vis[x.F] = true;
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(dis[i] <= t)
			ans++;
	
	cout << ans << endl;
	
	

	return 0;
}

