#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n+1], b[n+1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		int dp[n+2] = {0};
		for(int i = 1; i <= n; i++){
			dp[i] = 1;
			for(int j = i-1; j >= 1; j--){
				if(a[i] > a[j] && b[i] < b[j]){
					dp[i] = max(dp[i],dp[j] + 1);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans,dp[i]);
		cout << ans << endl;
	}
	
	return 0;
}
