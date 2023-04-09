#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 60;

vector<int> adj[N];
int ans[N][N], vis[N];

void dfs(int cur, int start){
	vis[cur] = 1;
	ans[start][cur] = 1;
	for(auto x : adj[cur]){
		if(!vis[x]){
			dfs(x,start);
		}
	}
}


void solve(){
	int n;
	cin >> n;
	
	// reset
	for(int i = 0; i <= 55; i++){
		adj[i].clear();
	}
	string in, out;
	cin >> in >> out;
	
	for(int i = 0; i < n; i++){
		if(i-1 >= 0 && in[i-1] == 'Y' && out[i] == 'Y'){
			adj[i].push_back(i-1);
		}
		if(i+1 < n && out[i] == 'Y' && in[i+1] == 'Y'){
			adj[i].push_back(i+1);
		}
	}
	
	memset(ans,0,sizeof ans);
	
	for(int i = 0; i < n; i++){
		memset(vis,0,sizeof vis);
		dfs(i,i);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << (ans[i][j] ? 'Y' : 'N');
		}
		cout << endl;
	}	
}

int32_t main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		cout << "Case #" << test++ << ": \n";
		solve();
	}
	
	return 0;
}
