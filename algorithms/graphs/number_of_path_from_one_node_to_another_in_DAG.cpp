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

// Using dynamic programming

// Let f(u) be the number of ways one can travel from node u to destination. Hence, f(source) is required answer. 
// As f(destination) = 1 here so there is just one path from destination to itself. One can observe, f(u) depends on nothing 
// other than the f values of all the nodes which are possible to travel from u. It makes sense because the number of
// different paths from u to the destination is the sum of all different paths from v1, v2, v3… vn to destination vertex 
// where v1 to v-n are all the vertices that have a direct path from vertex u.


const int MAX = 5;
vi adj[MAX];

bool vis[MAX];
stack<int> s;

void topological_sort(int cur){
	vis[cur] = true;
	for(auto x : adj[cur]){
		if(vis[x])
			continue;
		topological_sort(x);
	}
	s.push(cur);
}


int countPath(int source, int dest){
	topological_sort(source);					// Assuming only one connected component
	vector<int> v;
	while(!s.empty()){
		v.PB(s.top());
		s.pop();
	}
	for(auto x : v)
		cout << x << "-> ";
	cout << endl;
	
	int dp[MAX] = {0};
	dp[dest] = 1;
	for(int i = (int)v.size()-1; i >= 0; i--){
		for(auto x : adj[v[i]]){
			dp[v[i]] += dp[x];
		}
	}
	return dp[source];
}


int32_t main(){
	adj[0].PB(1);
	adj[0].PB(2);
	adj[0].PB(3);
	adj[0].PB(4);
	adj[2].PB(3);
	adj[3].PB(4);
	
	cout << countPath(0, 4) << endl;

	return 0;
}

