#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int solve(vi coin, int idx,int n){
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	if(idx == 0 && n != 0)
		return 0;
	return solve(coin, idx-1, n) + solve(coin, idx, n - coin[idx-1]);
}



int32_t main(){
	vi coin = {1,2,3};
	int n = 4;
	
	cout << solve(coin,coin.size(),n);		// Exponential Solution

	// DP solution
	
	int dp[n+1] = {0};
	dp[0] = 1;
	
	for(int i = 0; i < (int)coin.size(); i++){
		for(int j = coin[i]; j <= n; j++)
			dp[j] += dp[j-coin[i]];
	}
	
	cout << dp[n] << endl;
	
	return 0;
}

