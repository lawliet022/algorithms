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

// Given a set of Items each with a value and weight. Find 

int solve(int val[], int wt[], int W, int n){
	if(n == 0 || W == 0){
		return 0;
	}
	int ans = 0;
	if(wt[n-1] <= W){
		ans = val[n-1] + solve(val,wt,W-wt[n-1],n-1);
	}
	ans = max(ans,solve(val,wt,W,n-1));
	return ans;
}


int32_t main(){
	//int val[] = {8, 4, 0, 5, 3}, wt[] = {1, 2, 3, 2, 2};
	//int W = 4;
	
	//int n = 5;
	
	//cout << solve(val,wt,W,n) << endl;			// Recursive - (Exponential Solution)
	
	
	
	// DP Solution
	int W, n;
	cin >> W >> n;
	
	int val[n], wt[n];
	for(int i = 0; i < n; i++)
		cin >> wt[i] >> val[i]; 
	
	int dp[n+1][W+1];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][W] << endl;
	

	return 0;
}

