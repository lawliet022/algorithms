#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
vector<int> adj[N];
vector<pair<int,int>> maxi[N];

void dfs(int cur, int par){
	vector<pair<int,int>> v;
	for(auto x : adj[cur]){
		if(x != par){
			dfs(x,cur);
			if(maxi[x].size())
				v.push_back({maxi[x][0].first + 1, x});
			else
				v.push_back({1,x});
		}
	}
	sort(v.rbegin(),v.rend());
	for(int i = 0; i < min(2LL,(int)v.size()); i++){
		maxi[cur].push_back(v[i]);
	}
}

int ans[N];

void dfs2(int cur, int par){
	if(maxi[par].size() > 1){
		
	}
	for(auto x : adj[cur]){
		if(x != par){
			dfs2(x,cur);
		}
	}
}


int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1,0);
	
	
	
	return 0;
}
