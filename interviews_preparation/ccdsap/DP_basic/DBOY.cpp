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
		int dis[n], fuel[n];
		for(int i = 0; i < n; i++)
			cin >> dis[i];
		for(int i = 0; i < n; i++)
			cin >> fuel[i];
		
		int dp[1005] = {0};
		dp[0] = 0;
		const int INF = 1e9;
		
		for(int i = 1; i <= 1002; i++){
			dp[i] = INF;
			for(int j = 0; j < n; j++){
				if(i-fuel[j] >= 0){
					dp[i] = min(dp[i],dp[i-fuel[j]]+1);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += dp[2*dis[i]];
			
		cout << ans << endl;
		
	}

	return 0;
}

