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

const int N = 1e5 + 10;
vector<pair<int,int>> adj[N];
int n;

void addEdge(int a, int b, int wt){
	adj[a].PB({b,wt});
	adj[b].PB({a,wt});
}

const int LOG = 30;

int parent[N][LOG+1];
int maxi[N][LOG+1];
int sumi[N][LOG+1];
int depth[N];

void dfs(int cur, int par){
	for(auto x : adj[cur]){
		if(x.first == par)
			continue;
		depth[x.first] = depth[cur]+1;
		parent[x.first][0] = cur;
		maxi[x.first][0] = x.second;
		sumi[x.first][0] = x.second;
		dfs(x.first,cur);
	}
}


void precompute(){
	for(int lev = 1; lev <= LOG; lev++){
		for(int i = 1; i <= n; i++){
			if(parent[i][lev-1] != -1){
				parent[i][lev] = parent[parent[i][lev-1]][lev-1];
			}
		}
	}
}

int lca(int a, int b){
	if(depth[a] > depth[b])
		swap(a,b);
	
	int diff = depth[b] - depth[a];
	for(int i = 0; i <= LOG; i++){
		if(diff&(1<<i))
			b = parent[b][i];
	}
	if(a == b)
		return a;
	for(int i = LOG; i >= 0; i--){
		if(parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}


void precompute2(){
	for(int lev = 1; lev <= LOG; lev++){
		for(int i = 1; i <= n; i++){
			if(maxi[i][lev-1] != -1 && maxi[parent[i][lev-1]][lev-1] != -1){
				maxi[i][lev] = max(maxi[i][lev-1],maxi[parent[i][lev-1]][lev-1]);
			}
		}
	}
}

void precompute3(){
	for(int lev = 1; lev <= LOG; lev++){
		for(int i = 1; i <= n; i++){
			if(sumi[i][lev-1] != -1 && sumi[parent[i][lev-1]][lev-1] != -1){
				sumi[i][lev] = sumi[i][lev-1] + sumi[parent[i][lev-1]][lev-1];
			}
		}
	}
}

int getMax(int cur, int up){
	int maxia = 0;
	for(int i = 30; i >= 0; i--){
		if(up&(1<<i)){
			maxia = max(maxia,maxi[cur][i]);
			cur = parent[cur][i];
		}
	}
	return maxia;
}


int getSum(int cur, int up){
	int tot = 0;
	for(int i = 30; i >= 0; i--){
		if(up&(1<<i)){
			tot += sumi[cur][i];
			cur = parent[cur][i];
		}
	}
	return tot;
}




int32_t main(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y, wt;
		cin >> x >> y >> wt;
		addEdge(x,y,wt);
	}
	
	int q;
	cin >> q;
	
	// Using sparse table method (Binary Lift)
		
	// Initialise to -1 
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= LOG; j++){
			parent[i][j] = -1;
			maxi[i][j] = -1;
			sumi[i][j] = -1;
		}
	}
	
	depth[1] = 0;
	dfs(1,0);
	
	precompute();
	precompute2();
	precompute3();
	
	
	while(q--){
	
		int a, b, w;
		cin >> a >> b >> w;
				
		int p = lca(a, b);		
		int m1 = getMax(a,depth[a]-depth[p]);
		int m2 = getMax(b,depth[b]-depth[p]);
		
		if(max(m1,m2) > w){
			int d1 = getSum(a,depth[a]-depth[p]);
			int d2 = getSum(b,depth[b]-depth[p]);
			cout << "Yes " << d1 + d2 - max(m1,m2) + w << endl;
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}

