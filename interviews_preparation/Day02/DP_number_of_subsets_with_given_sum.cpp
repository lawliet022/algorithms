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
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int x;
		cin >> x;
		int dp[n+1][x+1];
		
		for(int i = 0; i <= x; i++)
			dp[0][i] = 0;
		
		for(int i = 0; i <= n; i++)
			dp[i][0] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= x; j++){
				if(j-a[i-1] >= 0)
					dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		cout << dp[n][x] << endl;
	}

	return 0;
}

