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

// Assuming there are some blocked cells (Represented by 0)

int32_t main(){
	int a[][5] = {1, 1, 1, 0, 1,
				  1, 1, 1, 0, 1,
				  0, 1, 0, 0, 1,
				  1, 1, 1, 0, 1,
				  1, 1, 1, 1, 1
				};
				
	int dp[5][5] = {0};
	int n = 5;
	
	dp[0][0] = a[0][0];
	
	for(int i = 1; i < n; i++)
		dp[i][0] = (a[i][0] ? dp[i-1][0] : 0);
	
	for(int i = 1; i < n; i++)
		dp[0][i] = (a[0][i] ? dp[0][i-1] : 0);
		
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			if(a[i][j])
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			else
				dp[i][j] = 0;
		}
	}
	
	cout << dp[n-1][n-1] << endl;

	return 0;
}

