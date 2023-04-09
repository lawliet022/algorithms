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

int32_t main(){
	int a[][5] =   {1, 2, 9, 1, 3,
					16, 4, 8, 9, 13,
					3, 4, 5, 9, 10,
					1, 11, 2, 16, 4,
					2, 1, 1, 2, 4
					};
					
	int dp[5][5];
	int n = 5;
	
	dp[0][0] = a[0][0];
	
	for(int i = 1; i < n; i++)
		dp[i][0] = dp[i-1][0] + a[i][0];
	
	for(int i = 1; i < n; i++)
		dp[0][i] = dp[0][i-1] + a[0][i];
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j];
		}
	}
	
	cout << dp[n-1][n-1] << endl;

	return 0;
}

