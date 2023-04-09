#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


// refer page 209 scenario-2 CP-Handbook
// ways to distribute m objects to n boxes = arranging (n-1) ->'s and m 0's

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
const int N = 2e6 + 10;
int fac[N], invF[N];


int32_t main(){
	int n, m;
	cin >> n >> m;
	
	fac[0] = 1;
	for(int i = 1; i < N; i++){
		fac[i] = (fac[i-1] * i) % MOD;
	}
	invF[N-1] = modpow(fac[N-1],MOD-2,MOD);
	for(int i = N-2; i >= 0; i--){
		invF[i] = invF[i+1] * (i+1) % MOD;
	}
	
	cout << (fac[n+m-1] * invF[n-1] % MOD) * invF[n+m-1-(n-1)] % MOD << endl;

	
	
	return 0;
}
