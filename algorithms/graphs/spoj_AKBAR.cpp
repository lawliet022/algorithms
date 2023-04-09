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

const int MAX = 1e6 + 10;
bool vis[MAX];
vi adj[MAX];

bool bfs(int source, int strength){
	unordered_map<int,int> a;				// Could have tried arrays but unordered_map looks better as maybe not all vertices are visited very often
	a[source]++;
	queue<pair<int,int>> q;
	q.push({source,0});
	while(!q.empty()){
		int cur = q.front().F;
		int dis = q.front().S;
		if(dis >= strength)
			break;
		
		q.pop();
		for(auto x : adj[cur]){
			if(a[x] == 0){
				q.push({x,dis+1});
				a[x]++;
			}
		}
	}
	for(auto x : a){
		if(vis[x.F]){
			return false;
		}
		else
			vis[x.F] = true;
	}
	cout << endl << endl;
	return true;
}



int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, s;
		cin >> n >> m >> s;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
		}
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		vector<pair<int,int>> v(s);
		for(auto &x : v){
			cin >> x.F >> x.S;
		}
		memset(vis,false,n+10);
		int flag = 1;
		for(int i = 0; i < (int)v.size(); i++){
			if(!bfs(v[i].F,v[i].S)){
				flag = 0;
				break;
			}
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i])
				flag = 0;
		if(!flag)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}
