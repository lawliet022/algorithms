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

// Given a tree T of N nodes and an integer K, find number of different sub trees of size less than or equal to K.
// Here sub tree is different from normal subtree. Sub tree is a connected subset of nodes

const int N = 10;
const int K = 10;
vector<int> adj[N];


int f[N][K];
int k;

void dfs(int cur, int par){
	int dp[K] = {0};			// stores number of ways to chose i nodes from subtree to form i+1 nodes
	dp[0] = 1;					// chosing 0 nodes from current subtree (i.e no of ways to chose 0 nodes other than cur)
	f[cur][0] = f[cur][1] = 1;	// ways to chose 0 and 1 nodes from subtree
	
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs(x,cur);
		int dp2[K] = {0};
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k-i; j++){
				dp2[i+j] += dp[i] * f[x][j];
			}
		}
		for(int i = 0; i < k; i++){
			dp[i] = dp2[i];
		}
	}
	for(int i = 2; i <= k; i++)
		f[cur][i] = dp[i-1];
}


void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int ncr(int n, int r){
	if(r > c)
		return 0;
	r = 
}

int32_t main(){
	
	// Number of ways to chose k elements from a1, a2, ..., an
	// Ex-> [2,3,2] when k = 2 answer is
	
	int a[3] = {2,3,2);
	int m = 3;
	int val = 2;
	int dp[n][10];
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= val; j++){
			for(int k = 0; k <= j; k++){
				dp[i][j] += dp[i-1][k] * ncr(a[i-1],j-k);
			}
		}
	}
	
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(3,6);
	addEdge(6,7);
	addEdge(6,8);
	addEdge(6,9);
	
	k = 3;
	dfs(1,0);
	
	int ans = 0;
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= k; j++){
			ans += f[i][j];
			// cout << "dp[" << i << "][" << j << "] = " << f[i][j] << endl;
		}
		
			
	cout << ans << endl;
	

	return 0;
}

