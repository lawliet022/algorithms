#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int MAX = 105;


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		if(n < 3 || m < 3){
			cout << 0 << endl;
			continue;
		}
		
		int ans[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				ans[i][j] = 0;
		
		priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> q;
		bool vis[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				vis[i][j] = false;
		
		for(int i = 0; i < m; i++){
			q.push({a[0][i],{0,i}});
			vis[0][i] = true;
		}
		
		for(int i = 0; i < m; i++){
			q.push({a[n-1][i],{n-1,i}});
			vis[n-1][i] = true;
		}
		for(int i = 1; i < n-1; i++){
			q.push({a[i][0],{i,0}});
			q.push({a[i][m-1],{i,m-1}});
			vis[i][0] = true;
			vis[i][m-1] = true;
		}
		
		while(!q.empty()){
			auto p = q.top();
			q.pop();
			//cout << "Popping " << p.S.F << " " << p.S.S << " with height = " << a[p.S.F][p.S.S] << endl;
			int height = p.F;
			// Run bfs in all directions from this node
			queue<pii> q2;
			q2.push({p.S.F,p.S.S});
			while(!q2.empty()){
				auto p2 = q2.front();
				q2.pop();
				if(p2.F-1 >= 0 && !vis[p2.F-1][p2.S] && a[p2.F-1][p2.S] < height){
					vis[p2.F-1][p2.S] = true;
					ans[p2.F-1][p2.S] = height - a[p2.F-1][p2.S];
					q2.push({p2.F-1,p2.S});
				}
				if(p2.S - 1 >= 0 && !vis[p2.F][p2.S-1] && a[p2.F][p2.S-1] < height){
					vis[p2.F][p2.S-1] = true;
					ans[p2.F][p2.S-1] = height - a[p2.F][p2.S-1];
					q2.push({p2.F,p2.S-1});
				}
				if(p2.F+1 < n && !vis[p2.F+1][p2.S] && a[p2.F+1][p2.S] < height){
					vis[p2.F+1][p2.S] = true;
					ans[p2.F+1][p2.S] = height - a[p2.F+1][p2.S];
					q2.push({p2.F+1,p2.S});
				}
				if(p2.S+1 < m && !vis[p2.F][p2.S+1] && a[p2.F][p2.S+1] < height){
					vis[p2.F][p2.S+1] = true;
					ans[p2.F][p2.S+1] = height - a[p2.F][p2.S+1];
					q2.push({p2.F,p2.S+1});
				}
				
				// Adding to heap
				
				if(p2.F-1 >= 0 && !vis[p2.F-1][p2.S] && a[p2.F-1][p2.S] >= height){
					vis[p2.F-1][p2.S] = true;
					q.push({a[p2.F-1][p2.S],{p2.F-1,p2.S}});
				}
				if(p2.S - 1 >= 0 && !vis[p2.F][p2.S-1] && a[p2.F][p2.S-1] >= height){
					vis[p2.F][p2.S-1] = true;
					q.push({a[p2.F][p2.S-1],{p2.F,p2.S-1}});
				}
				if(p2.F+1 < n && !vis[p2.F+1][p2.S] && a[p2.F+1][p2.S] >= height){
					vis[p2.F+1][p2.S] = true;
					q.push({a[p2.F+1][p2.S],{p2.F+1,p2.S}});
				}
				if(p2.S+1 < m && !vis[p2.F][p2.S+1] && a[p2.F][p2.S+1] >= height){
					vis[p2.F][p2.S+1] = true;
					q.push({a[p2.F][p2.S+1],{p2.F,p2.S+1}});
				}
			}
		}
		int res = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				res += ans[i][j];
		cout << res << endl;
	}

	return 0;
}

