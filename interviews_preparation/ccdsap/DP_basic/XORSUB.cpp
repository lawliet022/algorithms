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
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int dp[n+1][1100];
		for(int i = 0; i <= 1024; i++)
			dp[0][i] = 0;
			
		dp[0][0] = 1;		// forming xor = 0 using no element
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= 1023; j++){
				dp[i][j] = dp[i-1][j] | dp[i-1][j^a[i-1]];
			}
		}
		int ans = 0;
		for(int i = 0; i < 1024; i++){
			if(dp[n][i]){
				ans = max(ans,k^i);
			}
		}
		cout << ans << endl;
	}
	

	return 0;
}

