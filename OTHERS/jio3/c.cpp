#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
int cost[N];

vector<pair<int,int>> adj[N];
int dist[N];
int	vis[N];
	

map<pair<int,int>,int> ma;	

int32_t main(){
	int n, m, s;
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		if(x > y)
			swap(x,y);
		if(ma.count({x,y})){
			ma[{x,y}] = min(ma[{x,y}],w);
		}
		else{
			ma[{x,y}] = w;
		}
	}
	
	for(auto pp : ma){
		int x = pp.first.first;
		int y = pp.first.second;
		int w = pp.second;
		adj[x].push_back({y,w + cost[y]});
		adj[y].push_back({x,w + cost[x]});
	}
	
	for(int i = 1; i <= n; i++)
		dist[i] = 1e16;
	
	dist[s] = 0;
	memset(vis,false,sizeof vis);
	
	priority_queue<pair<int,int>> q;
	q.push({0,s});

	while(!q.empty()){
		int t = q.top().second;
		q.pop();
		if(vis[t])
			continue;
		vis[t] = true;

		for(auto x : adj[t]){
			int a = x.first;
			int w = x.second;
			if(dist[a] > dist[t]+w){
				dist[a] = dist[t]+w;
				q.push({-dist[a],a});
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	
	
	
	return 0;
}
