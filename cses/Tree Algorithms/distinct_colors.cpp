#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int col[N], sz[N];

vector<int> adj[N];
vector<int> *vec[N];
int ans[N];

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<int,int,custom_hash> m;


void pre(int cur, int par){
	sz[cur] = 1;
	for(auto x : adj[cur]){
		if(x != par){
			pre(x,cur);
			sz[cur] += sz[x];
		}
	}
}

void dfs(int cur, int par, int keep){
	int mx = -1, bigChild = -1;
	for(auto x : adj[cur]){
		if(x != par && sz[x] > mx){
			mx = sz[x];
			bigChild = x;
		}
	}
	for(auto x : adj[cur]){
		if(x != par && x != bigChild){
			dfs(x,cur,0);
		}
	}
	
	if(bigChild != -1){
		dfs(bigChild,cur,1);
		vec[cur] = vec[bigChild];
	}
	else{
		vec[cur] = new vector<int>();
	}
	vec[cur]->push_back(cur);
	m[col[cur]]++;
	for(auto x : adj[cur]){
		if(x != par && x != bigChild){
			for(auto y : *vec[x]){
				vec[cur]->push_back(y);
				m[col[y]]++;
			}
		}
	}
	ans[cur] = m.size();
	if(keep == 0){
		for(auto x : *vec[cur]){
			m[col[x]]--;
			if(m[col[x]] == 0)
				m.erase(m.find(col[x]));
		}
	}
}


int32_t main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)	
		cin >> col[i];
	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pre(1,0);
	
	dfs(1,0,0);
	
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	
	
	return 0;
}
