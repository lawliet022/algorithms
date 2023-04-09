#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


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
	int n;
	cin >> n;
	cout << modpow(2,n,MOD);
	
	return 0;
}
