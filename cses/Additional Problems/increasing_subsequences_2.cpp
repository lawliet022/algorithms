#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

map<int,int> m;

const int MAX = 5e5;
int bit[MAX];
int N = 3e5;

void add(int index, int val){
	for(int i = index; i < N; i = i|(i+1))
		bit[i] = bit[i] + val % MOD;
}

int getSum(int x){
	int ans = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		ans = ans + bit[i] % MOD;
	}
	if(ans < 0)
		ans += MOD;
	return ans;
}

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		m[a[i]] = 1;
	}
	
	// compression
	int cnt = 1;
	for(auto &x : m){
		x.second = cnt++;
	}
	for(int i = 0; i < n; i++){
		a[i] = m[a[i]];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int p = getSum(a[i]-1);
		add(a[i],p+1);
		ans += p+1;
		ans %= MOD;
	}
	cout << ans << endl;
	
	
	
	
	
	return 0;
}
