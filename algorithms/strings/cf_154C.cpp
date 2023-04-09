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

const int MAX = 1e6+5;

vi adj[MAX];

int32_t main(){
	ios::sync_with_stdio(0);		// Important when input is order of 1e6
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	
	// ------------- Not friend -----------------------
	for(int i = 0; i <= n; i++){
		sort(adj[i].begin(),adj[i].end());
	}
	vector<int> hash1(n+1,0), hash2(n+1,0);
	vi pa(n+1), pa2(n+1);
	pa[0] = 1;	pa2[0] = 1;
	
	for(int i = 1; i <= n; i++){
		pa[i] = (pa[i-1]*31)%MOD;
		pa2[i] = (pa2[i-1]*53)%MOD;
	}
	vector<pii> v;
	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 0)
			continue;
		for(auto x : adj[i]){
			hash1[i] = hash1[i] + pa[x];
			hash2[i] = hash2[i] + pa2[x];
			hash1[i] %= MOD;
			hash2[i] %= MOD;
		}
		if(hash1[i] < 0)	hash1[i] += MOD;
		if(hash2[i] < 0)	hash2[i] += MOD;
		v.PB({hash1[i],hash2[i]});
	}
	int ans = 0;
	sort(v.begin(),v.end());
	int temp = 1;
	for(int i = 1; i < (int)v.size(); i++){
		if(v[i] != v[i-1]){
			ans += (temp*(temp-1))/2;
			temp = 1;
		}
		else{
			temp++;
		}
	}
	if(v.size() >= 2 && v.back() == v[v.size()-2]){
		ans += temp*(temp-1)/2;
	}
	
	// ---------------- Friend ----------------
	
	
	for(int i = 0; i <= n; i++){
		adj[i].PB(i);
		sort(adj[i].begin(),adj[i].end());
	}
	fill(hash1.begin(),hash1.end(),0);
	fill(hash2.begin(),hash2.end(),0);
	
	
	v.clear();
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 1){
			count++;
			continue;
		}
		for(auto x : adj[i]){
			hash1[i] = hash1[i] + pa[x];
			hash2[i] = hash2[i] + pa2[x];
			hash1[i] %= MOD;
			hash2[i] %= MOD;
		}
		if(hash1[i] < 0)	hash1[i] += MOD;
		if(hash2[i] < 0)	hash2[i] += MOD;
		v.PB({hash1[i],hash2[i]});
	}
	sort(v.begin(),v.end());
	temp = 1;
	for(int i = 1; i < (int)v.size(); i++){
		if(v[i] != v[i-1]){
			ans += (temp*(temp-1))/2;
			temp = 1;
		}
		else{
			temp++;
		}
	}
	if(v.size() >= 2 && v.back() == v[v.size()-2]){
		ans += temp*(temp-1)/2;
	}
	ans += count*(count-1)/2;
	
	cout << ans;

	return 0;
}
