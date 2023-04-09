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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

const int INF = 1e6;


bool istrue(vector<pii> adj[], int n, pair<pii,int> p){
	priority_queue<pii> q;
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	
	int dis[n+1];
	for(int i = 1; i <= n; i++)
		dis[i] = 1e9;
	
	int source = p.F.F;
	int dest = p.F.S;
	int target = p.S;
	dis[source] = 0;
	
	q.push({source,0});
	
	while(!q.empty()){
		int t = q.top().F;
		q.pop();
		if(vis[t])
			continue;
		vis[t] = true;
		for(auto x : adj[t]){
			if(x.F == t)
				continue;
			int a = x.F;
			int w = x.S;
			if(dis[a] > dis[t] + w){
				dis[a] = dis[t] + w;
				q.push({a,-dis[a]});
			}
		}
	}
	if(dis[dest] != target)
		return 0;
	return 1;
		
}

int32_t main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int n, m;
		cin >> n >> m;
		vector<pii> adj[n+1];
		vector<pair<pii,int>> v;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j)
					adj[i].PB({j,0});
				else
					adj[i].PB({j,INF});
			}
		}
		for(int i = 0; i < m; i++){
			int x, y, wt;
			cin >> x >> y >> wt;
			v.PB({{x,y},wt});
			adj[x][y-1] = {y,wt};
			adj[y][x-1] = {x,wt};
		}
		
		
		int flag = 1;
		for(auto x : v){
			if(!istrue(adj,n,x)){
				flag = 0;
				break;
			}
		}
		if(!flag){
			cout << "Case #" << test << ": Impossible\n";
		}
		else{
			cout << "Case #" << test << ": " << n*(n-1)/2 << endl; 
			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++)
					cout << i << " " << j << " " << adj[i][j-1].S << endl;
			}
		}
	}
	//cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 

	return 0;
}

