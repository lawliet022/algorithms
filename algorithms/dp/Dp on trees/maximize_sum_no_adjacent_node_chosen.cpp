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

const int MAX = 1e5;
int dp1[MAX];			// Include current node and not its children
int dp2[MAX];			// Not include current node, can include its children
vi adj[MAX];

int val[] = {0,2,3,5,5,1,5,1,2};

void dfs(int cur, int par){
	int sum1 = 0, sum2 = 0;

	for(auto x : adj[cur]){
		if(x == par)	
			continue;
		dfs(x,cur);
		sum1 += dp2[x];						// exluding children of cur
		sum2 += max(dp1[x],dp2[x]);
	}
	dp1[cur] = val[cur] + sum1;
	dp2[cur] = sum2;
}

int32_t main(){
	int n = 8;
	
	adj[1].PB(2);
	adj[1].PB(3);
	adj[1].PB(4);
	adj[2].PB(5);
	adj[2].PB(6);
	adj[3].PB(7);
	adj[3].PB(8);
	
	adj[2].PB(1);
	adj[3].PB(1);
	adj[4].PB(1);
	adj[5].PB(2);
	adj[6].PB(2);
	adj[7].PB(3);
	adj[8].PB(3);
	
	dfs(1,-1);
	
	cout << max(dp1[1], dp2[1]) << endl;
	

	return 0;
}
