#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
vector<int> adj[N];

int max_dis = -1, node;

void dfs(int cur, int par, int dis){
	if(dis > max_dis){
		max_dis = dis;
		node = cur;
	}
	for(auto x : adj[cur]){
		if(x != par){
			dfs(x,cur,dis+1);
		}
	}
}


int to_leaf[N], dp[N];
void dfs2(int cur, int par){
	vector<int> v;
	for(auto x : adj[cur]){
		if(x != par){
			dfs2(x,cur);
			v.push_back(to_leaf[x]);
		}
	}
	if(v.size() == 1){
		to_leaf[cur] = v[0] + 1;
		dp[cur] = v[0] + 1;
	}
	else if(v.size() >= 2){
		int sz = v.size();
		nth_element(v.begin(),v.begin() + sz-1, v.end());
		dp[cur] = v[sz-1] + v[sz-2] + 2;
		to_leaf[cur] = v.back() + 1;
	}
	else{
		to_leaf[cur] = 0;
		dp[cur] = 0;
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
	
	//dfs(1,-1,0);
	//max_dis = 0;
	//dfs(node,-1,0);
	//cout << max_dis << endl;
	
	
	//DP Approach
	dfs2(1,-1);	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans,dp[i]);
	cout << ans << endl;
	
		
	return 0;
}
