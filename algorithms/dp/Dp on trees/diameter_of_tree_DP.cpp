#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int MAX = 100;
vi adj[MAX];

int f[MAX] = {0}, g[MAX] = {0}, diameter;

void dfs(int cur, int par){
	vi val;
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs(x,cur);
		val.PB(f[x]);
	}
	if(val.size()){
		sort(val.begin(),val.end());
		f[cur] += 1 + val.back();
	}
	if(val.size() >= 2){
		g[cur] += 2 + val.back() + val[val.size()-2];
	}
	diameter = max(diameter,max(f[cur],g[cur]));
	
}

int32_t main(){
	adj[1].PB(2);
	adj[1].PB(3);
	adj[1].PB(4);
	adj[2].PB(5);
	adj[2].PB(6);
	adj[3].PB(7);
	adj[3].PB(8);
	adj[8].PB(9);
	
	
	adj[2].PB(1);
	adj[3].PB(1);
	adj[4].PB(1);
	adj[5].PB(2);
	adj[6].PB(2);
	adj[7].PB(3);
	adj[8].PB(3);
	adj[9].PB(8);
	
	
	dfs(1,-1);
	
	cout << diameter << endl;

	return 0;
}
