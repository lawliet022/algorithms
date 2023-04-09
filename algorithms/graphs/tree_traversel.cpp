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

#define n 8

vi adj[n+1];

void dfs(int s,int parent){
	cout<<"Visited "<<s<<"\n";
	
	for(auto u:adj[s]){
		if(u!=parent)
			dfs(u,s);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	adj[1].PB(2);
	adj[1].PB(3);
	adj[1].PB(4);
	adj[2].PB(1);
	adj[2].PB(5);
	adj[2].PB(6);
	adj[3].PB(1);
	adj[4].PB(1);
	adj[4].PB(7);
	adj[5].PB(2);
	adj[6].PB(2);
	adj[6].PB(8);
	adj[7].PB(4);
	adj[8].PB(6);

	// passing root with parent as 0
	dfs(1,0);

	return 0;
}