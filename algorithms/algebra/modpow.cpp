#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ost;

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
	int c;
	cin >> c;
	cout << modpow(c,8,100000);

	return 0;
}
