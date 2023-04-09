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

// Max sum of subset nodes s.t no 2 adjacent nodes are picked

const int N = 10;
vector<int> adj[N];
int val[N];
int dp[N][2];		// 0 - without including itself		1 - including itself

void dfs(int cur, int par){
	int inc = val[cur], exc = 0;
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs(x,cur);
		inc += dp[x][0];
		exc += max(dp[x][0], dp[x][1]);
	}
	dp[cur][0] = exc;
	dp[cur][1] = inc;
}

void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int32_t main(){
	val[1] = 1;	val[2] = 2;	val[3] = 3;	val[4] = 1;	val[5] = 5;	val[6] = 1;	val[7] = 6;
	
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(3,6);
	addEdge(6,7);
	
	
	
	dfs(1,0);
	
	cout << max(dp[1][0],dp[1][1]) << endl;

	return 0;
}

