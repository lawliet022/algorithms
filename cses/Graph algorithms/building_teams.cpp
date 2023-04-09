#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 100;
vector<int> adj[N];
int ok = 1;
int color[N];

void dfs(int cur, int par, int col){
	color[cur] = col;
	for(auto x : adj[cur]){
		if(x != par){
			if(color[x] == -1){
				dfs(x,cur,1-col);
			}
			else{
				if(color[x] == color[cur]){
					ok = 0;
				}
			}
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
	memset(color,-1,sizeof color);
	
	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			dfs(i,-1,0);
		}
	}
	
	if(!ok){
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cout << color[i] + 1 << " ";
	}
	
	
	return 0;
}
