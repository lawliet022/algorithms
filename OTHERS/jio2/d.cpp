#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, l;
		cin >> n >> l;
		int dp[n+2] = {0};
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = i-1; j >= max(1LL,i-l+1); j -= 2){
				dp[i] = (dp[i] + dp[j-1]) % MOD;
			}
		}
		cout << dp[n] << endl;
	}
	
	return 0;
}
