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
	


pair<int,int> fibo(int n, int mod){
	if(n == 0){
		return {0,1};
	}
	auto p = fibo(n/2,mod);
	int c = p.F*(2*p.S-p.F);
	int d = p.F*p.F + p.S*p.S;
	c %= mod;
	d %= mod;
	if(n&1){
		int x = d % mod;
		int y = (c + d) % mod;
		if(x < 0)
			x += mod;
		if(y < 0)
			y += mod;
		return {x,y};
	}
	else{
		int x = c % mod;
		int y = d % mod;
		if(x < 0)
			x += mod;
		if(y < 0)
			y += mod;
		return {x,y};
	}
}

int32_t main(){
	int n, m;
	while(cin >> n >> m){
		int mod = 1;
		for(int i = 0; i < m; i++)
			mod *= 2;
		cout << fibo(n,mod).F << "\n";
	}


	return 0;
}
