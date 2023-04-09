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

const int MAX = 1e5 + 5;
const int LOG = 25;

vi adj[MAX+5];
int parent[MAX+2][LOG+2];

vi level[MAX+2];
int L[MAX+2];

int start[MAX+2], stop[MAX+2];
int ts = 0;

void dfs(int cur, int par, int lev){
	L[cur] = lev;
	start[cur] = ++ts;
	level[lev].PB(ts);
	
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		parent[x][0] = cur;
		dfs(x,cur,lev+1);
	}
	stop[cur] = ts;
}

void precompute(){
	for(int lev = 1; lev <= LOG; lev++){
		for(int i = 0; i <= MAX; i++){
			if(parent[i][lev-1] != -1){
				parent[i][lev] = parent[parent[i][lev-1]][lev-1];
			}
		}
	}
}

int getKth(int cur, int k){
	for(int i = 0; i <= 25; i++){
		if(k&(1<<i)){
			cur = parent[cur][i];
		}
		if(cur <= 0)
			return -1;
	}
	return cur;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		adj[x].PB(i);
	}
	for(int i = 0; i<= n; i++)
		for(int j = 0; j <= LOG; j++)
			parent[i][j] = -1;
	
	dfs(0,-1,0);
	
	precompute();
	
	//for(int i = 0; i <= n; i++){
		//for(int j = 0; j <= LOG; j++)
			//cout << parent[i][j] << " ";
		//cout << endl;
	//}
	//for(int i = 0; i <= n; i++)
		//cout << start[i] << " ";
	//cout << endl;
	
	//for(int i = 0; i <= n; i++)
		//cout << stop[i] << " ";
	//cout << endl;
	
	int q;
	cin >> q;
	while(q--){
		int node, x;
		cin >> node >> x;
		int kth = getKth(node,x);
		if(kth == -1){
			cout << 0 << " ";
		}
		else{
			int onLevel = L[node];
			int l = start[kth]+1, r = stop[kth];
			int p = upper_bound(level[onLevel].begin(),level[onLevel].end(),r) - lower_bound(level[onLevel].begin(),level[onLevel].end(),l);
			p--;
			cout << p << " ";
		}
	}

	return 0;
}

