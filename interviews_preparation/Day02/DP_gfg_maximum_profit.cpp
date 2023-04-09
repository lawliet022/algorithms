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

// https://practice.geeksforgeeks.org/problems/maximum-profit/0

//In stock market , a person buys a stock and sells it on some future date. Given the stock prices of N days in an form of an array A[ ] 
//and a positive integer K, find out the maximum profit a person can make in atmost K transactions. A transaction is equivalent to 
//(buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.


int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> k >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n+1][k+1];		// Stores max profit till nth day with atmost k transactions
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int i = 0; i <= k; i++)
            dp[0][i] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i-1][j];
                for(int l = 1; l < i; l++){
                    dp[i][j] = max(dp[i][j], a[i-1]-a[l-1] + dp[l-1][j-1]);
                }
            }
        }
        //for(int i = 1; i <= n; i++){
			//for(int j = 1; j <= k; j++)
				//cout << dp[i][j] << " ";
			//cout << endl;
		//}
        int ans = 0;
        for(int i = 1; i <= k; i++)
            ans = max(ans,dp[n][i]);
        
        cout << ans << endl;
    }


	return 0;
}
