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



	// It is a directed graph.. So only one -ve edge won't make a -ve cycle
	vector<tuple<int, int, int>> edges;
	edges.PB({2,1,3});
	edges.PB({1,3,5});
	edges.PB({3,2,2});
	edges.PB({2,4,1});
	edges.PB({4,3,-7});

	int flag = 0;
	int n = 4;
	int distance[n+1];
	for(int i = 1; i <= n; i++){
		distance[i] = MOD;
	}

	distance[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			if(i != n){
				distance[b] = min(distance[b], distance[a] + w);
			}
			else{
				if(distance[b] > distance[a]+w){
					cout<<"Negative cycle found\n";
					flag = 1;
					break;
				}
			}
		}
	}

	if(!flag){
		cout<<"No negative cycle found\n";
	}


	return 0;
}

