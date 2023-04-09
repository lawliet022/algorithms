#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int fastpower(int a, int b){
	if(b == 0){
		return 1;
	}
	int ans = fastpower(a,b/2);
	ans = ans*ans % MOD;
	if(b&1){
		ans = ans*a % MOD;
	}
	return ans;
}



int modpow(int a, int b){
	int ans = 1;
	a %= MOD;
	while(b > 0){
		if(b&1)
			ans  = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans;
}

int32_t main(){
	int a = 113, b = 10121;
	cout << fastpower(a,b) << endl;
	
	cout << modpow(a,b) << endl;
	
	return 0;
}

