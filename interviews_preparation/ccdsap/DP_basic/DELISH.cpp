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
		int dp1[n+1] = {0}, dp2[n+1] = {0};		// Max ending at ith position exactly
		int dp3[n+1] = {0}, dp4[n+1] = {0};		// Min ending at ith position exactly
		
		
		dp1[0] = dp3[0] = a[0];
		dp2[n-1] = dp4[n-1] = a[n-1];
		
		
		for(int i = 1; i < n; i++){
			dp1[i] = max(a[i],a[i]+dp1[i-1]);
			dp3[i] = min(a[i],a[i]+dp3[i-1]);
		}
		
		for(int i = n-2; i >= 0; i--){
			dp2[i] = max(a[i],a[i]+dp2[i+1]);
			dp4[i] = min(a[i],a[i]+dp4[i+1]);
		}
		
		// Now storing prefix max to tell what is max/min till cur index (not necessarily ending at cur index)
		for(int i = 1; i < n; i++){
			dp1[i] = max(dp1[i-1],dp1[i]);
			dp3[i] = min(dp3[i-1],dp3[i]);
		}
		
		for(int i = n-2; i >= 0; i--){
			dp2[i] = max(dp2[i+1],dp2[i]);
			dp4[i] = min(dp4[i+1],dp4[i]);
		}
		
		
		int ans = 0;
		
		for(int i = 0; i < n-1; i++){
			ans = max(ans,abs(dp1[i]-dp2[i+1]));
			ans = max(ans,abs(dp1[i]-dp4[i+1]));
			ans = max(ans,abs(dp3[i]-dp2[i+1]));
			ans = max(ans,abs(dp3[i]-dp4[i+1]));
		}
		
		cout << ans << endl;
		
	}

	return 0;
}

