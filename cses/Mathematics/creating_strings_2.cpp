#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e6 + 10;
int fac[N];

int modpow(int a, int b, int mod){
	int res = 1;
	a %= mod;
	while(b > 0){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int32_t main(){
	string s;
	cin >> s;
	int cnt[30] = {0};
	for(auto x : s){
		cnt[x-'a']++;
	}
	fac[0] = 1;
	for(int i = 1; i < N; i++){
		fac[i] = fac[i-1] * i % MOD;
	}
	int n = s.size();
	int ans = fac[n];
	for(int i = 0; i < 26; i++){
		if(cnt[i] > 1){
			ans = (ans * modpow(fac[cnt[i]],MOD-2,MOD)) % MOD;
		}
	}
	cout << ans << endl;
	
	
	return 0;
}
