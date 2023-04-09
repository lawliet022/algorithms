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
	int dis[n+1] = {0}, dis2[n+1] = {0};
	memset(vis,false,sizeof vis);
	
	// Bfs from 1
	q.push(1);
	vis[1] = true;
	dis[1] = 0;
	
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto x : adj[cur]){
			if(!vis[x]){
				q.push(x);
				vis[x] = true;
				dis[x] = dis[cur] + 1;
			}
		}
	}
	
	
	// Bfs from 9
	memset(vis,false,sizeof vis);
	q.push(9);
	vis[9] = true;
	dis2[9] = 0;
	
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto x : adj[cur]){
			if(!vis[x]){
				q.push(x);
				vis[x] = true;
				dis2[x] = dis2[cur] + 1;
			}
		}
	}
	
	
	cout << "Distance from source(1) to all other nodes are ";
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	
	cout << "Distance from source(9) to all other nodes are ";
	for(int i = 1; i <= n; i++){
		cout << dis2[i] << " ";
	}
	cout << endl;
	
	
	cout << "All vertices in between the shortest path from 1 to 9 are - ";
	for(int i = 1; i <= n; i++){
		if(dis[i]+dis2[i] == dis[9]){
			cout << i << " ";
		}
	}
	
	cout << "\nAll edges in between the shortest path from 1 to 9 are - ";
	int v = 9;
	for(int i = 1; i <= n; i++){
		for(auto x : adj[i]){
			if(dis[i]+dis2[x]+1 == dis[v]){
				cout << "(" << i << ", " << x << ")\t";
			}
		}
	}
	
	
	
	
	
	

	return 0;
}
