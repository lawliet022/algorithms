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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int dp[n+1];
		dp[0] = 0;
		dp[1] = 1;
		for(int i = 2; i <= n; i++){
			dp[i] = min(dp[i-1],((i&1) ? dp[i/2] + 1 : dp[i/2]) )+1;
		}
		cout << dp[n] << endl;
	}


	return 0;
}
