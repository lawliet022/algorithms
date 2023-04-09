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

int dp[105][100005];			// dp[i][j] - min wt you can have with first i items and atmost j value

int32_t main(){
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];
	for(int i = 0; i < n; i++)
		cin >> wt[i] >> val[i];
		
	const int INF = 1e9 + 15;
	
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100000; j++)
			dp[i][j] = INF;
	
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 100000; j++){
			dp[i][j] = dp[i-1][j];
			if(j - val[i-1] >= 0){
				dp[i][j] = min(dp[i][j],dp[i-1][j-val[i-1]] + wt[i-1]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 100000; j++)
			if(dp[i][j] <= w)
				ans = max(ans,j);
	
	
	cout << ans << endl;
	
	return 0;
}

