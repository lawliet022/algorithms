#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n <= 4){
			cout << n << "\n";
			continue;
		}
		int ans;
		if(n % 3 == 0)
			ans = modpow(3,n/3,MOD);
		else if((n-2) % 3 == 0)
			ans = 2 * modpow(3,(n-2)/3,MOD);
		else if((n-4) % 3 == 0)
			ans = 4 * modpow(3,(n-4)/3,MOD);
		
		ans %= MOD;
		if(ans < 0)
			ans += MOD;
		cout << ans << "\n";
	}


	return 0;
}
