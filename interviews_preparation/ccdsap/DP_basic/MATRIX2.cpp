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
	vector<string> s(n);
	for(auto &x : s)
		cin >> x;
	
	int dp[n+1][m+1] = {0};
	
	// DP on bottom right corner using DP(i-1,j-1) and DP(i-1,j) states
	//for(int i = 0; i < n; i++){
		//for(int j = 0; j < m; j++){
			//if(i == 0 || j == 0){
				//dp[i][j] = (s[i][j] == '1');
			//}
			//else{
				//dp[i][j] = (s[i][j] == '1') + (s[i][j] == '1')*min(dp[i-1][j-1],dp[i-1][j]);	// No of other triangles ending at this pos (bottom right)
			//}
		//}
	//}
	
	
	// OR
	// DP on top right corner using DP(i,j-1) and number of consecutive 1's below (i,j)
	int c[n+1][m+1];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j] = c[i][j] =  0;
	
	for(int i = n-2; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(s[i+1][j] == '1')
				c[i][j] = c[i+1][j] + 1;
			else
				c[i][j] = 0;
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i-1][j-1] == '0')
				continue;
			else{
				dp[i][j] = min(dp[i][j-1]+1,1+c[i-1][j-1]);
			}
		}
	}
	
	
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += dp[i][j];
	
	cout << ans << endl;

	return 0;
}

