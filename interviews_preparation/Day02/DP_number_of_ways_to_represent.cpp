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

// No of ways to write a number as sum of given numbers

// Ex as sum of 1, 3, 4

int32_t main(){
	int n = 50;
	int dp[n+5];
	dp[0] = dp[1] = dp[2] = 1;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1];
		if(i-3 >= 0)
			dp[i] += dp[i-3];
		if(i-4 >= 0)
			dp[i] += dp[i-4];
	}
	
	cout << dp[n] << endl;
	
	// For large numbers like 1e12

	return 0;
}

