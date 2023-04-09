#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;


#define MOD 10000007			 // Not usual

int modpow(int a, int b, int mod){
	int res = 1;
	a %= mod;
	while(b){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int modmul(int a, int b, int mod){
	int res = 0;
	a %= mod;
	while(b){
		if(b&1)
			res = (res+a)%mod;
		a = (a*2)%mod;
		b >>= 1;
	}
	return res;
}


int solve(int n, int k){
	int ans = modpow(n,k,MOD) + 2 * modpow(n-1,k,MOD) + modpow(n,n,MOD) + 2*modpow(n-1,n-1,MOD);
	ans %= MOD;
	if(ans < 0)
		ans += MOD;
	return ans;
}

int32_t main(){
	while(1){
		int n, k;
		cin >> n >> k;
		if(!n && !k)
			break;
		cout << solve(n,k) << "\n";
	}


	return 0;
}
