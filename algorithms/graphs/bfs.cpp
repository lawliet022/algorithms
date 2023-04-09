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
vi adj[MAX];

int32_t main(){
	int n = 9;
	
	adj[1].PB(4);
	adj[1].PB(2);
	adj[2].PB(3);
	adj[4].PB(5);
	adj[3].PB(5);
	adj[3].PB(8);
	adj[3].PB(6);
	adj[5].PB(7);
	adj[5].PB(9);
	adj[6].PB(9);
	
	adj[4].PB(1);
	adj[2].PB(1);
	adj[3].PB(2);
	adj[5].PB(4);
	adj[5].PB(3);
	adj[8].PB(3);
	adj[6].PB(3);
	adj[7].PB(5);
	adj[9].PB(5);
	adj[9].PB(6);
	
	
	queue<int> q;
	bool vis[n+1];
	int dis[n+1] = {0};
	int p[n+1];
	memset(vis,false,sizeof vis);
	
	q.push(1);
	vis[1] = true;
	dis[1] = 0;
	p[1] = -1;
	
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto x : adj[cur]){
			if(!vis[x]){
				q.push(x);
				vis[x] = true;
				dis[x] = dis[cur] + 1;
				p[x] = cur;
			}
		}
	}
	
	cout << "Distance from source(1) to all other nodes are ";
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	
	// Shortest Path from 1->7
	vi path;
	for(int x = 7; x != -1; x = p[x])
		path.PB(x);
	
	reverse(path.begin(),path.end());
	
	for(auto x : path)
		cout << x << "->";
	
	

	return 0;
}
