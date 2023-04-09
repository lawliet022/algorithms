#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


const int N = 1e6 + 100;
int fac[N], invF[N];

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
	int t;
	cin >> t;
	const int M = 1e6;
	fac[0] = 1;
	for(int i = 1; i <= M; i++){
		fac[i] = (fac[i-1] * i) % MOD;
	}
	invF[M] = modpow(fac[M],MOD-2,MOD);
	for(int i = M-1; i >= 0; i--){
		invF[i] = invF[i+1] * (i+1) % MOD;
	}
	while(t--){
		int n, r;
		cin >> n >> r;
		
		cout << (fac[n] * invF[n-r] % MOD) * invF[r] % MOD << endl;
	}
	
	return 0;
}
