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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 4;

	// when graph is unweighted and directed
	vi adj[N+1];
	adj[1].PB(2);
	adj[1].PB(3);
	adj[2].PB(4);
	adj[3].PB(4);
	adj[4].PB(1);

	// Processing all nodes that are reachable from a given node
	for(auto x : adj[1]){
		cout<<x<<"\n";
	}


	// when graph is weighted
	vp v[N+1];
	v[1].PB(MP(2,3));
	v[1].PB(MP(3,2));
	v[1].PB(MP(4,9));
	v[2].PB(MP(4,5));
	v[3].PB(MP(4,6));
	v[4].PB(MP(1,3));

	// Processing all nodes that are reachable from a given node
	for(auto x:v[1]){
		cout<<x.F<<" is at distance "<<x.S<<"\n";
	}	

	return 0;
}