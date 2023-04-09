#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

// No of derangements of n elements => f(n) = (n-1) * (f(n-1) + f(n-2))

const int N = 1e6 + 10;
int dp[N];

int solve(int n){
	if(dp[n] != -1)
		return dp[n];
	
	return dp[n] = (n-1) * (solve(n-1) +  solve(n-2) % MOD) % MOD;
}



int32_t main(){
	int n;
	cin >> n;
	
	memset(dp,-1,sizeof dp);
	
	dp[1] = 0;
	dp[2] = 1;
	
	cout << solve(n) << endl;
	
	
	
	return 0;
}
