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
	int n, m;
	cin >> n >> m;
	
	char grid[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	int dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1){
				dp[i][j] = 1;
			}
			else{
				if(grid[i-1][j-1] != '#'){
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	
	return 0;
}

