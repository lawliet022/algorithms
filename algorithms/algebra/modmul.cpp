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

int32_t main(){
	cout << modmul(3,5,4);


	return 0;
}
