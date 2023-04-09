#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

int modpow(int a, int n, int mod){
	int res = 1;
	a %= mod;
	while(n > 0){
		if(n % 2){
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, n;
		cin >> a >> n;
		cout << modpow(a,n,MOD) << endl;
	}
	
	return 0;
}
