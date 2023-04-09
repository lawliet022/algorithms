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

// Diameter of a tree

const int N = 10;
vector<int> adj[N];
int dp[N][2];				// 0 - max diameter passing through me,  1 - height / max diameter ending at me 


pair<int,int> get2max(vector<int> &v){
	for(int i = 0; i < (int)v.size()-1; i++)
			if(v[i] > v[i+1])
				swap(v[i],v[i+1]);
		for(int i = 0; i < (int)v.size()-1; i++)
			if(v[i] > v[i+1])
				swap(v[i],v[i+1]);
		return {v[v.size()-1],v[v.size()-2]};
}

void dfs(int cur, int par){
	vector<int> v;				// stores height of all children of cur
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs(x,cur);
		v.push_back(dp[x][1]);
	}
	if(v.size() >= 2){
		auto maxi = get2max(v);
		dp[cur][0] = maxi.first + maxi.second + 2;
		dp[cur][1] = maxi.first + 1;
	}
	else if(v.size() == 1){
		dp[cur][0] = 0;
		dp[cur][1] = v[0] + 1;
	}
}


void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int32_t main(){
	
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(3,6);
	addEdge(6,7);
	
	for(int i = 1; i <= 7; i++){
		memset(dp,0,sizeof dp);
		dfs(i,0);
		int diameter = 0;
		for(int j = 1; j <= 7; j++){
			diameter = max({diameter,dp[j][0], dp[j][1]});
		}
		cout << "Diamter with " << i << " as root = " << diameter << endl;
	}
	
	return 0;
}

