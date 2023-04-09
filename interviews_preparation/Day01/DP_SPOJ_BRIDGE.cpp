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
		vector<pair<int,int>> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i].F;
		for(int i = 0; i < n; i++)
			cin >> v[i].S;
		
		sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
			if(a.F != b.F)
				return a.F < b.F;
			return a.S < b.S;
		});
		
		
		int dp[n+1] = {0};
		dp[0] = 1;
		for(int i = 1; i < n; i++){
			dp[i] = 1;
			for(int j = 0; j < i; j++){
				if(v[i].F >= v[j].F && v[i].S >= v[j].S){
					dp[i] = max(dp[i],dp[j]+1);
				}
			}
		}
		int ans = 1;
		for(int i = 0; i < n; i++)
			ans = max(ans,dp[i]);
		cout << ans << endl;
	}
	

	return 0;
}

