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
vector<pair<int,int>> adj[MAX];

int32_t main(){
	int n = 9;
	
	adj[1].PB({4,1});
	adj[1].PB({2,1});
	adj[2].PB({3,1});
	adj[4].PB({5,1});
	adj[3].PB({5,1});
	adj[3].PB({8,1});
	adj[3].PB({6,0});
	adj[5].PB({7,1});
	adj[5].PB({9,1});
	adj[6].PB({9,0});
	
	adj[4].PB({1,1});
	adj[2].PB({1,1});
	adj[3].PB({2,1});
	adj[5].PB({4,1});
	adj[5].PB({3,1});
	adj[8].PB({3,1});
	adj[6].PB({3,0});
	adj[7].PB({5,1});
	adj[9].PB({5,1});
	adj[9].PB({6,0});
	
	
	deque<int> q;
	int dis[n+1] = {0};
	int p[n+1];
	
	for(int i = 1; i <= n; i++)
		dis[i] = 1e9;
	
	q.push_back(1);
	dis[1] = 0;
	p[1] = -1;
	
	while(q.size()){
		int cur = q.front();
		q.pop_front();
		for(auto x : adj[cur]){
			if(dis[x.F] > dis[cur] + x.S){
				if(x.S == 0)
					q.push_front(x.F);
				else
					q.push_back(x.F);
				dis[x.F] = dis[cur] + x.S;
				p[x.F] = cur;
			}
		}
	}
	
	cout << "Distance from source(1) to all other nodes are ";
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	
	// Shortest Path from 1->9
	vi path;
	for(int x = 9; x != -1; x = p[x])
		path.PB(x);
	
	reverse(path.begin(),path.end());
	
	for(auto x : path)
		cout << x << "->";
	
	

	return 0;
}
