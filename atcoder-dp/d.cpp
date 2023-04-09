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

int dp[105][100005];

int32_t main(){
	int n, w;
	cin >> n >> w;
	
	int wt[n], val[n];
	for(int i = 0; i < n; i++)
		cin >> wt[i] >> val[i];
	
	// bottom up
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= wt[i-1]){
				dp[i][j] = max(dp[i][j],dp[i-1][j-wt[i-1]] + val[i-1]);
			}
		}
	}
	
	cout << dp[n][w] << endl;

	return 0;
}

