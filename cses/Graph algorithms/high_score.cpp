#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	// can change it to bellman-ford by reverting signs of distances and finding shortest distance in a directed graph with negative wts
	int n, m;
	cin >> n >> m;
	
	int dis[n+1];
	for(int i = 0; i <= n; i++){
		dis[i] = 1e17;
	}
	
	dis[1] = 0;
	
	vector<tuple<int,int,int>> edges;
	
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({a,b,-w});
	}
	
	for(int i = 0; i < n-1; i++){
		for(auto e : edges){
			int a, b, w;
			tie(a,b,w) = e;
			dis[b] = min(dis[b],dis[a]+w);
		}
	}
	
	bool ok = 1;
	
	for(auto e : edges){
		int a, b, w;
		tie(a,b,w) = e;
		if(dis[a] + w < dis[b]){	// negative cycle exists
			ok = 0;
			break;
		}
	}
	
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	
	cout << -dis[n] << endl;
	
	
	
	
	return 0;
}
