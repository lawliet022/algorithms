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

const int MAX = 15 * 1e6 + 10;

int v[MAX];


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, b;
		cin >> n >> k >> b;
		
		int dis[n+1];
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			dis[i] = y;
			v[y] += x;
		}
		sort(dis,dis+n);
		int dp[1005][k+2][5];
		
		// 1 - Up
		// 2 - Down
		// 3 - Seperate Up and Down
		// 4 - Combined Up and Down
		
		const int INF = 1e9;
		
		dp[0][1][1] = (v[dis[0]] == 1 ? 1 : INF);
		dp[0][1][2] = (v[dis[0]] == 2 ? 1 : INF);
		dp[0][1][3] = INF;
		dp[0][2][3] = (v[dis[0]] == 3 ? 2 : INF);
		dp[0][1][4] = (v[dis[0]] == 3 ? 2 : INF);
		
		for(int i = 0; i <= 1000; i++){
			for(int k = 0; k < 5; k++){
				dp[i][0][k] = INF;
			}
		} 
		
		
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= k; j++){
				// 1
				if(v[dis[i]] != 1){
					dp[i][j][1] = INF;
				}
				else{
					int mini = 1e9;
					for(int x = 1; x < 5; x++)
						mini = min(mini,dp[i-1][j-1][x]);
						
					dp[i][j][1] = min(1 + mini, dis[i] - dis[i-1] + min(dp[i-1][j][1],dp[i-1][j][3]));
					
				}
				
				// 2
				if(v[dis[i]] != 2){
					dp[i][j][2] = INF;
				}
				else{
					int mini = 1e9;
					for(int x = 1; x < 5; x++)
						mini = min(mini,dp[i-1][j-1][x]);
						
					dp[i][j][1] = min(1 + mini, dis[i] - dis[i-1] + min(dp[i-1][j][2],dp[i-1][j][3]));
					
				}
				
				// 3
				if(v[dis[i]] != 3){
					dp[i][j][3] = INF;
				}
				else{
					int mini = 1e9;
					for(int x = 1; x < 5; x++)
						mini = min(mini,dp[i-1][j-1][x]);
					
					dp[i][j][1] = min(2 + mini, dis[i] - dis[i-1] + min(dp[i-1][j][2],dp[i-1][j][3]));
					
				}
				
				
				
				
			}
		}
		
		
	}

	return 0;
}

