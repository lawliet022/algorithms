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

// Given a set of coins with infinite supply find min number of coins for a given sum

const int INF = 1e9;

int dp[1000], dp2[1000];
	

int topDown(vi coins, int n){
	if(n == 0){
		return 0;
	}
	int &ans = dp[n];
	if(ans != -1)
		return ans;
	ans = INF;
	for(auto x : coins){
		if(n-x >= 0){
			ans = min(ans,topDown(coins,n-x) + 1);
		}
	}
	return ans;
}



int32_t main(){
	vector<int> coins = {8, 6, 11, 4, 1};
	int sum = 16;
		
	dp[0] = 0;
	
	for(int i = 1; i <= sum; i++){
		dp[i] = INF;
		for(auto x : coins){
			if(i-x >= 0){
				dp[i] = min(dp[i-x]+1,dp[i]);
			}
		}
	}
	cout << dp[sum] << endl;
	
	memset(dp,-1,sizeof(dp));
	
	cout << "Top Down => " << topDown(coins,sum) << endl;
	
	
	cout << "If no infinte supply\n";
	// What if no infinte supply - :) its kind of Knapsack where you need to find what all possible weights you can form from given	wts
	
	for(int i = 0; i <= sum; i++)
		dp2[i] = INF;
		
	dp2[0] = 0;
	for(int i = 0; i < (int)coins.size(); i++){
		for(int j = sum-coins[i]; j >= 0; j--)
			if(dp2[j] != INF){									// means there exists a way to form sum = j with first i-1 coins
				dp2[j+coins[i]] = min(dp2[j+coins[i]],dp2[j]+1);
			}
	}
	
	cout << dp2[sum] << endl;
	
	// Try its Top down approach.. Not able to do (for now)

	return 0;
}

