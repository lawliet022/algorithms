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

bool visited[7];
vi adj[7];


void dfs(int s){
	if(visited[s])
		return;
	visited[s]=true;
	cout<<"Visited "<<s<<"\n";

	for(auto u:adj[s]){
		dfs(u);
	}
}

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	// Graph is undirected. So a->b and b->a
	adj[1].PB(4);
	adj[4].PB(1);
	adj[1].PB(2);
	adj[2].PB(1);
	adj[2].PB(3);
	adj[3].PB(2);
	adj[2].PB(5);
	adj[5].PB(2);
	adj[3].PB(5);
	adj[5].PB(3);
	adj[4].PB(6);
	adj[6].PB(4);

	memset(visited,false,sizeof visited);
	cout<<"From 1\n";
	dfs(1);	
	memset(visited,false,sizeof visited);
	cout<<"From 2\n";
	dfs(2);
	memset(visited,false,sizeof visited);
	cout<<"From 3\n";
	dfs(3);
	memset(visited,false,sizeof visited);
	cout<<"From 4\n";
	dfs(4);
	memset(visited,false,sizeof visited);
	cout<<"From 5\n";
	dfs(5);
	memset(visited,false,sizeof visited);
	cout<<"From 6\n";
	dfs(6);


	return 0;
}