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

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);


	// To apply bellman ford in undirected graph there shouldn't be any negative edge.. 
	// as it will form a negative cycle beacaue in a undirected graph both a->b and b->a exists..
	
	vector<tuple<int, int, int>> edges;
	edges.PB({1,2,2});
	edges.PB({2,1,2});
	edges.PB({1,3,3});
	edges.PB({3,1,3});
	edges.PB({3,4,2});
	edges.PB({4,3,2});
	edges.PB({1,4,7});
	edges.PB({4,1,7});
	edges.PB({2,4,3});
	edges.PB({4,2,3});
	edges.PB({2,5,5});
	edges.PB({5,2,5});
	edges.PB({4,5,2});
	edges.PB({5,4,2});
	
	int n = 5;
	int distance[n+1];
	for(int i = 1; i <= n; i++){
		distance[i] = MOD;
	}

	distance[1] = 0;
	for (int i = 1; i <= n-1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}

	for(int i = 1;i < 6;i++){
		cout << distance[i] <<"\n";
	}

	return 0;
}
