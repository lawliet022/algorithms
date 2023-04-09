#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int > vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9
#define REP(i,a,b) for(ll i=a;i<=b;i++)

set<int> ans;			// Not a good idea to store into a set.. rather make an array
vi adj[6];
bool visited[6];

void dfs(int s){
	if(visited[s])
		return;
	visited[s] = true;
	ans.insert(s);

	for(auto x : adj[s]){
		dfs(x);
	}
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> a = {1, 2, 3, 4, 5};
	memset(visited, false, sizeof visited);

	adj[1].PB(3);
	adj[3].PB(1);
	adj[3].PB(4);
	adj[4].PB(3);
	adj[4].PB(1);
	adj[1].PB(4);
	adj[2].PB(5);
	adj[5].PB(2);

	// check all nodes that can be visited from a given node
	dfs(1);

	
	// Checking if all nodes are visited or not
	if(ans.size() == a.size()){
		cout << "Graph is connected\n";
	}
	else{
		cout << "Not connected\n";
	}


	return 0;
}
