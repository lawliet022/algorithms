#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 10;
vector<pair<int,int>> adj[N];

int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	priority_queue<pair<int,int>> q;
	int dis[n+1], vis[n+1];
	for(int i = 1; i <= n; i++){
		dis[i] = 1e15;
		vis[i] = 0;
	}
	dis[1] = 0;
	q.push({0,1});
	
	while(!q.empty()){
		auto p = q.top();
		int cur = p.second;
		q.pop();
		if(vis[cur])
			continue;
		vis[cur] = 1;
		for(auto x : adj[cur]){
			if(dis[x.first] > dis[cur] + x.second){
				dis[x.first] = dis[cur] + x.second;
				q.push({-dis[x.first],x.first});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	
	
	return 0;
}
