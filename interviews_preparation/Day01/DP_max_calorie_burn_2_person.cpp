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

// https://codeforces.com/contest/429/problem/B

int32_t main(){
	int a[][5] = {12, 15, 11, 17, 2,
				9, 17, 21, 25, 6,
				7, 30, 35, 9, 9,
				5, 15, 2, 7, 9,
				2, 15, 15, 10, 5
				};
				
	int n = 5;
	int dp1[n+2][n+2], dp2[n+2][n+2], dp3[n+2][n+2], dp4[n+2][n+2];
	
	for(int i = 0; i <= n+1; i++)
		for(int j = 0; j <= n+1; j++)
			dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 0;
	
	// Top left
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + a[i-1][j-1];
		}
	}
	
	// Bottom Left
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			dp2[i][j] = max(dp2[i+1][j], dp2[i][j-1]) + a[i-1][j-1];
		}
	}
	
	// Bottom Right
	for(int i = n; i >= 1; i--){
		for(int j = n; j >= 1; j--){
			dp3[i][j] = max(dp3[i+1][j], dp2[i][j+1]) + a[i-1][j-1];
		}
	}
	
	// Top Right
	for(int i = 1; i <= n; i++){
		for(int j = n; j >= 1; j--){
			dp4[i][j] = max(dp4[i+1][j], dp4[i][j-1]) + a[i-1][j-1];
		}
	}
	
	int ans = 0;
	
	for(int i = 2; i < n; i++){
		for(int j = 2; j < n; j++){
			ans = max(ans, dp1[i-1][j] + dp2[i][j-1] + dp3[i+1][j] + dp4[i][j+1]);
			ans = max(ans, dp1[i][j-1] + dp2[i+1][j] + dp3[i][j+1] + dp4[i-1][j]);
			//cout << "at ij = " << i-1 << " " << j-1 << " => " << dp1[i-1][j] + dp2[i][j-1] + dp3[i+1][j] + dp4[i][j+1] << endl; 
		}
	}
	cout << ans << endl;
	
	

	return 0;
}

