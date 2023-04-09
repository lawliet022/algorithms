#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int MAX = 2e5;
int parent[MAX], cnt[MAX];

void make(int n){
	parent[n] = n;
	cnt[n] = 1;
}

int find(int n){
	if(n == parent[n])
		return n;
	return parent[n] = find(parent[n]);			// Path Compression
}

void unionset(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(cnt[a] < cnt[b])
			swap(a,b);
		parent[b] = a;
			cnt[a] += cnt[b];
	}
}

int dp[MAX], temp[MAX];

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<int,int,custom_hash> ma;



int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		make(i);
	}
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		unionset(x,y);
	}
	vector<int> v;
	for(int i = 1; i <= n; i++){
		if(i == find(i)){
			v.push_back(cnt[i]);
		}
	}
	for(auto x : v){
		ma[x]++;
	}
	
	dp[0] = 1;
	for(auto x : ma){
		memset(temp,0,sizeof temp);
		for(int i = 0; i < n; i++){
			if(dp[i] == 0)
				continue;
			for(int j = 1; j <= x.second; j++){
				if(i + x.first * j > n)
					break;
				temp[i+x.first*j] = 1;
			}
		}
		for(int j = 1; j <= n; j++){
			dp[j] |= temp[j];
		}
	}
	for(int i = 1; i <= n; i++)
		cout << dp[i];
	
	
	return 0;
}
