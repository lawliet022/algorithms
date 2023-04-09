#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
vector<int> adj[N];
int lev[N];
vector<pair<int,int>> res;

void dfs(int cur){
	for(auto x : adj[cur]){
		if(lev[x] == 0){				// Not visited yet
			res.push_back({cur,x});
			lev[x] = lev[cur] + 1;
			dfs(x);
		}
		else if(lev[x] < lev[cur]-1){		// backward edge (-1 because parent edge is not a back edge)
			res.push_back({x,cur});
		}
	}
}


int32_t main(){
	
	int n, m;
	cin >> n >> m;
	set<pair<int,int>> edges;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edges.insert({x,y});
	}
	
	lev[1] = 1;
	dfs(1);
	
	for(auto p : res){
		if(edges.find(p) != edges.end()){
			edges.erase(edges.find(p));
		}
		else if(edges.find({p.second,p.first}) != edges.end()){
			edges.erase(edges.find({p.second,p.first}));
		}
		cout << p.first << " " << p.second << endl;
	}
	
	for(auto x : edges){
		cout << x.first << " " << x.second << endl;
	}
	
	
	
	
	return 0;
}
