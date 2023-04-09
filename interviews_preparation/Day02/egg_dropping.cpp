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
	int n, k;
	cin >> n >> k;			// No of eggs and floors resp
	
	int dp[n+1][k+1];
	
	const int INF = 1000;
	
	for(int i = 1; i <= k; i++)
		dp[1][i] = i;
	
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
		
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = INF;
			for(int x = 1; x <= j; x++){
				dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
			}
		}
	}
	//for(int i = 1; i <= n; i++){
		//for(int j = 0; j <= k; j++)
			//cout << dp[i][j] << " ";
		//cout << endl;
	//}
	cout << dp[n][k] << endl;
		
	

	return 0;
}

