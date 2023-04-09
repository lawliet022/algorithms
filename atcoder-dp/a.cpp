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
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int dp[n+1] = {0};
	
	for(int i = 1; i < n; i++){
		dp[i] = dp[i-1] + abs(a[i-1]-a[i]);
		if(i > 1)
			dp[i] = min(dp[i],dp[i-2] + abs(a[i-2]-a[i])); 
	}
	cout << dp[n-1] << endl;

	return 0;
}

