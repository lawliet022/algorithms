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
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		int n = a.size(), m = b.size();
		int dp[n+1][m+1];
		for(int i = 0; i <= m; i++)		// 1st string is empty
			dp[0][i] = 	0;
		
		for(int i = 0; i <= n; i++)		// 2nd string is empty
			dp[i][0] = 	1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		cout << dp[n][m] << endl;
		
			
	}

	return 0;
}

