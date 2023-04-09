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

#define n 5

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pi> adj[n+1];
	adj[1].PB({2,5});
	adj[1].PB({4,9});
	adj[1].PB({5,1});
	adj[2].PB({1,5});
	adj[2].PB({3,2});
	adj[3].PB({2,2});
	adj[3].PB({4,6});
	adj[4].PB({3,6});
	adj[4].PB({1,9});
	adj[4].PB({5,2});
	adj[5].PB({4,2});
	adj[5].PB({1,1});

	int distance[n+1];
	for(int i = 1; i <= n; i++)
		distance[i] = MOD;
	
	distance[1] = 0;
	int	processed[n+1];
	memset(processed, false, sizeof(processed));
	
	priority_queue<pi> q;
	q.push({0,1});

	while(!q.empty()){
		int t = q.top().S;
		q.pop();
		if(processed[t])
			continue;
		processed[t]=true;
		for(auto x : adj[t]){
			int a = x.F;
			int w = x.S;
			if(distance[a] > distance[t] + w){
				distance[a] = distance[t] + w;
				q.push({-distance[a],a});
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << distance[i] <<"\n";
	}
	

	return 0;
}