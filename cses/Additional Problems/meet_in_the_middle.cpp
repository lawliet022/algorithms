#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

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


int32_t main(){
	int n, target;
	cin >> n >> target;
	int a[n];
	for(int i = 0;i < n; i++)
		cin >> a[i];
	
	if(n <= 20){
		int ans = 0;
		for(int i = 0; i < (1<<n); i++){
			int cur = 0;
			for(int j = 0; j < n; j++){
				if(i&(1<<j)){
					cur += a[j];
				}
			}
			if(cur == target)
				ans++;
		}
		cout << ans << endl;
		return 0;
	}
	int p = n / 2;
	unordered_map<int,int,custom_hash> m;
	for(int i = 0; i < (1<<p); i++){
		int cur = 0;
		for(int j = 0; j < p; j++){
			if(i&(1<<j)){
				cur += a[j];
			}
		}
		m[cur]++;
	}
	
	vector<int> v;
	for(int i = p; i < n; i++){
		v.push_back(a[i]);
	}
	p = v.size();
	int ans = 0;
	for(int i = 0; i < (1<<p); i++){
		int cur = 0;
		for(int j = 0; j < p; j++){
			if(i&(1<<j)){
				cur += v[j];
			}
		}
		if(m.count(target-cur)){
			ans += m[target-cur];
		}
	}
	cout << ans << endl;
	
	
	
	return 0;
}
