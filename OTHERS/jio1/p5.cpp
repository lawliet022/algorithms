#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;

vector<int> adj[N];

pair<int,int> p[N];
int dep[N];
int val[N];

void dfs(int cur, int par, int depth){
	dep[cur] = depth;
	p[cur] = {val[cur],0LL};		// assuming first is even
	for(auto x : adj[cur]){
		if(x != par){
			dfs(x,cur,depth+1);
			p[cur].first += p[x].second;
			p[cur].second += p[x].first;
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
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}
	
	dfs(1,-1,0);
	int q;
	cin >> q;
	while(q--){
		int cur, type;
		cin >> cur >> type;
		if(type == 0){		// even depth
			if(dep[cur] % 2 == 0){
				cout << p[cur].first << endl;
			}
			else{
				cout << p[cur].second << endl;
			}
		} 
		else{
			if(dep[cur] % 2 == 0){
				cout << p[cur].second << endl;
			}
			else{
				cout << p[cur].first << endl;
			}
		}
	}
	
	return 0;
}
